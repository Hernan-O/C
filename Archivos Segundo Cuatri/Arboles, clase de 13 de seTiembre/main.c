#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///Structs
typedef struct
{
    int dato;
    struct nodoArbol *izq;
    struct nodoArbol *der;
}nodoArbol;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///Prototipados

nodoArbol *inicArbol();
nodoArbol* crearNodoArbol(int dato);
nodoArbol* buscar(nodoArbol* arbol,int dato);
nodoArbol* insertar(nodoArbol* arbol, int dato);
void preorder(nodoArbol* arbol);
void inorder(nodoArbol* arbol);
void postorder(nodoArbol* arbol);
nodoArbol* borrarArbolito(nodoArbol* arbol, int datoBus);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///Main

int main()
{
    nodoArbol* hola;
    hola = inicArbol();

    hola = crearNodoArbol(3);

    hola = insertar(hola,4);
    hola = insertar(hola,5);
    hola = insertar(hola,6);
    hola = insertar(hola,7);
    hola = insertar(hola,1);
    hola = insertar(hola,9);

    postorder(hola);

    hola = borrarArbolito(hola,7);

    printf("\nLuego de borrar el 5: \n");

    preorder(hola);


    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///Funciones
nodoArbol *inicArbol()
{
    return NULL;
}

nodoArbol* crearNodoArbol(int dato)
{
    nodoArbol* aux = (nodoArbol*)malloc(sizeof(nodoArbol));

    aux->dato = dato;
    aux->der = NULL;
    aux->izq = NULL;
}

nodoArbol* buscar(nodoArbol* arbol,int dato)
{
    nodoArbol* rta=NULL;
    if(arbol!=NULL)
    {
        if(dato == arbol->dato)
        {
            rta=arbol;
        }
        else
        {
            if(dato>arbol->dato)
            {
            rta = buscar(arbol->der, dato);
            }
            else
            {
                rta = buscar(arbol->izq, dato);
            }
        }
    }
return rta;
}

nodoArbol* insertar(nodoArbol* arbol, int datowo)
{
    if(arbol==NULL)
    {
        arbol = crearNodoArbol(datowo);
    }
    else
    {
        if(datowo > arbol->dato)
        {
            arbol->der = insertar(arbol->der,datowo);
        }
        else
        {
            arbol->izq = insertar(arbol->izq,datowo);
        }
    }
    return arbol;
}

void preorder(nodoArbol* arbol)
{
    if(arbol!=NULL)
    {
        printf("|%d",arbol->dato);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

void inorder(nodoArbol* arbol)
{
    if(arbol!=NULL)
    {
        inorder(arbol->izq);
        printf("|%d", arbol->dato);
        inorder(arbol->der);
    }
}
void postorder(nodoArbol* arbol)
{
    if(arbol!=NULL)
    {
        postorder(arbol->izq);
        postorder(arbol->der);
        printf("|%d", arbol->dato);
    }
}

nodoArbol* borrarArbolito(nodoArbol* arbol, int datoBus)         ///Funcion medio del bardo creo;
{
    nodoArbol* dereborro;
    nodoArbol* izquiborro;
    if (arbol == NULL)
    {
        return arbol;
    }
    else
    {
        if(arbol->dato == datoBus)          ///Si el dato aparece uwu;
        {
            if(arbol->izq!=NULL)
            {
                izquiborro->dato = arbol->dato;
                arbol->izq = borrarArbolito(arbol->izq,izquiborro->dato);
            }
            else if(arbol->der!=NULL)
            {
                dereborro->dato = arbol->dato;
                arbol->der = borrarArbolito(arbol->der,dereborro->dato);
            }
            else
            {
                free(arbol);
                arbol = NULL;
            }
        }
    ///Si el dato todavia no aparece!
        if(datoBus>arbol->dato)
        {
                arbol->der = borrarArbolito(arbol->der,datoBus);
        }
        if(datoBus<arbol->dato)
        {
                arbol->izq = borrarArbolito(arbol->izq,datoBus);
        }
    }
return arbol;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///Teoria
/*
Arboles TDA;

Arboles Binarios, tienen en disponibilidad 0, 1 Y 2!!!;          Raiz, Nodo Izq y Nodo Der;

Los arboles se tienen que inicializar tambien en NULL;

Punteros;

Todas las funciones parten de ver si el arbol está vacio o no (If(Arbol!=NULL));

El arbol binario completo es cuando el arbol está, balanceado, lleno y completo (Cada raiz tiene sus 2 hijitos :));

if(Padre == NULL) == Nodo Raiz;

if(Padre != NULL && Hijo != NULL)  == Nodo Rama;

if(Hijo == NULL) == Nodo Hoja;

Nivel: Aumenta a medida que aumenta la altura del arbolito;

Altura:Parte de la Raiz, y según su descendencia/dinastia se mide su altura;

Grado: Es la descendencia de cada nodo;

LA GRAN MAYORIA DE FUNCIONES VAN A SER RECURSIVAS!;

OJO AL PIOJO CON LO DE ARRIBA;

LEER LO QUE ESTÁ ARRIBA DE LO DE ARRIBA;

///Tres algoritmos clasicos;

-PreOrden: La raiz es lo que se muestra primero;
-InOrden: se muestra lo que esté en el medio;
-PostOrden: La raiz es lo que se muestra ultimo;
*/
