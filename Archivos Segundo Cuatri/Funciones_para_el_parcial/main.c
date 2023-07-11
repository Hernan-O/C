#include <stdio.h>
#include <stdlib.h>
#include <string.h>


///Structs

typedef struct
{
 int id;
 char nombreCanal[40];
 char rubro[30];            //los rubros de juegos a los que se dedica cada canal son (y estan escritos                                // tal cual: “fantasia","creativos","accion","aventura","retro","construccion"
 int cantSuscriptores;      //cant suscript total del canal
 int cantVistasSemestre;    //cant de vistas que recibieron sus videos en el último semestre
} stYoutuber;

typedef struct nodoS                ///Simplemente enlazada
{
    stYoutuber dato;
    struct nodoS* siguiente;
}nodoS;

typedef struct nodoD                ///Doblemente enlazada
{
    stYoutuber dato;
    struct nodoD* siguiente;
    struct nodoD* anterior;
}nodoD;


///prototipados

void mostrarListaS(nodoS* lista);
nodoS* inicLista();
nodoD* inicListaD();
nodoS* crearNodoS(stYoutuber A);
void agregarFinal(nodoS** lista, nodoS* nuevo);
void agregarPrimero(nodoS **lista,nodoS *nuevo);
void archivoALista(nodoS** lista);
void mostrarYoutubers(stYoutuber Yt);
void mostrarYoutubersRecu(nodoS* lista);
nodoD* crearNodoD(nodoD *nuevo,stYoutuber dat);
nodoD* pasajeListaDoble(nodoS** lista, char rubroL[]);
void mostrarYoutubersRecuD(nodoD* lista);
nodoD* BuscarMayorSubs(nodoD * listaD, nodoD* mayorSubs);
float MayorNroSubsPlus(nodoD * lista);


///main

int main()
{
    nodoS* lista;
    nodoD* lista2;

    int idmodi = 0;
    int nuevasvistas = 0;

    system("COLOR DB");
    lista = inicLista();

    ///Ej 1
    printf("Ejercicio 1\n");
    archivoALista(&lista);
    system("pause");
    ///Ej 2
    printf("Ejercicio 2\n");
    mostrarYoutubersRecu(lista);
    system("pause");
    system("cls");

    ///Ej 3
    printf("Ejercicio 3\n");
    printf("Que Youtuber quiere modificar, elija su ID: ");
    scanf("%d",&idmodi);

    printf("\nCuantas vistas quiere ingresarle a novo muchacho: ");
    scanf("%d",&nuevasvistas);

    ModificarVistas(&lista,idmodi,nuevasvistas);

    mostrarYoutubersRecu(lista);
    system("pause");

    ///Ej 4
    printf("Ejercicio 4\n");
    char rubro[]="fantasia";
    lista2 = pasajeListaDoble(&lista,rubro);

    ///Ej 5
    printf("Ejercicio 5\n");

    //MostrarListaDoble(lista2);

    ///Ej 6
    printf("Ejercicio 6\n");

    float extra = MayorNroSubsPlus(lista2);

    printf("El Youtuber con mas subscriptores es: %s\n",lista2->dato.nombreCanal);
    printf("Tiene %d subscriptores\n",lista2->dato.cantSuscriptores);
    printf("Y el bono que recibirá es de: %f",extra);

}



///funciones

///Ej 1
nodoS* inicLista()
{
    return NULL;
}

nodoS* crearNodoS(stYoutuber A){

    nodoS* nuevo = (nodoS*)malloc(sizeof(nodoS));

    nuevo->dato=A;
    nuevo->siguiente=inicLista();

    return nuevo;
}

void agregarPrimero(nodoS **lista,nodoS *nuevo)
{
    if((*lista) == NULL)
    {
        (*lista) = nuevo;
    }
    else
    {
        nuevo->siguiente = (*lista);
        (*lista) = nuevo;
    }
}
nodoS* buscarElUltimoS(nodoS* lista)
{
    nodoS* ultimo = lista;
    if (lista!=NULL)
        {
            while(ultimo->siguiente!=NULL)
            {
                ultimo = ultimo->siguiente;
            }
        }
    return ultimo;
}

nodoS* agregarAlFinal(nodoS* lista,nodoS* nuevo)
{

    if(lista==NULL)
        {
            lista = nuevo;
        }
    else
        {
            nodoS* ultimo = lista;
            ultimo = buscarElUltimoS(lista);
            ultimo->siguiente = nuevo;
        }
    return lista;
}


void archivoALista(nodoS** lista)
 {
    FILE* arch = fopen("archivoYoutubers.bin","rb");
    nodoS* aux;
    stYoutuber personita;

    if(arch != NULL)
    {
      while(fread(&personita,sizeof(stYoutuber),1,arch) > 0)
      {
            aux = crearNodoS(personita);
            (*lista) = agregarAlFinal(*lista,aux);
            //mostrarYoutubers(personita);
      }
    fclose(arch);
    }
    else
    {
        printf("Error UwU\n");
    }
 }


