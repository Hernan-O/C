#include <stdio.h>
#include <stdlib.h>



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///Structs
typedef struct
{
    int dato;
    struct nodo* siguiente;
    struct nodo* anterior;
} nodo;

typedef struct
{
    nodo* primero;
    nodo* ultimo;
} Fila;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///Prototipados

nodo* inicLista();
nodo* CrearNodo(int dato);
nodo* encontrarUltimo(nodo* lista);
void agregarAlFinal(nodo** lista, nodo* aux);

void inicFila7u7(Fila * fila);
void agregarF(Fila * fila, int dato);
void mostrarF(Fila fila);
int TopEwE(Fila fila);
int filaVacia(Fila fila);
void leerF(Fila* fila);
int extraerF(Fila *fila);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///Main
int main()
{
    Fila* romagnoli;
    romagnoli = inicFila7u7(romagnoli);

    int perez = 0;

    perez = filaVacia(romagnoli);

    printf("%d 0=FilaVacia 1=FilaVacian't", &perez);

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///Funciones

nodo* inicLista()
{
    return NULL;
}

nodo* CrearNodo(int dato)
{
    nodo* aux = (nodo*)malloc(sizeof(nodo));

    aux->anterior = inicLista();
    aux->siguiente = inicLista();
    aux->dato = dato;

    return aux;
}

nodo* encontrarUltimo(nodo* lista)
{
    while(lista->siguiente != NULL)
    {
        lista = lista->siguiente;
    }
    return lista;
}

void agregarAlFinal(nodo** lista, nodo* aux)
{
    if(*lista == NULL)
    {
        *lista = aux;
    }
    else
    {
        nodo* ultimo = encontrarUltimo(*lista);

        ultimo->siguiente = aux;
        aux->anterior = ultimo;
    }
}


void inicFila7u7(Fila * fila)
{
    fila->primero = inicLista();
    fila->ultimo = inicLista();
}

void agregarF(Fila * fila, int dato)
{
    nodo* add = CrearNodo(dato);

    if(fila->primero == NULL)
    {
        agregarAlFinal(&(fila->primero), add);
        fila->ultimo = fila->primero;
    }
    else
    {
        fila->ultimo->siguiente = add;
        add->anterior = fila->ultimo;
        fila->ultimo = add;
    }

}

void mostrarF(Fila fila)
{
    nodo* seg = fila.ultimo;
    printf("\nPrimero_________________Ultimo\n\n");
    while(seg != NULL)
    {
        printf("| %d | ", seg->dato);
        seg = seg->anterior;
    }
    printf("\n\Primero________________Ultimo\n");
}

int TopEwE(Fila fila)
{
    return fila.primero->dato;
}

int filaVacia(Fila fila)
{
    int flag = 0;
    if(fila.primero == NULL)
    {
        flag = 1;
    }
return flag;
}

void leerF(Fila* fila)
{
    char cont = 's';
    int dato;
    nodo* aux;

    while(cont == 's' || cont == 'S')
    {
        printf("\nQue numero desea agregar: ");
        scanf("%d", &dato);

        aux = CrearNodo(dato);

        agregarF(fila, dato);

        printf("\nQuiere agregar mas numeros? (s/n) ");
        fflush(stdin);
        cont = getch();
    }
}

int extraerF(Fila *fila)
{
    int resto = NULL;
    nodo* aux;
    if(fila->primero != NULL)
    {
        if(fila->primero == fila->ultimo)
        {
            fila->ultimo = fila->primero->siguiente;
            fila->ultimo->anterior = NULL;
        }

        aux = fila->primero;
        resto = fila->primero->dato;
        fila->primero = fila->primero->siguiente;
        fila->primero->anterior = NULL;

        free(aux);
    }
    return resto;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
