#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int arreglo[9];
    char Carreglo[5];
//    funciontotal(arreglo,9);    //EJEREJER1
    funcionMAXICRITICA(Carreglo,5);
}

promeprome()
{

}

void celdasMenosUno(int arr[], int dimension)
{
    int i=0;
    while(i<dimension){
        arr[i]=-1;
        i++;
    }


}

int cargaValoresXUsuario (int arr[], int dimension)
{
    int i=0;
     while(i < dimension)
     {
        printf("Ingrese el numero\n");
        scanf("%d",  &arr[i]);
        i++;
    }
 return i;
}

void mostrarArreglo (int arr[], int val)
{
    int i=0;
    while(i < val)
    {
        printf(" |%d| \n",arr[i]);
        i++;
    }
}

int sumaTotalArreglo (int arr[], int validos)
{
    int i=0,suma=0;

    while(i<validos)
    {
        suma=arr[i]+suma;
        i++;
    }
return suma;
}

int promiedo(int suma,int validos){
    int promeprome=suma/validos;

    printf("El promedio es %d", promeprome);

return promeprome;
}

void funciontotal(int arr[],int dimension){
    int promedio=0,validos=0,suma=0;
    celdasMenosUno(arr,dimension);
    validos=cargaValoresXUsuario(arr,dimension);
    mostrarArreglo(arr, validos);
    suma=sumaTotalArreglo(arr,validos);
    promedio=promiedo(suma,validos);
}


//ejerejer2

int cargaCaracteresXUsuario (char arr[], int dimension)
{
    int i=0;
     while(i < dimension)
     {
        printf("Ingrese el caracter\n");
        scanf("%c",&arr[i]);
        fflush(stdin);
        i++;
    }
 return i;
}

void mostrarArregloChar (char arr[], int val)
{
    int i=0;
    while(i < val)
    {
        printf(" |%c| \n",arr[i]);
        i++;
    }
}

void inversiondelcharjsjsj(char arr[],int validos){
    char aux;
    int j=validos-1,i=0;
    while (i<validos/2){
        aux=arr[j];
        arr[j]=arr[i];
        arr[i]=aux;
        i++;
        j--;
    }
}
void funcionMAXICRITICA(char arr[],int dimension)
{
    int validos=0;
    validos=cargaCaracteresXUsuario(arr,dimension);
    mostrarArregloChar(arr,validos);
    inversiondelcharjsjsj(arr,validos);
    printf("\nINVERSION!!!!\n");
    mostrarArregloChar(arr,validos);

}
