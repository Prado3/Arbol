#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "alumno.h"
#include "lista.h"
#include "arbol.h"
#define ARCHI_ALUMNOS "alumno.dat"
#define ESC 27
#define DIM 30

void menu();
void cargarArchivo(char nombreArchivo[]);
void mostrarArchi(char nombreArchivo[]);
int cargarArreglo(stAlumno alumno[], int dim);
void mostrarArreglo(stAlumno alumno[],int v);

int main()
{

    menu();
    return 0;
}

void menu(){
    char op;
    int opMenu = 0;
    stAlumno alumnos[DIM];
    int v=0;
    nodo* lista=inicLista();
    nodo* menor=inicLista();
    int can=0;
    int sum=0;
    float promedio=0;
    nodoArbol* arbol = inicArbol();
    do{
        system("cls");
        opMenu = opcionesMenu();
        switch(opMenu){
        case 1:
            cargarArchivo(ARCHI_ALUMNOS);
            break;
        case 2:
            mostrarArchi(ARCHI_ALUMNOS);
            break;
        case 3:
            v=cargarArreglo(alumnos,DIM);
            break;
        case 4:
            mostrarArreglo(alumnos,v);
            break;
        case 5:
            lista = archivo2ListaOrdenada(lista,ARCHI_ALUMNOS);
            break;
        case 6:
            mostrarLista(lista);
            break;
        case 7:
            can = contarListaRecursiva(lista);
            printf("\n la cantidad es: %d", can);
            break;
        case 8:
            sum = sumaListaRecursiva(lista);
            printf("\n la suma es: %d", sum);
            promedio=(float)sum/(float)can;
            printf("\n el promedio de edad es: %.2f", promedio);
            break;
        case 9:
            menor = buscarMenorRecursivo(lista);
            mostrarAlumno(menor->dato);
            break;
        case 10:
            arbol = lista2arbol(arbol,lista);
            break;
        case 11:
            preorder(arbol);
            break;
        }

    printf("\n Ingrese ESC para salir..");
    printf("\n Ingrese ENTER para ver las opciones nuevamente");
    op=getch();
    }while(op!=ESC);
}

int opcionesMenu(){
    int i=0;
    printf("\n =====================================");
    printf("\n 1 = cargar archivo");
    printf("\n 2 = mostrar archivo");
    printf("\n 3 = cargar arreglo");
    printf("\n 4 = mostrar arreglo");
    printf("\n 5 = archivo a lista en forma ordenada por dni");
    printf("\n 6 = mostrar lsita recursivo");
    printf("\n 7 = contar alumnos");
    printf("\n 8 = sumar edad alumnos");
    printf("\n 9 = buscar menor recursivo");
    printf("\n 10 = pasar lista a arbol");
    printf("\n 11 = mostrar arbol (preorder)");
    printf("\n =====================================");
    printf("\n Inserte la opcion a elegir: ");
    scanf("%d",&i);
    return i;
}

void cargarArchivo(char nombreArchivo[]){
    stAlumno alumno;
    char op;
    FILE* archi = fopen(nombreArchivo,"a+b");
    if(archi){
        do{
        alumno = cargarAlumno();
        fwrite(&alumno,sizeof(stAlumno),1,archi);
        printf("\n Ingrese ESC para dejar de cargar..");
        op=getch();
        }while(op!=ESC);
        fclose(archi);
    }
}

void mostrarArchi(char nombreArchivo[]){
    stAlumno alumno;
    FILE* archi=fopen(nombreArchivo,"rb");
    if(archi){
        while(fread(&alumno,sizeof(stAlumno),1,archi)>0){
            mostrarAlumno(alumno);
        }
        fclose(archi);
    }
}

int cargarArreglo(stAlumno alumno[], int dim){
    int i=0;
    for(i =0;i<dim;i++){
        alumno[i] = cargarAlumno();
    }

    return i;
}

void mostrarArreglo(stAlumno alumno[],int v){
    for(int i = 0;i<v;i++){
        mostrarAlumno(alumno[i]);
    }
}
