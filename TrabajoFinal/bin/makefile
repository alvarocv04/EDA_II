# Generación de fichero por el método de dispersión
SRC=../src/
H=../include/
OBJ=../lib/
CTAGS = -c -g 
ALUMNO =-DALUM -c -g
ASIG = -DASIG -c -g 
# Parte 3. Ejercicio 1: Crear alumnosC.hash
genAlumnosH: $(OBJ)genAlumnosH.o $(OBJ)dispersionAl.o $(OBJ)alumno.o
	gcc $(OBJ)genAlumnosH.o $(OBJ)dispersionAl.o $(OBJ)alumno.o -o genAlumnosH
$(OBJ)genAlumnosH.o: $(SRC)genFicheroHash.c $(H)dispersion.h 
	gcc $(ALUMNO) $(SRC)genFicheroHash.c -o $(OBJ)genAlumnosH.o
	
# Parte 3. Ejercicio 2: Crear asignaturasC.hash
genAsignaturasH: $(OBJ)genAsignaturasH.o $(OBJ)dispersionAs.o $(OBJ)asignatura.o 
	gcc $(OBJ)genAsignaturasH.o $(OBJ)dispersionAs.o $(OBJ)asignatura.o -o genAsignaturaH
$(OBJ)genAsignaturasH.o: $(SRC)genFicheroHash.c $(H)dispersion.h
	gcc $(ASIG) $(SRC)genFicheroHash.c -o $(OBJ)genAsignaturasH.o

# Parte 3. Ejercicio 3: Acceso alumnosC.hash
modAlumnoH: $(OBJ)modAlumnoH.o $(OBJ)dispersionAl.o $(OBJ)alumno.o
	gcc $(OBJ)modAlumnoH.o $(OBJ)dispersionAl.o $(OBJ)alumno.o -o modAlumnoH	

$(OBJ)modAlumnoH.o: $(SRC)modFicheroHash.c $(H)dispersion.h 
	gcc $(ALUMNO) $(SRC)modFicheroHash.c -o $(OBJ)modAlumnoH.o

# Parte 3. Ejercicio 4: Acceso asignaturasC.hash	
modAsigH: $(OBJ)modAsignaturaH.o $(OBJ)dispersionAs.o $(OBJ)asignatura.o
	gcc $(OBJ)modAsignaturaH.o $(OBJ)dispersionAs.o $(OBJ)asignatura.o -o modAsigH
$(OBJ)modAsignaturaH.o: $(SRC)modFicheroHash.c $(H)dispersion.h
	gcc $(ASIG) $(SRC)modFicheroHash.c -o $(OBJ)modAsignaturaH.o
# Parte	3. Ejercicio 5: Insertar registros en alumnosC.Hash y asignaturasC.Hash
### ......
	
# Funciones genéricas de dispersión
$(OBJ)dispersionAl.o: $(H)dispersion.h $(H)alumno.h $(SRC)dispersion.c
	gcc $(ALUMNO) $(SRC)dispersion.c -o $(OBJ)dispersionAl.o
$(OBJ)dispersionAs.o: $(H)dispersion.h $(H)asignatura.h $(SRC)dispersion.c
	gcc $(ASIG) $(SRC)dispersion.c -o $(OBJ)dispersionAs.o
# Funciones especificas
$(OBJ)asignatura.o: $(H)asignatura.h $(SRC)asignatura.c
	gcc $(ASIG) $(SRC)asignatura.c -o $(OBJ)asignatura.o	
$(OBJ)alumno.o: $(H)alumno.h $(SRC)alumno.c
	gcc $(ALUMNO) $(SRC)alumno.c -o $(OBJ)alumno.o	
limpiar:
	rm $(OBJ)*.o
