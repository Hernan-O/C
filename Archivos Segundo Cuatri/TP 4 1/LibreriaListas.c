#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreriaListas.h"

///-----------Personas

Persona cargarPersona()
{
    Persona aux;

    printf("Ingrese el nombre\n");
    fflush(stdin);
    gets(aux.nombre);

    printf("Ingrese edad\n");
    fflush(stdin);

    scanf("%i",&aux.edad);

return aux;
}

void mostrarPersonaL(Persona aux)
{
    printf("------------------\n");
    printf("Nombre: %s\n",aux.nombre);
    printf("Edad: %i\n",aux.edad);
    printf("------------------\n");

}

///------------NODOS

nodoL* inicLista() ///IGUAL QUE LA DE ARRIBA PERO MAS OPTIMIZADA.
{
    return NULL;
}

nodoL* crearNodoL(Persona aux)  ///(Con memoria dinamica usamos MALLOC)
{
    nodoL * nuevo=(nodoL*)malloc(sizeof(nodoL)); ///Dedicamos el espacio de memoria

    nuevo->dato=aux;
    nuevo->siguiente=NULL; ///Direcc de memoria del nodo siguiente.

return nuevo;
}

nodoL* agregarPrimeroL(nodoL* lista, nodoL* nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }else
    {
        nuevo->siguiente=lista;
        lista=nuevo; ///Redirecciono el puntero al nuevo nodo.
    }

return lista;
}

nodoL* cargarListaL(nodoL* lista)
{
    Persona aux;
    nodoL* nuevo;

    aux = cargarPersona();
    nuevo = crearNodoL(aux);
    lista=agregarPrimeroL(lista,nuevo);

return lista;
}

void mostrarListaL(nodoL* lista)
{
    nodoL* seguidora=lista;///HASTA NO TENERLA CLARA USAR SEGUIDORA PARA NO MODIFICAR EL PUNTERO A LA LISTA.

    while(seguidora!=NULL)
    {
        mostrarPersonaL(seguidora->dato);
        seguidora=seguidora->siguiente;
    }

}

nodoL* buscarUltimoL(nodoL* lista)   ///RETORNA LA DIRECC DE MEMORIA DEL ULTIMO NODO.
{
    nodoL* ultimo= lista;
    if(lista!=NULL)
    {
        while(ultimo->siguiente!=NULL)
        {
            ultimo=ultimo->siguiente;
        }
    }
return ultimo;
}

nodoL* agregarAlFinal(nodoL* lista,nodoL* nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;

    }else{
        nodoL* ultimo= buscarUltimoL(lista);
        ultimo->siguiente=nuevo;
    }

return lista; ///RETORNA LA LISTA POR SI NO TENIA NODOS POR LO QUE DEBE RETORNAR LA LISTA.
}

nodoL* buscarDato(nodoL* lista,char nombreBusc[])
{
    nodoL* seguidora=lista;

    while(seguidora!=NULL && strcmpi(seguidora->dato.nombre,nombreBusc)!=0)
    {
        seguidora=seguidora->siguiente;
    }

return seguidora;
}

nodoL* agregarEnOrden(nodoL* lista, nodoL* nuevoNodo)
{
    if(lista==NULL)  ///Si la lista esta vacia.
    {
        lista=nuevoNodo;
    }
    else ///Si no esta vacia.
    {
        if(nuevoNodo->dato.edad < lista->dato.edad)          ///Si debe ir 1ro
        {
            lista=agregarPrimeroL(lista,nuevoNodo);
        }else                                       ///En cualquier otro lugar que no sea el primero.
        {
            nodoL* ante=lista;
            nodoL* seg=lista->siguiente;
            while((seg!=NULL) && (nuevoNodo->dato.edad >= seg->dato.edad)) ///Se encuentra el espacio para insertar.
            {                                                   ///Con 2 punteros, seg(Seguidora) ante(Anterior)
                ante=seg;
                seg=seg->siguiente;
            }
            nuevoNodo->siguiente=seg; ///Se lleva a cabo el reemplazo con el lugar previamente encontrado.
            ante->siguiente=nuevoNodo;
        }
    }
return lista;
}

