#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

typedef struct{
    char nombre[30];
    char dni[12];
    int edad;
}stAlumno;

stAlumno cargarAlumno();
void mostrarAlumno(stAlumno alumno);

#endif // ALUMNO_H_INCLUDED
