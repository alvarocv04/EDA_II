#ifndef __CONJUNTOS_H
#define __CONJUNTOS_H

#define MAXIMO 16

typedef int tipoElemento;
typedef int tipoConjunto;
typedef struct tipoCelda {
	tipoElemento elemento;
	struct tipoCelda * sig;
	} tipoCelda;


typedef struct {
	tipoCelda * primero , *ultimo;
	} tipoLista;


typedef tipoLista particion[MAXIMO];


// Funciones a implementar

void crea(particion P);

tipoConjunto buscar(tipoElemento x, particion P);

// Implementación de operación unir con control de representantes:
// Si x e y son los representantes de sus clases de equivalencia las unen y devuelven VERDADERO,
// en otro caso no hace nada y devuelve FALSO

int unir(tipoConjunto x, tipoConjunto y, particion P);

// Funciones proporcionadas
void verParticion(particion P);
void verClaseEquivalencia(tipoElemento x,particion P);

#endif

