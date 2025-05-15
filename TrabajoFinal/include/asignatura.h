#ifndef __ASIGNATURA_H
#define __ASIGNATURA_H
#define C 6	        // Capacidad del cubo fichero asignaturas
typedef struct {
	int codigo;	// campo clave
	char nombre[60];
	char curso;
	float creditosT;
	float creditosP;
	char tipo;
	char cuatrimestre;
	int numGrT;
	int numGrP;
	} tAsignatura;
int funcionHash(tAsignatura *reg,int nCubos);
void mostrarReg(tAsignatura *reg);
int cmpClave(tAsignatura *reg1, tAsignatura *reg2);
int buscar(char *fichero, int codigo);
int modificar(char *fichero, int codigo,float creditosT, float creditosP);
#endif
