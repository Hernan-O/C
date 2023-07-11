#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
     char nombre[50];
     int edad;
} persona;


typedef struct {
     persona dato;
     struct nodoL * siguiente;
} nodoL;



nodoL* crearNodoL(persona A){
    nodoL* nuevo=(nodoL*)malloc(sizeof(nodoL));

    nuevo->dato=A;
    nuevo->siguiente=NULL;
    return nuevo;
}

nodoL* agregarPrimeroL(nodoL* lista,nodoL* nuevo)
{
    if(lista==NULL)
        {
            lista = nuevo;
        }
    else
        {
            nuevo -> siguiente = lista;
            lista = nuevo;
        }
    return lista;
}

persona cargarPersona()
{
    persona aux;
    printf("Cargue la persona.\n");
    fflush(stdin);
    gets(&aux.nombre);
    printf("Cargue la edad de la misma.\n");
    scanf("%d",&aux.edad);

return aux;
}

nodoL* cargarListaL(nodoL* lista)
{
    char continuar='s';
    while(continuar=='s'){
        persona aux;
        nodoL* nodoAux;

        aux = cargarPersona();
        nodoAux = crearNodoL(aux);
        lista = agregarPrimeroL(lista, nodoAux);

        printf("Desea seguir cargando nombres? s/n\n");
        fflush(stdin);
        scanf("%c",&continuar);
        system("cls");
    }
system("cls");
return lista;
}

nodoL* inicLista(nodoL* lista) //Dirige el puntero a NULL
{
    lista = NULL;

return lista;
}

void mostrarPersonaL(persona dato)
{
    printf("------------------------\n");
    printf("edad: %i\n",dato.edad);
    printf("nombre: %s\n",&dato.nombre);
    printf("------------------------\n");

}

void mostrarListaL(nodoL* lista)
{
    nodoL* seguidora = lista;
    while(seguidora!=NULL)
        {
        mostrarPersonaL(seguidora->dato);
        seguidora = seguidora -> siguiente;
        }
}


int buscarDatoEnLista(nodoL *lista, char nombre[]){

 nodoL* seguidora = lista;
 int flag = 0;

    while(seguidora!=NULL && flag==0)
        {
           if(strcmpi(seguidora->dato.nombre,nombre)!=0)
           {
              seguidora=seguidora->siguiente;

           }else{

             flag = 1;
           }
        }
    return flag;
}



void cargarArchivo(char nombrearchivo[] , persona personita)
{
FILE* arch=fopen(nombrearchivo,"wb");

if(arch!=NULL){
  fwrite(&personita,sizeof(persona),1,arch);
  personita = cargarPersona(personita);
  fwrite(&personita,sizeof(persona),1,arch);
  personita = cargarPersona(personita);
  fwrite(&personita,sizeof(persona),1,arch);
 }
fclose(arch);
}


nodoL* archivoALista(char nombrearchivo[], nodoL* lista)
 {
    FILE* arch=fopen(nombrearchivo,"rb");
    persona personita;
    nodoL* aux;
    if(arch!=NULL){

      while(fread(&personita,sizeof(persona),1,arch)>0){

        aux = crearNodoL(personita);

        lista = agregarPrimeroL(lista,aux);

      }
    }fclose(arch);
  return lista;
 }


void mostrarArchivo(char nombrearchivo[])
{
    FILE* arch=fopen(nombrearchivo,"rb");
    persona personaa;

    if(arch!=NULL)
        {
          while(fread(&personaa,sizeof(persona),1,arch)>0)
          {
           mostrarPersonaL(personaa);
          }
        }fclose(arch);
}
nodoL* buscarElUltimoL(nodoL* lista)
{
    nodoL* ultimo = lista;
    if (lista!=NULL)
        {
            while(ultimo->siguiente!=NULL)
            {
                ultimo = ultimo->siguiente;
            }
        }
    return ultimo;
}

nodoL* agregarAlFinal(nodoL* lista,nodoL* nuevo)
{

    if(lista==NULL)
        {
            lista = nuevo;
        }
    else
        {
            nodoL* ultimo = lista;
            ultimo = buscarElUltimoL(lista);
            ultimo->siguiente = nuevo;
        }
    return lista;
}

