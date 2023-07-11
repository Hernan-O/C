#ifndef LIBRERIALISTAS_H_INCLUDED
#define LIBRERIALISTAS_H_INCLUDED
typedef struct{
    char nombre[30];
    int edad;
}Persona;

typedef struct nodoL{ ///SE USA PARA QUE NO TIRE ERROR EN LA FILA 72 YA QUE NO DETECTA EL nodoL HASTA LA CREACION DEL MISMO EN LA SIGUIENTE LINEA.
    Persona dato;      ///Datos del nodo.
    struct nodoL* siguiente; ///Puntero al siguiente nodo.
}nodoL;

nodoL* inicLista();

nodoL* crearNodoL(Persona aux);

nodoL* agregarPrimeroL(nodoL* lista, nodoL* nuevo);

nodoL* cargarListaL(nodoL* lista);

void mostrarListaL(nodoL* lista);

nodoL* buscarUltimoL(nodoL* lista);

nodoL* agregarAlFinal(nodoL* lista,nodoL* nuevo);

nodoL* agregarEnOrden(nodoL *lista, nodoL* nuevoNodo);

nodoL* buscarDato(nodoL* lista,char nombreBusc[]);

#endif // LIBRERIALISTAS_H_INCLUDED
