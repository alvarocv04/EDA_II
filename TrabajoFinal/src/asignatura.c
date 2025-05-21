#include "../include/asignatura.h"
#include "../include/dispersion.h"
#include <stdio.h>

int funcionHash(tAsignatura *reg, int nCubos)
{
    return reg->codigo % nCubos; // función hash: módulo del número de cubos
}

void mostrarReg(tAsignatura *reg)
{
    printf("Código: %d, Nombre: %s, Curso: %c, Créditos T: %.2f, Créditos P: %.2f, Tipo: %c, Cuatrimestre: %c, Grupos T: %d, Grupos P: %d\n",
           reg->codigo, reg->nombre, reg->curso,
           reg->creditosT, reg->creditosP,
           reg->tipo, reg->cuatrimestre,
           reg->numGrT, reg->numGrP);
}

int cmpClave(tAsignatura *reg1, tAsignatura *reg2)
{
    return reg1->codigo - reg2->codigo;
}

int buscar(char *fichero, int codigo)
{
    FILE *f = fopen(fichero, "rb");
    if (!f)
        return -2;
    tAsignatura a;
    tPosicion pos;
    a.codigo = codigo;

    int res = busquedaHash(f, &a, &pos);
    fclose(f);

    if (res == 0)
    {
        mostrarReg(&a);
        return 0;
    }

    return res;
}

int modificar(char *fichero, int codigo, float creditosT, float creditosP)
{
    FILE *f = fopen(fichero, "r+b");
    if (!f)
        return -2;

    tAsignatura a;
    tPosicion pos;
    a.codigo = codigo;

    int res = busquedaHash(f, &a, &pos);
    if (res != 0)
    {
        fclose(f);
        return res;
    }

    a.creditosT = creditosT;
    a.creditosP = creditosP;

    res = modificarReg(f, &a, &pos);
    fclose(f);
    return res;
}