#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"
#include "cola.h"

//
// Reserva de memoria para un nuevo nodo de árbol binario
//
Arbol creaNodo(tipoInfo info)
{
  tipoNodo *nuevo;

  //   nuevo =(tipoNodo *)calloc(1, sizeof(tipoNodo));
  if ((nuevo = (tipoNodo *)malloc(sizeof(tipoNodo))) == NULL)
    return NULL;
  else
  {
    nuevo->info = info;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
  }
}

//
// Recorrido en amplitud o por niveles: necesita una cola de punteros a nodos de árbol binario!!!
//

void amplitud(Arbol raiz)
{
  Cola c;
  tipoNodo *nodo;
  colaCreaVacia(&c);
  nodo = raiz;
  if (raiz != NULL)
    colaInserta(&c, nodo);
  while (!colaVacia(&c))
  {
    nodo = (Arbol)colaSuprime(&c);
    printf(" %c ", nodo->info);
    if (nodo->izq != NULL)
      colaInserta(&c, nodo->izq);
    if (nodo->der != NULL)
      colaInserta(&c, nodo->der);
  }
}
//
// Recorridos en profundidad "recursivos"
//
void preOrden(Arbol raiz)
{
  if (raiz != NULL)
  {
    printf("%c ", raiz->info);
    preOrden(raiz->izq);
    preOrden(raiz->der);
  }
}
void enOrden(Arbol raiz)
{
  if (raiz != NULL)
  {
    enOrden(raiz->izq);
    printf("%c ", raiz->info);
    enOrden(raiz->der);
  }
}
void postOrden(Arbol raiz)
{
  if (raiz != NULL)
  {
    postOrden(raiz->izq);
    postOrden(raiz->der);
    printf("%c ", raiz->info);
  }
}

int altura(Arbol raiz)
{
  if (raiz == NULL)
  {
    return -1;
  }
  int alturaIzqda = altura(raiz->izq);
  int alturaDcha = altura(raiz->der);
  return alturaIzqda > alturaDcha ? alturaIzqda + 1 : alturaDcha + 1;
}

int numNodos(Arbol raiz)
{
  if (raiz == NULL)
  {
    return 0;
  }
  int numNodosIzqda = numNodos(raiz->izq);
  int numNodosDcha = numNodos(raiz->der);
  return numNodosIzqda + numNodosDcha + 1;
}

Arbol anula(Arbol raiz)
{
  if (raiz == NULL)
  {
    return NULL;
  }
  raiz->izq = anula(raiz->izq);
  raiz->der = anula(raiz->der);
  free(raiz);
  return NULL;
}

int sustituye(Arbol raiz, tipoInfo x, tipoInfo y)
{
  if (raiz == NULL)
  {
    return 0;
  }
  if (raiz->info == x)
  {
    raiz->info = y;
    return sustituye(raiz->izq, x, y) + sustituye(raiz->der, x, y) + 1;
  }
  else
  {
    return sustituye(raiz->izq, x, y) + sustituye(raiz->der, x, y);
  }
}

int numNodosHoja(Arbol raiz)
{
  if (raiz == NULL)
  {
    return 0;
  }
  if (raiz->der == NULL && raiz->izq == NULL)
  {
    return numNodosHoja(raiz->der) + numNodosHoja(raiz->izq) + 1;
  }
  else
  {
    return numNodosHoja(raiz->der) + numNodosHoja(raiz->izq);
  }
}

int numNodosInternos(Arbol raiz)
{
  if (raiz == NULL)
  {
    return 0;
  }
  return numNodos(raiz) - numNodosHoja(raiz) - 1;
}

int numHijoUnico(Arbol raiz)
{
  if (raiz == NULL)
  {
    return 0;
  }
  if ((raiz->der == NULL && raiz->izq != NULL) || (raiz->der != NULL && raiz->izq == NULL))
  {
    return numHijoUnico(raiz->der) + numHijoUnico(raiz->izq) + 1;
  }
  else
  {
    return numHijoUnico(raiz->der) + numHijoUnico(raiz->izq);
  }
}

Arbol buscarMax(Arbol raiz)
{
  if (raiz == NULL)
  {
    return 0;
  }
  Arbol maxIzqda = buscarMax(raiz->izq);
  Arbol maxDcha = buscarMax(raiz->der);
  Arbol maximo = raiz;
  if (maxIzqda != NULL && maxIzqda->info > maximo->info)
  {
    maximo = maxIzqda;
  }
  if (maxDcha != NULL && maxDcha->info > maximo->info)
  {
    maximo = maxDcha;
  }
  return maximo;
}
Arbol buscarMin(Arbol raiz)
{
  if (raiz == NULL)
  {
    return 0;
  }
  Arbol minIzqda = buscarMin(raiz->izq);
  Arbol minDcha = buscarMin(raiz->der);
  Arbol minimo = raiz;
  if (minIzqda != NULL && minIzqda->info < minimo->info)
  {
    minimo = minIzqda;
  }
  if (minDcha != NULL && minDcha->info < minimo->info)
  {
    minimo = minDcha;
  }
  return minimo;
}

int similares(Arbol r1, Arbol r2)
{
  if (r1 == NULL && r2 == NULL)
  {
    return 1;
  }
  else
  {
    if ((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL))
    {
      return 0;
    }
    else
    {
      return similares(r1->izq, r2->izq) * similares(r1->der, r2->der);
    }
  }
}

int equivalentes(Arbol r1, Arbol r2)
{
  if (r1 == NULL && r2 == NULL)
    return 1;
  else if ((NULL == r1 && NULL != r2) || (NULL != r1 && NULL == r2))
    return 0;
  else
  { // if(NULL != r1 && NULL != r2)
    if (r1->info == r2->info)
      return equivalentes(r1->izq, r2->izq) * equivalentes(r1->der, r2->der);
    else
      return 0;
  }
}
Arbol especular(Arbol raiz)
{
  if (NULL == raiz)
    return NULL;
  else
  {
    Arbol a = creaNodo(raiz->info);
    a->izq = especular(raiz->der);
    a->der = especular(raiz->izq);
    return a;
  }
}

int nodosPorNivel(Arbol raiz, int nivel)
{
  int nivelActual = 0;
  if (raiz == NULL)
  {
    return 0;
  }
  if (nivel == 0)
  {
    return 1;
  }
  int nodosDerecha = nodosPorNivel(raiz->der, nivel-1);
  int nodosIzquierda = nodosPorNivel(raiz->izq, nivel-1);
  return nodosDerecha + nodosIzquierda;
}