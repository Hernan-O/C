#include <stdio.h>
#include <stdlib.h>

typedef struct {
      char nombre[30];
      char genero;
      int edad;
}persona;

int cargarArregloPersona (persona arr[], int dim);


int main()
{
   persona Arreglo[30];
   int i=0;
   int j=0,validos=0;
   validos=cargarArregloPersona(Arreglo,30);

   mostrarArrPer(Arreglo, validos);
   system("pause");
   system("cls");
   copiaDatosDelGeneroEspecificoElegido(Arreglo,validos);



    return 0;
}

int cargarArregloPersona (persona arr[], int dim)
{
    char opc = 's';
    int i=0;

    while(i<dim && opc == 's')
    {
        printf("Ingrese nombre del humano\n");
        fflush(stdin);
        gets(arr[i].nombre);

        printf("Ingrese genero del humano\n");
        fflush(stdin);
        scanf("%c", &arr[i].genero);

        printf("Ingrese edad del humano\n");
        fflush(stdin);
        scanf("%i", &arr[i].edad);

        printf("Quiere ingresar otro humano?\n");
        fflush(stdin);
        scanf("%c", &opc);

        i++;
    }

    return i;
}

void mostrarArrPer (persona arr[], int val)
{
    for(int i=0; i<val; i++)
    {
         printf("--------------------------------\n");
         printf("El nombre del ser es: %s\n", arr[i].nombre);
        printf("se autopercibe como: %c\n", arr[i].genero);
        printf("su numero de tiempo en vida es: %i\n", arr[i].edad);
        printf("--------------------------------\n");

    }


}

int cuentaCantidadGeneros(persona arr[], int val)
{
    int i, j=0;
    char gen;

     printf("Que genero desea cuantificar?\n");
    fflush(stdin);
    scanf("%c", &gen);

    for(i=0; i<val; i++)
    {
        if(gen == arr[i].genero)
        {
            j=j+1;
        }
    }
    printf("%d",j);
    return j;
}


void copiaDatosDelGeneroEspecificoElegido(persona arr[],int validios)
{
   int j=0,i=0;
   j=cuentaCantidadGeneros(arr,validios);
    persona * arr2=(persona*)malloc(j*sizeof(persona));
    i=copiarConLosArreglosYaHechos(arr,arr2,validios);

    mostrarArrPer(arr2,i);

    insercionDeLaEdadDeLaAnteriorEstructura(arr2, i);
    printf("Despues de ordenar!\n");
    mostrarArrPer(arr2, i);


}

int copiarConLosArreglosYaHechos(persona arr[],persona arr2[],int val)
{
    int i, j=0;
    char gen;

     printf("Que genero desea cuantificar?\n");
    fflush(stdin);
    scanf("%c", &gen);

    for(i=0; i<val; i++)
    {
        if(gen == arr[i].genero)
        {
            arr2[j].edad=arr[i].edad;
            strcpy(arr2[j].nombre,arr[i].nombre);
            arr2[j].genero=arr[i].genero;
            j++;
        }
    }
return j;
}

void insercionDeLaEdadDeLaAnteriorEstructura(persona arr[],int val)
{
    int i=0,j=0;
    persona aux;

    while(j<val)
    {
        for(i=0; i<val-1; i++)
        {
            if(arr[i+1].edad < arr[i].edad)
            {
                aux.edad = arr[i].edad;
                aux.genero = arr[i].genero;
                strcpy(aux.nombre,arr[i].nombre);

                arr[i].edad = arr[i+1].edad;
                arr[i].genero = arr[i+1].genero;
                strcpy(arr[i].nombre,arr[i+1].nombre);

                arr[i+1].edad = aux.edad;
                arr[i+1].genero = aux.genero;
                strcpy(arr[i+1].nombre,aux.nombre);
            }
        }
        j++;
    }
}
