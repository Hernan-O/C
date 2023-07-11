#include <stdio.h>
#include <stdlib.h>

long fibonacci(int n);

int main()
{
    int n, k;

    do
    {
        printf("Introduzca el numero de terminos: \n");
        scanf("%d", &n);
    }while(n <= 1);

    puts("\tSerie numeros de fibonacci");
    printf("0 1 ");

    for(k=2; k<=n; k++)
    {
        printf("%ld%c", fibonacci(k), (k%7==0 ?'\n':' '));
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
        return fibonacci(n-2) + fibonacci(n -1);
    }
}
