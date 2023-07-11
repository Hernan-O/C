#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[20];
    char apellido [20];
    char dni[10];
    int edad;
    char genero;
    int cantMateriasAprobadas; /// total de materias aprobadas del estudiante en lacarrera (máximo 20)
    float promedioSinAplazos; /// indica el promedio de estudiante, sin tener en cuenta aplazos float
    float promedioConAplazos; /// indica el promedio de estudiante, teniendo encuenta aplazos
}estudiante;

typedef struct nodoEstudiante
{
    estudiante persona;
    struct nodoEstudiante* siguiente;
}nodoEstudiante;


nodoEstudiante* inicListaEstudiante (nodoEstudiante* lista);


int main()
{
    nodoEstudiante* lista = inicListaEstudiante(lista);

    lista = inicListaEstudiante(lista);

    //lista = crearNodo(Alumno);


    return 0;
}

///Funciones Ejercicio 1:

nodoEstudiante* inicListaEstudiante (nodoEstudiante* lista)
{
    lista=NULL;

    return lista;
}

nodoEstudiante* archivitoALista(nodoEstudiante* lista)
{
    estudiante alumno;

    if("EstudiantesTUP"!=NULL)
    {
        fread(&alumno,sizeof(estudiante),1,"EstudiantesTUP");
        lista->persona=alumno;
        lista = lista->siguiente;
    }
    lista->siguiente=NULL;
return lista;
}

nodoEstudiante* crearNodo(estudiante A)
{
    nodoEstudiante* alumno = (nodoEstudiante*)malloc(sizeof(nodoEstudiante));
    alumno->persona=A;
    alumno->siguiente=NULL;

    return alumno;
}

nodoEstudiante* buscarFinal(nodoEstudiante* lista)
{
    nodoEstudiante* seg=lista;
    if(lista!=NULL)
    {
        while(seg->siguiente==NULL)
        {
            seg=seg->siguiente;
        }
    }
return seg;
}

nodoEstudiante* agregarAlFinal(nodoEstudiante* lista, nodoEstudiante* nuevo)
{
    nodoEstudiante* seg;

    if(lista==NULL)
    {
        lista = nuevo;
    }
    else
    {
        seg = buscarFinal(lista);
        seg->siguiente = nuevo;
    }
return lista;
}

///Funciones Ejercicio 2:
void mostrarEstudiante(estudiante estud)
{
    printf("----------------------\n");
    printf("Legajo: %d\n",estud.legajo);
    printf("Nombre: %s\n",estud.nombre);
    printf("Apellido: %s\n",estud.apellido);
    printf("DNI: %d\n",estud.dni);
    printf("Edad: %d\n",estud.edad);
    printf("Genero: %c\n",estud.genero);
    printf("Cantidad de materias APROBADAS: %d\n",estud.cantMateriasAprobadas);
    printf("Promedio de materias Sin Aplazos: %f\n",estud.promedioSinAplazos);
    printf("Promedio de materias CON aplazos: %f\n",estud.promedioConAplazos);
    printf("----------------------\n");
}

void mostrarLista(nodoEstudiante* lista)
{
    if(lista!=NULL)
    {
        nodoEstudiante* seg = lista;
        while(seg!=NULL)
            {

                mostrarEstudiante(seg->persona);
                seg = seg->siguiente;
            }
    }
}

///Funciones Ejercicio3:
float cantidadDeAlumnos(nodoEstudiante* lista)
{
    float cantidad;
    nodoEstudiante* seg = lista;
    while(seg->siguiente!=NULL)
    {
        seg = seg->siguiente;
        cantidad++;
    }
return cantidad;
}

float cantidadAlumnosAplazo(nodoEstudiante* lista, int cantidad)
{
    nodoEstudiante* seg = lista;
    float cantidadSup = 0;        ///El promedio a superar es de 5

    for(int i = 0;i<cantidad;i++)
    {
        if(5<seg->persona.promedioConAplazos);      ///Si el promedio es mayor a 5 entrará al if
        {
            cantidadSup++;
        }
    seg = seg->siguiente;
    }
return cantidadSup;
}

void porcentajeProm(nodoEstudiante* lista)
{
    float cantidad,cantidadProm,porcentaje;

    nodoEstudiante* seg = lista;

    cantidad = cantidadDeAlumnos(seg);

    printf("La cantidad total de alumnos es: %f\n",cantidad);

    cantidadProm = cantidadAlumnosAplazo(seg,cantidad);

    printf("La cantidad de alumnos con promedio superior a 5 es: %f\n",cantidadProm);

    porcentaje = (cantidadProm/cantidad)*100;

    printf("El porcentaje de alumnos con promedio superior a 5 es: %f",porcentaje);
}
///Funciones Ejercicio 4:


