#include "conjuntos.h"
#include <stdio.h>

/// Incluir aqui las funciones que implementan las tres operaciones básicas
/// en la representación de CONJUNTOS DISJUNTOS mediante ÁRBOLES
/// ......................................................................
/*
void crea(particion P)
{
    for (int i = 0; i < MAXIMO; i++)
    {
        P[i] = i;
    }
}

tipoConjunto buscar(tipoElemento x, particion P)
{
    if (P[x] == x)
    {
        return x;
    }
    return buscar(P[x], P);
}

int unir(tipoConjunto x, tipoConjunto y, particion P)
{
    if(P[x]!=x || P[y]!=y)
    {
        return 0;
    }
    P[y]=x;
    return 1;
}
*/

// UNION POR TAMAÑO
/*
void crea(particion P)
{
    for (int i = 0; i < MAXIMO; i++)
    {
        P[i] = -1;
    }
}

tipoConjunto buscar(tipoElemento x, particion P)
{
    if (P[x] < 0)
    {
        return x;
    }
    return buscar(P[x], P);
}

int unir(tipoConjunto x, tipoConjunto y, particion P)
{
    if (P[x] >= 0 || P[y] >= 0)
    {
        return 0;
    }
    if (P[x] <= P[y])
    {
        P[x]=P[x]+P[y];
        P[y] = x;
        return 1;
    }
    else{
        P[y]=P[y]+P[x];
        P[x]=y;
        return 1;
    }
}
 */

// UNION POR ALTURA

void crea(particion P)
{
    for (int i = 0; i < MAXIMO; i++)
    {
        P[i] = -1;
    }
}

/*tipoConjunto buscar(tipoElemento x, particion P)
{
    if (P[x] < 0)
    {
        return x;
    }
    return buscar(P[x], P);
}
*/
//BUSCAR CON COMPRENSION DE CAMINO
tipoConjunto buscar(tipoElemento x, particion P)
{
    if (P[x] < 0)
    {
        return x;
    }
    tipoElemento padre = buscar(P[x], P);
    P[x]=padre;
    return padre;
}

int unir(tipoConjunto x, tipoConjunto y, particion P)
{
    if (P[x] >= 0 || P[y] >= 0)
    {
        return 0;
    }
    if (P[x] <= P[y])
    {
        if (P[x] == P[y])
            P[x]--;
        P[y] = x;
        return 1;
    }
    else
    {
        P[x] = y;
        return 1;
    }
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
