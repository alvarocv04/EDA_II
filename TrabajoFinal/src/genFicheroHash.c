#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include "../include/dispersion.h"

int main()
{ regConfig regC;
  int error;
  char fEntrada[50],fSalida[50];
	#ifdef ALUM 
 		strcpy(fEntrada,"../datos/alumnos.dat");
 		strcpy(fSalida,"../datos/alumnosC.hash");
	  	regC.nCubos=15;
	#endif  	  	
	#ifdef ASIG
 		strcpy(fEntrada,"../datos/asignaturas.dat");
 		strcpy(fSalida,"../datos/asignaturasC.hash");
	  	regC.nCubos=10;
	#endif  	
  	regC.nCubosDes=4;	// Número de cubos area de desborde
	regC.densidadMax=80;
	regC.densidadMin=40;
	
	error = creaHash(fEntrada,fSalida,&regC);
  	switch (error) {
		case -1:
		case -2:
		case -5 : {	printf("Error %d en la función creaHash\n", error);
  			  	return -1;
  			  }
		case -3: printf("Error (%d): Se supera densidad máxima de ocupación\n",
			error);
  			 break;
	  	case -4: printf("Error (%d): No se alcaza densidad mínima de ocupación\n",
  		 	error);
  		 	 break;
  	}
  	leeHash(fSalida); 	
  	} 	 		  		
  			
