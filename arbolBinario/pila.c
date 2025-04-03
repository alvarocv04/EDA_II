#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"



int pilaCreaVacia(Pila *p)
{
    if(p==NULL) return -1;
    else {*p=NULL; return 0;}
}

int pilaVacia(Pila *p)
{
   if(p==NULL) return -1;
   else{ return(*p==NULL); }
}

int pilaInserta(Pila *p,tipoElemento elemento)
{
      if(p==NULL) return -1; //Por si la pila no existe
      tipoCelda   *nuevaCelda;
      if(NULL== (nuevaCelda=malloc(sizeof(tipoCelda)))) return -2;
      
      nuevaCelda->elemento=elemento;
      nuevaCelda->sig=NULL;
      
      //Contemplamos el caso de que la pila esté vacía
      if(pilaVacia(p)) *p=nuevaCelda;
      else {nuevaCelda->sig=*p; *p=nuevaCelda;}
      return 0;
}

tipoElemento pilaSuprime(Pila *p)
{
	if(p==NULL) return NULL; //Por si la pila no existe
	if(pilaVacia(p)) return NULL; //Por si la pila está vacía
	
	tipoCelda *aBorrar = *p;
	tipoElemento aux=aBorrar->elemento;
	
	*p= (*p)->sig;
   	
   	free(aBorrar);
   	
   	return aux;
}
