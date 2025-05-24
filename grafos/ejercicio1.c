#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "grafos.h"

tipoGrafo *creaGrafoT26();

int main(void)
{ tipoGrafo *gT26;
  
  	printf("\nSi el directorio de  vertices no se inicia correctamente los recorridos no funionan\n");
	gT26 = creaGrafoT26();
	verGrafo(gT26);
  	printf("\nProfundidad: ");
	iniciar(gT26);
  	profundidad(1,gT26);
  	printf("\nProfundidad: ");	
	iniciar(gT26);
	profundidad(1,gT26);
	printf("\n\nIncluso iniciando correctamente directorio de vértices los recorridos depeden del vértice inicial y del tipo de grafo. ¡¡ Necesidad de mejorar los recorridos!! \n");
  	printf("\nProfundidad: ");
	iniciar(gT26);
  	profundidad(6,gT26);
 	printf("\nAmplitud : ");
	iniciar(gT26);
 	amplitud(1,gT26);
	printf("\nAmplitud : ");
	iniciar(gT26);
 	amplitud(6,gT26);
	verGrafo(gT26);

}
/********************************************************/
/* Creación del grafo de la figura 1 (transparecnia 26) */
/********************************************************/
tipoGrafo *creaGrafoT26()
{ int i;
  pArco  p;
  tipoGrafo *g;

  g=(tipoGrafo *)calloc(1,sizeof(tipoGrafo));

  g->orden=7;

  // Lista de adyacencia del vértice 1
  p = (arco *)calloc(1,sizeof(arco));
  p->v = 2;
  p->peso = 1;
  g->directorio[1].lista=p;
  p = (arco *)calloc(1,sizeof(arco));
  p->v = 3;
  p->peso = 1;
  g->directorio[1].lista->sig=p;
  p = (arco *)calloc(1,sizeof(arco));
  p->v = 4;
  p->peso = 1;
  g->directorio[1].lista->sig->sig=p;
  p->sig=NULL;
  // Lista de adyacencia del vértice 2
  p = (arco *)calloc(1,sizeof(arco));
  p->v = 4;
  p->peso = 1;
  g->directorio[2].lista=p;
  p= (arco *)calloc(1,sizeof(arco));
  p->v = 5;
  p->peso = 1;
  g->directorio[2].lista->sig=p;
  p->sig=NULL;
  // Lista de adyacencia del vértice 3
  p = (arco *)calloc(1,sizeof(arco));
  p->v = 6;
  p->peso = 1;
  g->directorio[3].lista=p;
  p->sig=NULL;
  // Lista de adyacencia del vértice 4
  p = (arco *)calloc(1,sizeof(arco));
  p->v = 3;
  p->peso = 1;
  g->directorio[4].lista=p;
  p= (arco *)calloc(1,sizeof(arco));
  p->v = 6;
  p->peso = 1;
  g->directorio[4].lista->sig=p;
  p = (arco *)calloc(1,sizeof(arco));
  p->v = 7;
  p->peso = 1;
  g->directorio[4].lista->sig->sig=p;
  p->sig=NULL;
// Lista de adyacencia del vértice 5
  p = (arco *)calloc(1,sizeof(arco));
  p->v = 4;
  p->peso = 1;
  g->directorio[5].lista=p;
  p= (arco *)calloc(1,sizeof(arco));
  p->v = 7;
  p->peso = 1;
  g->directorio[5].lista->sig=p;
  p->sig=NULL;
// Lista de adyacencia del vértice 6
  g->directorio[6].lista=NULL;
// Lista de adyacencia del vértice 7
  p = (arco *)calloc(1,sizeof(arco));
  p->v = 6;
  p->peso = 1;
  g->directorio[7].lista=p;
  p->sig=NULL;

  return g;
  }

