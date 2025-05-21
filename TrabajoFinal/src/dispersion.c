#include "../include/dispersion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Lee el contenido del fichero hash organizado mediante el método de DISPERSIÓN según los criterios
// especificados en la práctica. Se leen todos los cubos completos tengan registros asignados o no. La
// salida que produce esta función permite visualizar el método de DISPERSIÓN
int leeHash(char *fichHash)
{
   FILE *f;
   tipoCubo cubo;
   regConfig regC;
   int j, nCubo = 0, densidadOcupacion;

   if ((f = fopen(fichHash, "rb")) == NULL)
      return -2;
   fread(&regC, sizeof(regConfig), 1, f);
   fread(&cubo, sizeof(cubo), 1, f);
   while (!feof(f))
   {
      for (j = 0; j < C; j++)
      {
         if (j == 0)
            printf("Cubo %2d (%2d reg. ASIGNADOS)", nCubo, cubo.numRegAsignados);
         else if ((j == 1) && cubo.desbordado)
            printf("DESBORDADO\t\t");
         else
            printf("\t\t\t");
         if (j < cubo.numRegAsignados)
            mostrarReg(&(cubo.reg[j]));
         else
            printf("\n");
      }
      nCubo++;
      fread(&cubo, sizeof(cubo), 1, f);
   }
   fclose(f);
   printf("ORGANIZACIÓN MÉTODO DISPERSIÓN:\n\t %d CUBOS y %d CUBOS DESBORDE con capacidad %d\n",
          regC.nCubos, regC.nCubosDes, C);
   printf("Cubo de Desborde Actual: %d\n", regC.nCuboDesAct);

   printf("\t Contiene %d registros de los cuales se han desbordado %d:\n", regC.numReg, regC.numRegDes);

   densidadOcupacion = 100 * regC.numReg / ((regC.nCubos + regC.nCubosDes) * C);
   printf("Densidad ACTUAL de ocupación: %d \n\t(MÍNIMA permitida %f  MÁXIMA permitida %f)\n",
          densidadOcupacion, regC.densidadMin, regC.densidadMax);

   if (densidadOcupacion > regC.densidadMax)
   {
      printf("No se respeta la densidad máxima de ocupacion\n");
   }

   if (densidadOcupacion < regC.densidadMin)
   {
      printf("No se respeta la densidad mínima de ocupacion\n");
   }
   return 0;
}

int creaHvacio(char *fichHash, regConfig *reg)
{
   FILE *fHash;
   tipoCubo cubo;
   int totalCubos, i;

   reg->numReg = 0;
   reg->numRegDes = 0;
   reg->nCuboDesAct = reg->nCubos;

   fHash = fopen(fichHash, "wb");
   if (fHash == NULL)
   {
      return -2;
   }
   fwrite(reg, sizeof(regConfig), 1, fHash);
   memset(&cubo, 0, sizeof(cubo));
   totalCubos = reg->nCubos + reg->nCubosDes;
   for (i = 0; i < totalCubos; i++)
   {
      fwrite(&cubo, sizeof(tipoCubo), 1, fHash);
   }
   fclose(fHash);
   return 0;
}

int desborde(FILE *fHash, tipoReg *reg, regConfig *regC)
{
   tipoCubo cubo;
   int pos = regC->nCuboDesAct;
   int totalCubos = regC->nCubos + regC->nCubosDes;

   if (!fHash)
      return -2;

   while (pos < totalCubos)
   {
      fseek(fHash, sizeof(regConfig) + pos * sizeof(tipoCubo), SEEK_SET);
      fread(&cubo, sizeof(tipoCubo), 1, fHash);

      if (cubo.numRegAsignados < C)
      {
         cubo.reg[cubo.numRegAsignados] = *reg;
         cubo.numRegAsignados++;

         fseek(fHash, -sizeof(tipoCubo), SEEK_CUR);
         fwrite(&cubo, sizeof(tipoCubo), 1, fHash);

         if (cubo.numRegAsignados == C)
         {
            regC->nCuboDesAct = pos + 1;
         }

         return 0;
      }

      pos++;
   }

   memset(&cubo, 0, sizeof(tipoCubo));
   cubo.reg[0] = *reg;
   cubo.numRegAsignados = 1;

   fseek(fHash, sizeof(regConfig) + totalCubos * sizeof(tipoCubo), SEEK_SET);
   fwrite(&cubo, sizeof(tipoCubo), 1, fHash);

   regC->nCubosDes++;
   regC->nCuboDesAct = regC->nCubos + regC->nCubosDes;

   return 0;
}

