//ÁLVARO CASTRO VALVERDE PB3 70926103Z
#include <stdio.h>
#include <string.h>
#ifdef ALUM
	#include "alumno.h"
	typedef tAlumno tipoReg;
#endif
#ifdef ASIG
	#include "asignatura.h"
	typedef  tAsignatura tipoReg;
#endif
#ifndef __DISPERSION_H
#define __DISPERSION_H
typedef struct {
	int nCubos;		// N�mero de cubos en el area prima (>8)
	int nCubosDes;		// N�mero de cubos area de desborde (>4)
	int nCuboDesAct; 	// N�mero del primer cubo desborde con espacio para m�s registros
	float densidadMax;	// M�xima densidad de ocupaci�n permitida
	float densidadMin;	// M�nima densidad de ocupaci�n permitida
	int numReg;		// N�mero total de registros en el archivo
	int numRegDes;		// N�mero de registros desbordados
} regConfig;
typedef struct {
	tipoReg reg[C];
	int numRegAsignados;
	int desbordado;	// Este campo indica si el cubo se ha desbordado(1) o no(0)
	} tipoCubo;
typedef struct {
	int cubo;	// N�mero de cubo asginado a un registro
	int cuboDes;	// N�mero de cubo en que se encuentra si se ha desbordado, -1 en otro caso
	int posReg;	// Posici�n del registro en el cubo
	} tPosicion;	
// Funci�n proporcionada
int leeHash(char *fichHash);
// Funciones a codificar
// Parte 1. Funciones gen�ricas para la creaci�n de ficheros
int creaHvacio(char *fichHash,regConfig *reg);
int creaHash(char *fichEntrada,char *fichHash, regConfig *regC);
int insertar(FILE *f, tipoReg *reg, regConfig *regC);
int desborde(FILE *fHash,tipoReg *reg, regConfig *regC);
// Parte 2. Funciones gen�rcias para el acceso a los ficheros
int busquedaHash(FILE *fHash, tipoReg *reg, tPosicion *posicion); 
int modificarReg(FILE *fHash, tipoReg *reg, tPosicion *posicion);
#endif

