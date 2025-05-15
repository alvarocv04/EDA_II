#include "../include/asignatura.h"

int funcionHash(tAsignatura *reg, int nCubos) {
    return reg->codigo % nCubos;  // función hash: módulo del número de cubos
}
