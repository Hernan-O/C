#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


typedef struct{
     int valores[100];
     int posTope; //posición de nuevo tope, lugar en donde se almacenará el nuevo valor
} Pila;


/*void apilar(Pila p, int valor);
int desapilar(Pila p);
int tope(Pila p);
int pilavacia(Pila p);
void mostrar(Pila p);
void leer (Pila p);
void inicPila(Pila p);*/

int main()
{
    /*Pila Romagnoli;
    int PRUEBA=0;
    system("color 56");
    inicPila(&Romagnoli);
    leer(&Romagnoli);
    mostrar(&Romagnoli);
    PRUEBA=tope(&Romagnoli);
    printf("\n\nPRUEBA!:%d",PRUEBA);
    */


return 0;
}

void apilar(Pila p, int valor)
{
    p.valores[p.posTope]=valor;
    p.posTope=p.posTope+1;
}

int desapilar(Pila p)
{
    int desapilado;
    desapilado=p.valores[p.posTope];
    p.posTope=p.posTope-1;
return desapilado;
}

int tope(Pila p)
{
    int aux;

    aux = p.valores[p.posTope];

    return aux;
}

int pilavacia(Pila p)
{
    int flag=0;

    if(p.posTope == 0)
    {
        flag = 1;
    }

    return flag;
}

void mostrar(Pila p)
{
    printf("-------------------------\n");
    for(int i=0;i<p.posTope;i++)
    {
        fflush(stdin);
        printf("|%d",p.valores[i]);
    }
    printf("\n-------------------------\n");
}

void leer (Pila p)
{
    int valor=0;

    printf("Ingrese un valor\n");
    fflush(stdin);
    scanf("%i",&valor);
    printf("%d",p.posTope);

    p.valores[p.posTope]=valor;
    p.posTope++;
    printf("%d",p.valores[p.posTope]);
}

void inicPila(Pila p)
{
    for(int i=0;i<100;i++)
    {
        p.valores[i]=0;
    }
    p.posTope=0;
}


