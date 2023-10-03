#include "arbol.h"

nodoArbol* inicArbol(){
    return NULL;
}

nodoArbol* crearNodoArbol(stAlumno dato){
    nodoArbol* nuevo = (nodoArbol*) malloc(sizeof(nodoArbol));
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

nodoArbol* argregarArbol(nodoArbol* arbol, stAlumno dato){
    if(!arbol){
        arbol = crearNodoArbol(dato);
    }else{
        if(dato.edad>arbol->dato.edad){
            arbol->der = argregarArbol(arbol->der,dato);
        }else{
            if(dato.edad!=arbol->dato.edad){
                arbol->izq = argregarArbol(arbol->izq,dato);
            }
        }
    }
    return arbol;
}

void preorder(nodoArbol* arbol){
    if(arbol){
       mostrarAlumno(arbol->dato);
       preorder(arbol->izq);
       preorder(arbol->der);
    }
}

void inorder(nodoArbol* arbol){
    if(arbol){
       inorder(arbol->izq);
       mostrarAlumno(arbol->dato);
       inorder(arbol->der);
    }
}

void postorder(nodoArbol* arbol){
    if(arbol){
        postorder(arbol->izq);
        postorder(arbol->der);
        mostrarAlumno(arbol->dato);
    }
}

nodoArbol* buscar(nodoArbol* arbol, stAlumno dato){
    nodoArbol* rta = NULL;
    if(!arbol){
        if(dato.edad == arbol->dato.edad){
            rta = arbol;
        }else{
            if(dato.edad>arbol->dato.edad){
                rta = buscar(arbol->der,dato);
            }else{
                rta = buscar(arbol->izq,dato);
            }
        }
    }
    return rta;
}

nodoArbol* lista2arbol(nodoArbol* arbol, nodo* lista){
    while(lista){
        arbol = argregarArbol(arbol,lista->dato);
        lista = lista->sig;
    }
    return arbol;
}
