#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"

tipoElemento ERROR = -1;

int colaCreaVacia(Cola *c)
{
	if(NULL==c) return -1; //La cola no existe
	//Establecemos los punteros de la cola a NULL
	c->frente=c->fondo=NULL;
    
    
}

int colaVacia(Cola *c)
{
	if(NULL==c) return -1; //La cola no existe
	else return(c->frente==NULL && c->fondo==NULL);
	return 0;
    
}

int colaInserta(Cola *c,tipoElemento elemento)
{
	if(NULL==c) return -1; //La cola no existe
      
	tipoCelda  *nuevaCelda;
	if(NULL== (nuevaCelda=malloc(sizeof(tipoCelda)))) return -2;
      
	nuevaCelda->elemento=elemento;
	nuevaCelda->sig=NULL;
      
	//Contemplamos el caso de que la pila esté vacía
	if(colaVacia(c)) {c->frente=nuevaCelda; c->fondo=nuevaCelda;}
	else {
          c->fondo->sig = nuevaCelda; // Apuntar el antiguo fondo al nuevo nodo
          c->fondo = nuevaCelda; // Ahora el nuevo nodo es el fondo
        }
	return 0;
    
}

tipoElemento colaSuprime(Cola *c)
{
	if(NULL==c) return ERROR; //La cola no existe
	else if(colaVacia(c)) return ERROR; //La cola está vacia
    
	tipoCelda*aBorrar = c->frente;
	tipoElemento valor = aBorrar->elemento;
	
	c->frente = aBorrar->sig; 
	if(aBorrar == c->fondo) //Si es el ultimo elemento
		c->fondo = c->frente;
	free(aBorrar);

	return valor;
    
}
