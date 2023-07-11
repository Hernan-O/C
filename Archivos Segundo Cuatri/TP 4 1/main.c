#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreriaListas.h"
#include "libreriaListas.c"
///En principio lista apunta a NULL,

/// |lista| - > NULL.

/// + 1 NODO... Luego de agregar uno, lista apunta al nuevo nodo y ese nodo apunta a NULL

/// |lista|-> nodo.1 -> NULL

/// + 1 NODO... Lista apunta al nuevo nodo y ese nuevo apunta al que apuntaba lista.

/// |lista|-> nodo.2 -> nodo.1 -> NULL

///------------------------------------------------------ TP 4----------------------------------------------------------------------///
nodoL* archivoAListaOrdenado(nodoL* lista,FILE* archivo);
nodoL* archivoALista(nodoL* lista,FILE * archivo);
int buscarDatoFlag(nodoL* lista,char nombreBusc[]);
nodoL* ordenListas(nodoL* listaA,nodoL* listaB);

void mostrarArchivoPersona(FILE *archivo)
{
    Persona aux;

    while(fread(&aux,sizeof(Persona),1,archivo)>0)
    {
        printf("---------------------\n");
        printf("Nombre: %s\n",aux.nombre);
        printf("Edad: %i\n",aux.edad);
        printf("---------------------\n");
    }
}

int main()
{
    /* DEL 1 AL 4 FUNCIONADO
    Persona aux;
    int dato;

    nodoL* lista;
    lista=inicLista();

    nodoL* listaB;
    listaB=inicLista();

   FILE* archivo=fopen("datos","r+b");

    listaB=archivoAListaOrdenado(listaB,archivo);

    lista=archivoAListaOrdenado(lista,archivo);

    dato=buscarDatoFlag(lista,"Felipe");

   fclose(archivo);

   printf("Lista A:");
   mostrarListaL(lista);
   printf("---------------------------------------------------------\n");

   printf("\nLista B:");
   mostrarListaL(listaB);
   printf("---------------------------------------------------------\n");


   lista=ordenListas(lista,listaB);

   printf("Resultado:\n");
   mostrarListaL(lista);

    */
    int aux;

    nodoP* Pila;

    inicListaP(Pila);

    nodoP* dato;

    cargarEntero(&aux);

    dato=crearNodoP(aux);

    apilar(&Pila,dato);

    mostrarListaP(Pila);



return 0;
}

///PUNTO 1
nodoL* archivoALista(nodoL* lista,FILE * archivo)
{
    Persona aux;
    nodoL* nuevo;

    fseek(archivo,0,0);

    while(fread(&aux,sizeof(Persona),1,archivo)>0)
    {
        nuevo=crearNodoL(aux);
        lista=agregarPrimeroL(lista,nuevo);

    }
return lista;

}

///PUNTO 2
nodoL* archivoAListaOrdenado(nodoL* lista,FILE* archivo)
{
    Persona aux;
    nodoL* nuevo;


    fseek(archivo,0,0);

    while(fread(&aux,sizeof(Persona),1,archivo)>0)
    {
        nuevo = crearNodoL(aux);
        lista=agregarEnOrden(lista,nuevo);
    }
return lista;
}

///PUNTO 3
int buscarDatoFlag(nodoL* lista,char nombreBusc[])
{
    int flag;
    nodoL* seguidora=lista;

    while(seguidora!=NULL && strcmpi(seguidora->dato.nombre,nombreBusc)!=0)
    {
        seguidora=seguidora->siguiente;
    }

    if(seguidora==NULL)
    {
        flag=1;
    }else
    {
        flag=0;
    }

return flag;
}

///PUNTO 4
nodoL* ordenListas(nodoL* listaA,nodoL* listaB)
{
    nodoL* listaC;
    listaC=inicLista();

    nodoL* auxA; ///NO ESTOY CREANDO UN NODO

    while(listaA!=NULL && listaB!=NULL)
    {
        if(listaA->dato.edad<listaB->dato.edad){

            auxA=listaA;

            listaA=listaA->siguiente;
        }else{
            auxA=listaB;

            listaB=listaB->siguiente;
        }
            auxA->siguiente=NULL;
            listaC=agregarAlFinal(listaC,auxA);
    }

    if(listaA!=NULL)
    {
        listaC=agregarAlFinal(listaC,listaA);
    }else if(listaB!=NULL)
    {
        listaC=agregarAlFinal(listaC,listaB);
    }
return listaC;
}

///PUNTO 5


























///-------------------------------------------------------------------///















