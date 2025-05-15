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
	int nCubos;		// Número de cubos en el area prima (>8)
	int nCubosDes;		// Número de cubos area de desborde (>4)
	int nCuboDesAct; 	// Número del primer cubo desborde con espacio para más registros
	float densidadMax;	// Máxima densidad de ocupación permitida
	float densidadMin;	// Mínima densidad de ocupación permitida
	int numReg;		// Número total de registros en el archivo
	int numRegDes;		// Número de registros desbordados
} regConfig;
typedef struct {
	tipoReg reg[C];
	int numRegAsignados;
	int desbordado;	// Este campo indica si el cubo se ha desbordado(1) o no(0)
	} tipoCubo;
typedef struct {
	int cubo;	// Número de cubo asginado a un registro
	int cuboDes;	// Número de cubo en que se encuentra si se ha desbordado, -1 en otro caso
	int posReg;	// Posición del registro en el cubo
	} tPosicion;	
// Función proporcionada
int leeHash(char *fichHash);
// Funciones a codificar
// Parte 1. Funciones genéricas para la creación de ficheros
int creaHvacio(char *fichHash,regConfig *reg);
int creaHash(char *fichEntrada,char *fichHash, regConfig *regC);
int insertar(FILE *f, tipoReg *reg, regConfig *regC);
int desborde(FILE *fHash,tipoReg *reg, regConfig *regC);
// Parte 2. Funciones genércias para el acceso a los ficheros
int busquedaHash(FILE *fHash, tipoReg *reg, tPosicion *posicion); 
int modificarReg(FILE *fHash, tipoReg *reg, tPosicion *posicion);
#endif

