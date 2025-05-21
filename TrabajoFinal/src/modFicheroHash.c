#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include "../include/dispersion.h"

int main()
{

#ifdef ALUM
	leeHash("../datos/alumnosC.hash");
	char dni[9];
    printf("Introduce DNI del alumno a buscar: ");
    scanf("%s", dni);

    int res = buscar("../datos/alumnosC.hash", dni);

    if (res == 0)
        printf("Registro encontrado.\n");
    else if (res == -1)
        printf("Registro no encontrado.\n");
    else
        printf("Error (%d) durante la búsqueda.\n", res);

    return 0;

#endif
#ifdef ASIG
	leeHash("../datos/asignaturasC.hash");
	int codigo;
    printf("Introduce el codigo de la asignatura a buscar: ");
    scanf("%d", &codigo);

    int res = buscar("../datos/asignaturasC.hash", codigo);

    if (res == 0)
        printf("Registro encontrado.\n");
    else if (res == -1)
        printf("Registro no encontrado.\n");
    else
        printf("Error (%d) durante la búsqueda.\n", res);

    return 0;
#endif

}
