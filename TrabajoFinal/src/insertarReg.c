//ÁLVARO CASTRO VALVERDE PB3 70926103Z
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include "../include/dispersion.h"

int main()
{

#ifdef ALUM

    FILE *f = fopen("../datos/alumnosC.hash", "r+b");
    if (!f)
    {
        printf("Error al abrir el fichero hash\n");
        return -1;
    }

    regConfig config;
    fread(&config, sizeof(regConfig), 1, f);

    tAlumno nuevo;
    printf("Introduce nuevo alumno:\n");
    fflush(stdin);
    printf("Nombre: ");
    scanf("%s", nuevo.nombre);
    printf("DNI: ");
    scanf("%s", nuevo.dni);
    printf("Apellido 1: ");
    scanf("%s", nuevo.ape1);
    printf("Apellido 2: ");
    scanf("%s", nuevo.ape2);
    printf("Provincia: ");
    scanf("%s", nuevo.provincia);

    int res = insertar(f, &nuevo, &config);
    if (res != 0)
    {
        printf("Error al insertar (código %d)\n", res);
        fclose(f);
        return res;
    }

    rewind(f);
    fwrite(&config, sizeof(regConfig), 1, f);

    tPosicion posicion;
    posicion.cubo = -1;
    posicion.cuboDes = -1;
    busquedaHash(f, &nuevo, &posicion);
    printf("ALUMNO INSERTADO CORRECTAMENTE, VÉASE:\n" );
    leeHash("../datos/alumnosC.hash");
    fclose(f);

#endif
#ifdef ASIG
    FILE *f = fopen("../datos/asignaturasC.hash", "r+b");
    if (!f)
    {
        printf("Error al abrir el fichero hash\n");
        return -1;
    }

    regConfig config;
    fread(&config, sizeof(regConfig), 1, f);

    tAsignatura nueva;

    printf("Introduce nueva asignatura:\n");
    printf("Código: ");
    scanf("%d", &nueva.codigo);
    printf("Nombre: ");
    scanf(" %[^\n]", nueva.nombre);
    printf("Curso: ");
    scanf(" %c", &nueva.curso);
    printf("Créditos T: ");
    scanf("%f", &nueva.creditosT);
    printf("Créditos P: ");
    scanf("%f", &nueva.creditosP);
    printf("Tipo: ");
    scanf(" %c", &nueva.tipo);
    printf("Cuatrimestre: ");
    scanf(" %c", &nueva.cuatrimestre);
    printf("Nº grupos T: ");
    scanf("%d", &nueva.numGrT);
    printf("Nº grupos P: ");
    scanf("%d", &nueva.numGrP);

    int res = insertar(f, &nueva, &config);
    if (res != 0)
    {
        printf("Error al insertar (código %d)\n", res);
        fclose(f);
        return res;
    }

    rewind(f);
    fwrite(&config, sizeof(regConfig), 1, f);
    fclose(f);

    printf("ASIGNATURA INSERTADO CORRECTAMENTE, VÉASE:\n" );
    leeHash("../datos/asignaturasC.hash");
#endif
}
