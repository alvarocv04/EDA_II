#include "conjuntos.h"
#include <stdio.h>
/// Incluir aqui las funciones que implementan las tres operaciones básicas
/// en la representación de CONJUNTOS DISJUNTOS mediante MATRICES
/// ......................................................................

void crea(particion P)
{
    for (int i = 0; i < MAXIMO; i++)
    {
        P[i] = i;
    };
}

tipoConjunto buscar(tipoElemento x, particion P)
{
    if (P[x] == x)
        return x;
    return P[x];
}

int unir(tipoConjunto x, tipoConjunto y, particion P)
{
    if (P[x] != x || P[y] != y)
    {
        return 0;
    }
    for (int i = 0; i < MAXIMO; i++)
    {
        if (P[i] == y)
        {
            P[i] = x;
        }
    }
    return 1;
}
//
// Función auxiliar para ver contenido de Partición
//
void verParticion(particion P)
{
    int i;
    printf("\n");
    for (i = 0; i < MAXIMO; i++)
        printf("|%2d", P[i]);
    printf("| contenido  vector\n");
    for (i = 0; i < MAXIMO; i++)
        printf("---");
    printf("\n");
    for (i = 0; i < MAXIMO; i++)
        printf(" %2d", i);
    printf("  índices vector\n\n");
}
