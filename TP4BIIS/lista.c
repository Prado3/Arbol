#include "lista.h"
#include "alumno.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

nodo* crearNodo(stAlumno alumno){
    nodo* nuevoNodo = (nodo*) malloc(sizeof(nodo));
    nuevoNodo->dato = alumno;
    nuevoNodo->sig = NULL;

    return nuevoNodo;
}

nodo* inicLista(){
    return NULL;
}

nodo* apilarAlPrincipio(nodo* lista, nodo* nuevo){
    nuevo->sig=lista;
    return nuevo;
}

nodo* agregarAlFinal(nodo* lista, nodo* nuevo){
    if(!lista){
       lista = nuevo;
    }else{
        nodo* ultimo = buscarUltimo(lista);
        ultimo->sig = nuevo;
    }
    return lista;
}

nodo* buscarUltimo(nodo* lista){
    nodo* aux = lista;

    while(aux->sig){
        aux = aux->sig;
    }

    return aux;
}

nodo * ordenarPorDni (nodo * lista, nodo * nuevo){
    if (!lista){
        lista=nuevo;
    }
    else{
        if(atoi(nuevo->dato.dni)<= atoi(lista->dato.dni)){
            lista=apilarAlPrincipio(lista, nuevo);
        }
        else{
            nodo* anterior=lista;
            nodo * auxiliar = lista -> sig;
            while (auxiliar && atoi(nuevo->dato.dni)>atoi(auxiliar->dato.dni)){
                anterior=auxiliar;
                auxiliar=auxiliar->sig;
            }
            nuevo->sig=auxiliar;
            anterior->sig=nuevo;
        }
    }


return lista;
}

nodo* archivo2ListaOrdenada(nodo* lista, char nombreArchi[]){
    stAlumno alumno;
    FILE* archi = fopen(nombreArchi,"rb");
    if(archi){
        while(fread(&alumno,sizeof(stAlumno),1,archi)>0){
            lista = ordenarPorDni(lista,crearNodo(alumno));
        }
        fclose(archi);
    }
    return lista;
}

void mostrarLista(nodo* lista){
    if(lista){
        mostrarAlumno(lista->dato);
        mostrarLista(lista->sig);
    }
}

int contarListaRecursiva(nodo* lista){
    int i=0;
    if(lista){
        i = 1 + contarListaRecursiva(lista->sig);
    }
    return i;
}

int sumaListaRecursiva(nodo* lista){
    int suma=0;
    if(lista){
        suma = lista->dato.edad + sumaListaRecursiva(lista->sig);
    }
    return suma;
}

int buscarMenorRecursivo(nodo* lista){
    nodo* menor = NULL;
    if(lista->sig){
        menor = buscarMenorRecursivo(lista->sig);
        if(menor->dato.edad>lista->dato.edad){
            menor=lista;
        }
    }else{
        menor=lista;
    }
    return menor;
}


