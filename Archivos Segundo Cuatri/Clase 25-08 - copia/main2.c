#include <stdio.h>
#include <stdlib.h>

long fibonacci(int n);
double FactoFactoRecursiva(double n);

int main()
{
    int n, k;

    printf("Ingrese el n:\n");
    scanf("%i", &n);

    k=FactoFactoRecursiva(n);

    printf("%i", k);
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