nodoL* borrarNodo(char nombre[20],nodoL* lista)///El nombre identifica al nodo
{
    if(lista!=NULL)
    {                   ///Si el buscado es el 1ro
        if(strcmp(nombre,lista->dato.nombre)==0)
        {
            nodoL* aBorrar=lista;
            lista=lista->siguiente;
            free(aBorrar);
                    ///Si lo busca no esta en el 1ro nodo
        }
        else
        {
            nodoL* ante=lista;
            nodoL* seg=lista->siguiente;

            while((seg!=NULL) && (strcmpi(nombre,seg->dato.nombre)!=0)) ///Mientras que no llegue al final o que encuentre el que quiere borrar
            {
                ante=seg;
                seg=seg->siguiente;
            }

            if(seg!=NULL)
            {
                ante->siguiente = seg->siguiente; ///bypass
                free(seg);
            }
        }
    }
return lista;
}




///PUNTO 6

///--------------------------TDA PILAS CON LISTAS (LIBRERIA DE LISTAS ADAPTADA CON ENTEROS)--------------------------------///
typedef struct nodoP{
    int dato;
    struct nodoP* siguiente;
}nodoP;

void cargarEntero(int* aux)
{
    printf("Ingrese entero\n");

    scanf("%i",aux);
}
void mostrarEnteroP(int aux)
{
    printf("|%i|",aux);
}

nodoP* inicListaP()
{
    return NULL;
}
nodoP* crearNodoP(int entero)
{
    nodoP * nuevo=(nodoP*)malloc(sizeof(nodoP));

    nuevo->dato=entero;
    nuevo->siguiente=NULL;

return nuevo;
}
void apilar(nodoP** lista, nodoP* nuevo)
{
    if((*lista)==NULL)
    {
        *lista=nuevo;
    }else
    {
        nuevo->siguiente=*lista;
        *lista=nuevo; ///Redirecciono el puntero al nuevo nodo.
    }
}
nodoP* cargarListaP(nodoP* lista)
{
    int aux;
    nodoP* nuevo;

    cargarEntero(&aux);
    nuevo = crearNodoP(aux);
    apilar(&lista,nuevo);

return lista;
}
void mostrarListaP(nodoP* lista)
{
    nodoP* seguidora=lista;///HASTA NO TENERLA CLARA USAR SEGUIDORA PARA NO MODIFICAR EL PUNTERO A LA LISTA.

    while(seguidora!=NULL)
    {
        mostrarEnteroP(seguidora->dato);
        //seguidora=seguidora->siguiente;
        lista = lista->siguiente;
        seguidora = lista;
    }

}
int desapilarP(nodoP* lista)
{
    nodoP* aux=lista;

    lista=lista->siguiente;

    int entero=aux->dato;

    return entero;
}
void leerP(nodoP** lista)
{
    nodoP* aux;
    int entero;
    cargarEntero(&entero);

    aux=crearNodoP(entero);

    apilar(lista,aux);

}
int topeP(nodoP* lista)
{
    int aux=lista->dato;
return aux;
}

///--------------------------TDA PILAS CON LISTAS EXPLICACION EN CLASE POR PROFE--------------------------------///

/// Forma Facil:

typedef struct nodo{
   int dato;
   struct nodo * siguiente;
}nodo;

typedef struct{
    nodo* lista;
}Pila;

void inicPila(Pila* A)
{
   // A->lista=NULL; /// NO ESTA MAL PERO PUEDE SER MEJOR

    A->lista=inicLista(); /// PORQUE APROVECHAS LAS FUCIONES DE LAS LIB.. DE LISTAS.
}

void apilar(Pila* A,int dato)
{

    nodoL* nuevo;
    nuevo=crearNodo(dato);

    A->lista=agregarPrimeroL(A->lista,nuevo);
}

void leer(Pila *A)
{
    int entero;

    printf("Ingrese algun dato\n");
    scanf("%i",&entero);

    apilar(A,entero);
}

int desapilar(Pila *A)
{
    int dato;

    dato=retornarPrimerDato(A); /// Funcion nueva para retorar el primer dato de una lista.

    A->lista=borrarElPrimero(A->lista);  ///Funcion modificada de borrar el primero

return dato;
}


int tope(Pila A)
{
   int dato;
   dato=retornarPrimerDato(A.lista);///retorna el primer dato.
return dato;
}

int pilavacia(Pila A)               /// Que pregunta??? 0=Falso 1=Verdadero.
{
    int flag=0;

    if(A.lista!=NULL)
    {
      flag=1;
    }
return flag; /// Si retorna 1 significa que esta vacia.
}

void mostrarPila(Pila A)
{
    Pila aux;
    inciPila(&aux);

    while(!pilavacia(A))
    {
        apilar(&aux,desapilar(&A));
    }

    printf("\nBase                      Tope\n");
    mostrarListaL(A.lista);
    printf("\nBase                      Tope\n");
}














































