#include "alumno.h"
#include <stdio.h>
#include <stdlib.h>

stAlumno cargarAlumno(){
    stAlumno alumno;

    printf("\n Ingrese el nombre: ");
    fflush(stdin);
    gets(alumno.nombre);

    printf("\n Ingrese el dni: ");
    fflush(stdin);
    gets(alumno.dni);

    printf("\n Ingrese la edad: ");
    scanf("%d", &alumno.edad);

    return alumno;
}

void mostrarAlumno(stAlumno alumno){
    printf("\n ==============================");
    printf("\n Nombre:...: %s",alumno.nombre);
    printf("\n Dni:......: %s",alumno.dni);
    printf("\n Edad:.....: %d",alumno.edad);
    printf("\n ==============================");
}