nodoL* buscarDato(nodoL*lista,char nombreBusc[])
{
    nodoL* seguidora = lista;

    while(seguidora!=NULL && strcmpi(seguidora->dato.nombre,nombreBusc)!=0)
        {
        seguidora=seguidora->siguiente;
        }

    return seguidora;
}

nodoL* DatosIntercalados(nodoL* Nuevo,nodoL* lista1,nodoL* lista2)
{
    nodoL* aux;
    inicLista(aux);

    printf("Entrando bucle!\n");

    while(lista1!=NULL || lista2!=NULL)
        {
            if(lista1==NULL && lista2!=NULL)
                {
                    aux = lista2;
                    lista2 = lista2->siguiente;
                    printf(" aun mas rar232323o!\n");
                }


            else if(lista2==NULL && lista1!=NULL)
                {
                    aux = lista1;
                    lista1 = lista1->siguiente;
                    printf(" aun mas raro!\n");
                }

            else if(lista1->dato.edad > lista2->dato.edad)
                {
                    aux = lista2;
                    printf(" Menor!\n");
                    lista2 = lista2->siguiente;

                }
            else
                {
                    aux=lista1;
                    lista2 = lista2->siguiente;
                    printf(" Mayor!\n");
                }



        Nuevo=agregarAlFinal(Nuevo,aux);
        aux->siguiente=NULL;
        }

return Nuevo;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    system("COLOR DF");
    nodoL* lista;
    nodoL* lista2;
    nodoL* Nuevo;

    persona Ejemplo;

    int flag;

    char nombre[500];



    lista = inicLista(lista);
    lista2 = inicLista(lista2);
    Nuevo = inicLista(Nuevo);

    Ejemplo = cargarPersona(Ejemplo);
    cargarArchivo("archivochiquito",Ejemplo);
    Ejemplo = cargarPersona(Ejemplo);
    cargarArchivo("archivochiquito2",Ejemplo);
    mostrarArchivo("archivochiquito");


    lista2 = cargarListaL(lista2);



    lista2 = archivoALista("archivochiquito" , lista2);
    lista = archivoALista("archivochiquito2" , lista);

    lista2 = crearNodoL(Ejemplo);

    agregarAlFinal(lista2,lista);

    printf("Lista 1:\n");
    mostrarListaL(lista);
    printf("\n\nLista 2:\n");
    mostrarListaL(lista2);


    /*printf("que nombre desea buscar!?!?!?!? \n");             //Ejercicio 3!
    fflush(stdin);
    gets(nombre);
    flag = buscarDatoEnLista(lista,nombre);
    printf("el flag es: %d\n",flag);
    */

    system("pause");
    system("cls");

    /*Nuevo = DatosIntercalados(Nuevo,lista,lista2);

    mostrarListaL(Nuevo);*/

    printf("---------------------\n");
    printf("  FINAL DE FINALES!\n");
    printf("---------------------\n");
return 0;
}


/*nodoL* borrarElUltimoDatoConocidoDeLaListaQueEstuvimosUsandoYNoLoQuieroMas(nodoL* lista)
{
    if(lista!=NULL)
        {
         if(strcmp(nombre, lista->dato.nombre))
           nodoL* aBorrar = lista;
           lista = lista->siguiente;
           free(aBorrar);
        }
    else
        {
         nodoL* ante = lista;
         nodoL* seg = lista->siguiente;
         while((seg!=NULL) && (strcmp(strcmp(nombre, seg->dato.nombre)!=0)){
         ante = seg;
         seg = seg->siguiente;

        }
         if(seg!=NULL)
         {
          ante->siguiente = seg->siguiente;
           free(seg);
         }
}
///////////////////////////////////////////////////////////////////////////////
/*nodoL * agregarEnOrden(nodoL*lista, nodoL*nuevoNodo)
{

 if(lista==NULL)
 {

  lista = nuevoNodo;


  else
  {
     if(nuevoNodo->dato < lista->dato)
     {


     }
  }

else{
 nodoL * ante = lista;
 nodoL * seg = lista->siguiente;
  while((seg!=NULL) && (nuevoNodo->dato >= seg->dato))
  {
   ante = seg;
   seg = seg->siguiente;
  }
  nuevoNodo->siguiente = seg;
  ante->siguiente = nuevoNodo;
}
return lista;
}
*/
