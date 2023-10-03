#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "alumno.h"

typedef struct _nodo{
    stAlumno dato;
    struct _nodo* sig;
}nodo;

nodo* buscarUltimo(nodo* lista);
void mostrarLista(nodo* lista);
nodo* archivo2ListaOrdenada(nodo* lista, char nombreArchi[]);
nodo* ordenarPorDni(nodo* lista,nodo* nuevo);
nodo* agregarAlFinal(nodo* lista, nodo* nuevo);
nodo* apilarAlPrincipio(nodo* lista, nodo* nuevo);
nodo* inicLista();
nodo* crearNodo(stAlumno alumno);
int contarListaRecursiva(nodo* lista);
int sumaListaRecursiva(nodo* lista);
int buscarMenorRecursivo(nodo* lista);

#endif // LISTA_H_INCLUDED