int insertar(FILE *f, tipoReg *reg, regConfig *regC)
{
   int posHash = funcionHash(reg, regC->nCubos);
   tipoCubo cubo;
   if (!f)
      return -2;

   fseek(f, sizeof(regConfig) + posHash * sizeof(tipoCubo), SEEK_SET);
   fread(&cubo, sizeof(tipoCubo), 1, f);
   if (cubo.numRegAsignados < C)
   {
      cubo.reg[cubo.numRegAsignados] = *reg;
      cubo.numRegAsignados++;

      fseek(f, -sizeof(tipoCubo), SEEK_CUR);
      fwrite(&cubo, sizeof(tipoCubo), 1, f);

      regC->numReg++;
      return 0;
   }
   else
   {
      cubo.desbordado = 1;
      fseek(f, -sizeof(tipoCubo), SEEK_CUR);
      fwrite(&cubo, sizeof(tipoCubo), 1, f);

      int res = desborde(f, reg, regC);
      if (res == 0)
      {
         regC->numReg++;
         regC->numRegDes++;
      }
      return res;
   }
}

int creaHash(char *fichEntrada, char *fichHash, regConfig *regC)
{
   FILE *fEntrada = NULL, *fSalida = NULL;
   tipoReg reg;

   if (creaHvacio(fichHash, regC) != 0)
      return -2;

   fEntrada = fopen(fichEntrada, "rb");
   if (!fEntrada)
      return -1;
   fSalida = fopen(fichHash, "r+b");
   if (!fSalida)
   {
      fclose(fEntrada);
      return -2;
   }

   while (fread(&reg, sizeof(tipoReg), 1, fEntrada) == 1)
   {
      if (insertar(fSalida, &reg, regC) != 0)
      {
         fclose(fEntrada);
         fclose(fSalida);
         return -5;
      }
   }

   rewind(fSalida);
   fwrite(regC, sizeof(regConfig), 1, fSalida);

   if (regC->nCubos == 0 || C == 0)
   {
      fclose(fEntrada);
      fclose(fSalida);
      return -5; // evitar división por cero
   }
   float densidad = ((float)regC->numReg / (regC->nCubos * C)) * 100;

   fclose(fEntrada);
   fclose(fSalida);

   if (densidad > regC->densidadMax)
      return -3;
   if (densidad < regC->densidadMin)
      return -4;

   return 0;
}

int busquedaHash(FILE *fHash, tipoReg *reg, tPosicion *posicion)
{
   if (!fHash)
      return -2;

   tipoCubo cubo;
   int i, posHash;

   regConfig regC;
   rewind(fHash);
   fread(&regC, sizeof(regConfig), 1, fHash);
   
   posHash = funcionHash(reg, regC.nCubos);
   posicion->cubo = posHash;
   posicion->cuboDes = -1;
   posicion->posReg = -1;

   fseek(fHash, sizeof(regConfig) + posHash * sizeof(tipoCubo), SEEK_SET);
   fread(&cubo, sizeof(tipoCubo), 1, fHash);

   for (i = 0; i < cubo.numRegAsignados && i < C; i++)
   {
      if (cmpClave(&cubo.reg[i], reg) == 0)
      {
         *reg = cubo.reg[i];
         posicion->posReg = i;
         return 0;
      }
   }

   if (cubo.desbordado)
   {
      int posDesb = posicion->cubo + 1;
      int cubosLeidos = 0;

      regConfig cabecera;
      rewind(fHash);
      fread(&cabecera, sizeof(regConfig), 1, fHash);

      int totalDesborde = cabecera.nCubosDes;
      int iniDesb = cabecera.nCubos;

      for (i = 0; i < totalDesborde; i++)
      {
         fseek(fHash, sizeof(regConfig) + (iniDesb + i) * sizeof(tipoCubo), SEEK_SET);
         fread(&cubo, sizeof(tipoCubo), 1, fHash);

         for (int j = 0; j < cubo.numRegAsignados; j++)
         {
            if (cmpClave(&cubo.reg[j], reg) == 0)
            {
               *reg = cubo.reg[j];
               posicion->cuboDes = iniDesb + i;
               posicion->posReg = j;
               return 0;
            }
         }
      }
   }

   return -1;
}

int modificarReg(FILE *fHash, tipoReg *reg, tPosicion *posicion)
{
   if (!fHash)
      return -2;

   tipoCubo cubo;
   tipoReg original = *reg;

   int resultado = busquedaHash(fHash, &original, posicion);
   if (resultado == -1)
      return -1; // no existe
   if (resultado != 0)
      return resultado; // -2 u -5

   int cuboIndex = (posicion->cuboDes == -1) ? posicion->cubo : posicion->cuboDes;

   fseek(fHash, sizeof(regConfig) + cuboIndex * sizeof(tipoCubo), SEEK_SET);
   fread(&cubo, sizeof(tipoCubo), 1, fHash);

   cubo.reg[posicion->posReg] = *reg;

   fseek(fHash, -sizeof(tipoCubo), SEEK_CUR);
   fwrite(&cubo, sizeof(tipoCubo), 1, fHash);

   return 0;
}
