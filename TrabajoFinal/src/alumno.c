#include <stdlib.h>
#include "../include/alumno.h"

int funcionHash(tAlumno *reg, int nCubos) {
    int clave = atoi(reg->dni); // convertir DNI a número
    return clave % nCubos;      // función hash: módulo del número de cubos
}
