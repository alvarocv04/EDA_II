#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conjuntos.h"

tipoCelda *creaNodo(tipoElemento x)
{
  tipoCelda *n;

  if (NULL == (n = malloc(sizeof(tipoCelda))))
    return NULL;

  n->elemento = x;
  n->sig = NULL;

  return n;
}

/// Incluir aqui las funciones que implementan las tres operaciones básicas
/// en la representación de CONJUNTOS DISJUNTOS mediante LISTAS
/// ......................................................................

void crea(particion P)
{
  for (int i = 0; i < MAXIMO; i++)
  {
    P[i].primero = creaNodo(i);
    P[i].ultimo = creaNodo(i);
  }
}

tipoConjunto buscar(tipoElemento x, particion P)
{
  tipoCelda y;
  for (int i = 0; i < MAXIMO; i++)
  {
    if (P[i].primero != NULL)
    {
      y = *P[i].primero;
      if (y.elemento == x)
      {
        return x;
      }
      while (y.sig != NULL)
      {
        y = *y.sig;
        if (y.elemento == x)
        {
          return x;
        }
      }
    }
  }
  return 0;
}
int unir(tipoConjunto x, tipoConjunto y, particion P){
  if(P[x].primero == NULL || P[y].primero==NULL){
    return 0;
  }
  if(P[x].primero->elemento != x || P[y].primero->elemento != y){
    return 0;
  }
  P[x].ultimo->sig = P[y].primero;
  P[x].ultimo=P[y].ultimo;
  P[y].primero=NULL;
  P[y].ultimo=NULL;
  return 1;
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
