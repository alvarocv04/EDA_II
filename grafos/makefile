# Sesión Grafos

ejercicio1: ejercicio1.c grafos.h grafos.o cola.o
	gcc -g ejercicio1.c grafos.o cola.o -o ejercicio1
ejercicio2: ejercicio2.c grafos.h grafos.o cola.o 
	gcc -g ejercicio2.c grafos.o cola.o -o ejercicio2


# Para la ultima parte de ejercicio2.c necesitamos monticulo.o ...cambia la linea de ordenes...
#ejercicio2: ejercicio2.c grafos.h grafos.o cola.o monticulo.o 
#	gcc -g ejercicio2.c grafos.o cola.o monticulo.o -o ejercicio2




grafos.o: grafos.c grafos.h
	gcc -g -c grafos.c
cola.o: cola.c cola.h
	gcc -g -c cola.c
# hay que modificar tipoElemento de monticulo 	
# CUIDADO hay que cambiar tipoElemento de monticulo a tipoElementoM ....
monticulo.o:monticulo.c monticulo.h
	gcc -g -c monticulo.c
limpiar:
	rm *.o	


