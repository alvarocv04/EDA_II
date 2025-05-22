//ÁLVARO CASTRO VALVERDE PB3 70926103Z
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/alumno.h"
#include "../include/dispersion.h"

int funcionHash(tAlumno *reg, int nCubos)
{
    int clave = atoi(reg->dni); // convertir DNI a número
    return clave % nCubos;      // función hash: módulo del número de cubos
}

void mostrarReg(tAlumno *reg)
{
    printf("DNI: %s, Nombre: %s %s %s, Provincia: %s\n",
           reg->dni, reg->nombre, reg->ape1, reg->ape2, reg->provincia);
}

// Comparar claves por DNI
int cmpClave(tAlumno *reg1, tAlumno *reg2)
{
    return strcmp(reg1->dni, reg2->dni);
}

int buscar(char *fichero, char *dni)
{
    FILE *f = fopen(fichero, "rb");
    if (!f)
        return -2;

    tAlumno a;
    tPosicion pos;
    strcpy(a.dni, dni);

    int res = busquedaHash(f, &a, &pos);

    fclose(f);

    if (res < 0)
        printf("No existe alumno con dni %s", dni);

    if (res == 0)
    {
        mostrarReg(&a);
        return 0;
    }

    return res;
}

int modificar(char *fichero, char *dni, char *provincia)
{
    FILE *f = fopen(fichero, "r+b");
    if (!f)
        return -2;

    tAlumno a;
    tPosicion pos;
    strcpy(a.dni, dni);
    int res = busquedaHash(f, &a, &pos);
    if (res != 0)
    {
        fclose(f);
        return res;
    }

    strcpy(a.provincia, provincia);

    res = modificarReg(f, (tipoReg *)&a, &pos);
    fclose(f);
    return res;
}