///Ej 2
void mostrarYoutubers(stYoutuber Yt)
{
    printf("\n ***************************** YOUTUBER *********************************** \n");
    printf("Id del Youtuber..............................: %d ",Yt.id);
    printf("\nNombre del Canal...........................: %s ",Yt.nombreCanal);
    printf("\nRubro del Canal (tipo de juegos)...........: %s ",Yt.rubro);
    printf("\nCantidad de Suscriptores en miles..........: %d ",Yt.cantSuscriptores);
    printf("\nCantidad de vistas del semestre en miles..: %d \n\n",Yt.cantVistasSemestre);
}

void mostrarYoutubersRecu(nodoS* lista)
{
    if(lista==NULL)
    {
        printf("Final de la lista\n");
    }
    else
    {
        mostrarYoutubers(lista->dato);
        mostrarYoutubersRecu(lista->siguiente);
    }
}

///Ej 3

nodoS* BuscarPorId(nodoS* lista, int id)
{
    if(lista != NULL && lista->dato.id != id)
    {
        lista = BuscarPorId(lista->siguiente, id);
    }

    return lista;
}

void ModificarVistas(nodoS** lista, int id, int nuevoDato)
{
    nodoS* buscado = BuscarPorId(*lista, id);

    buscado->dato.cantVistasSemestre = nuevoDato;
}
///Ej 4

nodoD* inicListaD()
{
    return NULL;
}

nodoD* crearNodoD(nodoD *nuevo,stYoutuber dat)
{
    nodoD* nuevoD = (nodoD*)malloc(sizeof(nodoD));

    nuevoD->dato=dat;
    nuevoD->siguiente=inicLista();
    nuevoD->anterior=nuevoD;

    return nuevo;
}

nodoD* agregarPrimeroD(nodoD* lista,nodoD* nuevo)
{
    if(lista==NULL)
    {
        lista = nuevo;
    }
    else
    {
        nuevo->siguiente = lista;
        lista->anterior = nuevo;
        lista = nuevo;
    }
return lista;
}

void BorrarNodo(nodoS ** lista, nodoS * eliminar)
{
    if(*lista != NULL)
    {
        nodoS* aBorrar;
        if((*lista) == eliminar)
        {
            aBorrar = *lista;
            *lista = (*lista)->siguiente;
            free(aBorrar);
        }
        else
        {
            nodoS* seg = (*lista)->siguiente;
            nodoS* ante = *lista;

            while(seg != NULL && seg != eliminar)
            {
                ante = seg;
                seg = seg->siguiente;
            }

            if(seg == eliminar)
            {
                aBorrar = seg;
                ante->siguiente = seg->siguiente;
                free(aBorrar);
            }
        }
    }
}

nodoD* pasajeListaDoble(nodoS** lista, char rubroL[])
{
    nodoD* listaDoble = inicListaD();
    nodoD* aux;

    if(*lista != NULL)
    {
        if(strcmp((*lista)->dato.rubro, rubroL) == 0)
        {
            aux = crearNodoD(aux,(*lista)->dato);

            listaDoble = agregarPrimeroD(listaDoble, aux);

            BorrarNodo(lista, *lista);
        }

        nodoS* seg = (*lista)->siguiente;
        nodoS* ante = (*lista);

        while(seg != NULL)
        {
            if(strcmp(seg->dato.rubro, rubroL) == 0)
            {
                aux = crearNodoD(aux,seg->dato);

                listaDoble = agregarPrimeroD(listaDoble, aux);

                BorrarNodo(lista, seg);
            }

            ante = seg;
            seg = seg->siguiente;
        }
    }
return listaDoble;
}

///Ej 5

nodoD * BuscarNodoFinal(nodoD * lista)
{
    while(lista->siguiente != NULL)
    {
        lista = lista->siguiente;
    }
    return lista;
}

void MostrarListaDoble(nodoD * lista)
{
    nodoD* ultimo = BuscarNodoFinal(lista);
    while(ultimo != NULL)
    {
        mostrarYoutubers(ultimo->dato);
        ultimo = ultimo->anterior;
    }
}

///Ej 6

nodoD* BuscarMayorSubs(nodoD * listaD, nodoD* mayorSubs)
{
    if(listaD != NULL)
    {
        if(listaD->dato.cantSuscriptores > mayorSubs->dato.cantSuscriptores)
        {
            mayorSubs = BuscarMayorSubs(listaD->siguiente, listaD);
        }
        else
        {
            mayorSubs = BuscarMayorSubs(listaD->siguiente, mayorSubs);
        }
    }
    return mayorSubs;
}

float MayorNroSubsPlus(nodoD * lista)
{
    nodoD* mayorSubs = BuscarMayorSubs(lista->siguiente, lista);

    float plus = (mayorSubs->dato.cantSuscriptores) * 0.2;

    return plus;
}
