#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "alumno.h"
#include "lista.h"

typedef struct _nodoArbol{
    stAlumno dato;
    struct _nodoArbol* izq;
    struct _nodoArbol* der;
}nodoArbol;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(stAlumno dato);
nodoArbol* argregarArbol(nodoArbol* arbol, stAlumno dato);
void preorder(nodoArbol* arbol);
void inorder(nodoArbol* arbol);
void postorder(nodoArbol* arbol);
nodoArbol* buscar(nodoArbol* arbol, stAlumno dato);
nodoArbol* lista2arbol(nodoArbol* arbol, nodo* lista);

#endif // ARBOL_H_INCLUDED
