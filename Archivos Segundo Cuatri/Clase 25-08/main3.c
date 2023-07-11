#include <stdio.h>
#include <stdlib.h>

long fibonacci(int n);
double FactoFactoRecursiva(double n);

int main()
{
    int n, k,cant;
    int Arr[5] = {1,2,3,2,1};

    //printf("Ingrese el n:\n");
    //scanf("%i", &n);
    //printf("\nCuantas veces quiere sacar la potencia del numero que ingreso anteriormente? \n");
   // scanf("%d",&cant);


    //n=PotePoteRecuRecursiva(n,cant);
    ArreArreRecursivo(Arr, 5);
    printf("\n----------------------------\nAL REVEZ!!!!!!!!!!!!!!\n----------------------------\n");
    ArreArreRecursivoInv(Arr, 5,0);

    n=ArreArreRecursivoCapicua(Arr, 5, 0, 0);

    if(n!=0)
    {
        printf("\n Es capicua\n");

    }
    else
    {
        printf("\nNo es capicua\n");
    }
    system("pause");

    return 0;
}

long fibonacci(int n)
{
    if (n== 0||n==1)
    {
        return n;
    }
    else
    {
        return fibonacci(n-2) + fibonacci(n-1);
    }
}

double FactoFactoRecursiva(double n)
{
    int rta;
    if(n==0)
    {
            rta =1;
    }
    else
    {
        rta = n*FactoFactoRecursiva(n-1);
    }
    return rta;
}

int PotePoteRecuRecursiva(int potencia, int cant)
{
    int rta;
    if(potencia==0||potencia==1||cant==0)
    {
        rta = 1;
    }
    else
    {
        rta = potencia * PotePoteRecuRecursiva(potencia,cant-1);

    }
    return rta;
}

void ArreArreRecursivo(int arr[], int val)
{

    if(val==0)
    {
        printf("| BOKA");
        system("COLOR 9E");
    }
    else
    {
        printf("%d ",arr[val-1]);
        ArreArreRecursivo(arr, val-1);
    }
}

void ArreArreRecursivoInv(int arr[], int val, int i)
{

    if(i==val)
    {
        printf("| AKOB");
        system("COLOR 9E");
    }
    else
    {
        printf("%d ",arr[i]);
        ArreArreRecursivoInv(arr,val,i+1);
    }
}

int ArreArreRecursivoCapicua(int arr[], int val, int i,int flag )
{

    if(i>=val+1)
    {
        printf("| AKOB");
        system("COLOR 9E");
    }
    else
    {
        if(arr[i] == arr[val])
        {
            flag = 1;
        }
        else
        {
            i=val;
            flag=0;
        }
        ArreArreRecursivoCapicua(arr,val-1,i+1, flag);
    }
    return flag;
}

