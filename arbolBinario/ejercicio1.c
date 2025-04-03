#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"

int main(void)
{
  Arbol varArbol;

  /* Creación arbol ejemplo de las transparencias de recorridos */
  varArbol = creaNodo('A');
  varArbol->izq = creaNodo('B');
  varArbol->der = creaNodo('C');
  varArbol->izq->izq = creaNodo('D');
  varArbol->izq->der = creaNodo('E');
  varArbol->der->izq = creaNodo('F');
  varArbol->der->der = creaNodo('G');

  /* Aplicación de recorridos al arbol ejemplo */

  printf("Recorrido en PRE_ORDEN: ");
  preOrden(varArbol);
  printf("\n");
  printf("Recorrido en ORDEN: ");
  enOrden(varArbol);
  printf("\n");
  printf("Recorrido en POST_ORDEN: ");
  postOrden(varArbol);
  printf("\n");
  printf("Recorrido en AMPLITUD: ");
  amplitud(varArbol);
  printf("\n");

  /* Comenzar a implementar y probar las funciones del ejercicio 2 ... y segunda parte del ejercicio 3 */

  printf("La altura del arbol es: %d\r\n", altura(varArbol));
  fflush(stdout);
  printf("El numero de nodos del arbol es: %d\r\n", numNodos(varArbol));
  fflush(stdout);
  /*printf("Sustituyo los nodos D por X: un total de %d sustituciones\n", sustituye(varArbol, 'D', 'X'));
  printf("Recorrido en AMPLITUD: ");
  amplitud(varArbol);
  printf("\n");
  */
  printf("El numero de nodos hoja del arbol es: %d\r\n", numNodosHoja(varArbol));
  fflush(stdout);
  printf("El numero de nodos internos del arbol es: %d\r\n", numNodosInternos(varArbol));
  fflush(stdout);
  printf("El numero de hijos unicos del arbol es: %d\r\n", numHijoUnico(varArbol));
  fflush(stdout);
  printf("El valor maximo de un nodo del arbol es: %d\r\n", buscarMax(varArbol)->info);
  fflush(stdout);
  printf("El valor minimo  de un nodo del arbol es: %d\r\n", buscarMin(varArbol)->info);
  fflush(stdout);
  return 1;
}
