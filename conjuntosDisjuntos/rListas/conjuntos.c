#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conjuntos.h"

/// Incluir aqui las funciones que implementan las tres operaciones básicas
/// en la representación de CONJUNTOS DISJUNTOS mediante LISTAS
/// ......................................................................

void crea(particion P)
{
  for (int i = 0; i < MAXIMO; i++)
  {
    P[i].primero = i;
    P[i].ultimo = i;
    P[i].primero->elemento = i;
    P[i].primero->sig = NULL;
  }
}

tipoConjunto buscar(tipoElemento x, particion P)
{
  tipoCelda y;
  for (int i = 0; i < MAXIMO; i++)
  {
    if (P[i] != NULL)
    {
      y = *P[i].primero;
      while (y.sig != NULL)
      {

      }
    }
  }
}

void verParticion(particion P)
{
  int i;
  tipoCelda *aux;
  for (i = 0; i < MAXIMO; i++)
  {
    aux = P[i].primero;
    if (aux != NULL)
      printf("\n\nClase equivalencia representante %d: ", i);
    while (aux != NULL)
    {
      printf("%d ", aux->elemento);
      aux = aux->sig;
    }
  }
}

void verClaseEquivalencia(tipoElemento x, particion P)
{
  int representante;
  tipoCelda *aux;

  representante = buscar(x, P);
  printf("\n\nClase de Equivalencia de %d cuyo representante es %d: ", x, representante);
  aux = P[representante].primero;
  while (aux)
  {
    printf(" %d ", aux->elemento);
    aux = aux->sig;
  }
  printf("\n\n");
}
