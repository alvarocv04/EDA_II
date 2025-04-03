# Ejercicio 1
cMatrices:prueba.c rMatrices/conjuntos.o  
	gcc -g prueba.c -DMATRICES rMatrices/conjuntos.o -o cMatrices
rMatrices/conjuntos.o: rMatrices/conjuntos.c rMatrices/conjuntos.h
	gcc -c -g rMatrices/conjuntos.c -o rMatrices/conjuntos.o
# Ejercicio 2
cListas:prueba.c rListas/conjuntos.o 
	gcc -g prueba.c -DLISTAS rListas/conjuntos.o -o cListas
rListas/conjuntos.o: rListas/conjuntos.c rListas/conjuntos.h
	gcc -c -g rListas/conjuntos.c -o rListas/conjuntos.o
# Ejercicio 3 
cArboles:prueba.c rArboles/conjuntos.o 
	gcc -g prueba.c -DARBOLES rArboles/conjuntos.o -o cArboles
rArboles/conjuntos.o: rArboles/conjuntos.c rArboles/conjuntos.h
	gcc -c -g rArboles/conjuntos.c -o rArboles/conjuntos.o
# Ejercicio 4, 5 y 6
#  ....

limpiar:
	rm c*
