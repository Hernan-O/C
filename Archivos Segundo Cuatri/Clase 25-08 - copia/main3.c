#include <stdio.h>
#include <stdlib.h>

long fibonacci(int n);
double FactoFactoRecursiva(double n);
int SumaArrRecu(int arr[], int val, int rta);
int MichaelJackson(int arr[], int val, int menor);
int MichaelJacksonArchives(char name[30]);
int sevihcrAnoskcaJleahciM(FILE *archi, int menor);

int main()
{
    int n=0, k,cant;
    int Arr[5] = {4,1,5,6,8};

    FILE *archi = fopen("Jackson 5", "wb");

    fwrite( &Arr[4], sizeof(int), 1, archi);
    fwrite( &Arr[3], sizeof(int), 1, archi);
    fwrite( &Arr[2], sizeof(int), 1, archi);
    fwrite( &Arr[0], sizeof(int), 1, archi);
    fwrite( &Arr[1], sizeof(int), 1, archi);


    fclose(archi);


    //printf("Ingrese el n:\n");
    //scanf("%i", &n);
    //printf("\nCuantas veces quiere sacar la potencia del numero que ingreso anteriormente? \n");
   // scanf("%d",&cant);

    //n=PotePoteRecuRecursiva(n,cant);

    ArreArreRecursivo(Arr, 5);
    printf("\n----------------------------\nAL REVEZ!!!!!!!!!!!!!!\n----------------------------\n");
    ArreArreRecursivoInv(Arr, 5,0);

    n=ArreArreRecursivoCapicua(Arr, 4, 0, n);




    if(n==0)
    {
        printf("\n No es capicua\n");

    }
    else
    {
        printf("\nEs capicua\n");
    }

     n=SumaArrRecu(Arr, 5, 0);

    printf("\n\nSuma Arreglo=%i \n", n);

    n=MichaelJackson(Arr, 5, Arr[4]);

    printf("\n\nEl menor es=%i shamouna\n", n);

    n=MichaelJacksonArchives("Jackson 5");

    printf("\nEl menor en el archivos es= %i\n\n", n);


    InvierteArchivos("Jackson 5");

    mostrarArchivo("Jackson 5");


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

    if(val==-1)
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

    if(i>val)
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
        printf("flag: %i", flag);
        ArreArreRecursivoCapicua(arr,val-1,i+1, flag);
        return flag;
    }
}

int SumaArrRecu(int arr[], int val, int rta)
{
    if(val==-1)
    {
             printf("| AKOB");
            system("COLOR 9E");
    }
    else
    {
        rta = rta+SumaArrRecu(arr, val-1, rta)+arr[val];
    }
    return rta;
}

int MichaelJackson(int arr[], int val, int menor)
{
    if(val == 0)
    {
         printf("| AKOB");
        system("COLOR 9E");
    }
    else
    {
        if(menor > arr[val])
        {
            menor = arr[val];
        }
        menor = MichaelJackson(arr, val-1, menor);
    }
    return menor;
}

int MichaelJacksonArchives(char name[30])
{
    FILE *archi= fopen(name, "rb");

    int menor;
    fread(&menor, sizeof(int),1,archi);
    fseek(archi, sizeof(int), 0);
    menor = sevihcrAnoskcaJleahciM(archi, menor);


    fclose(archi);

    return menor;
}

int sevihcrAnoskcaJleahciM(FILE *archi, int menor)
{
    int aux;
    if(fread(&aux, sizeof(int),1,archi)==0)
    {
         printf("| AKOB");
        system("COLOR 9E");
    }
    else
    {

        if(menor > aux)
        {
            menor = aux;
        }
        menor = sevihcrAnoskcaJleahciM(archi,menor);
    }
    return menor;
}

int InvierteArchivos(char name[30])
{
    FILE *archi= fopen(name, "ab");
    int ini=0, fin;

    fseek(archi,0,SEEK_END);
    fin = ftell(archi);
    fseek(archi,0,SEEK_SET);
    printf("%d",fin);
    system("pause");

    mostrarArchivoInvertido(archi, ini, fin);

    fclose(archi);
}

void mostrarArchivoInvertido(FILE *archi, int ini, int fin)
{
    int auxIni;
    int auxFin;
    if(ini>fin)
    {
        printf("| AKOB\n");
        system("COLOR 9F");
    }
    else
    {
        fread(&auxIni, sizeof(int)*ini, 1, archi);
        fread(&auxFin,fin,1,archi);
        fseek(archi,0,SEEK_SET);
        fwrite(&auxFin,sizeof(int)*ini,1,archi);
        fwrite(&auxIni,fin,1,archi);
    }
    ini=ini+sizeof(int);
    fin=fin-sizeof(int);
    mostrarArchivoInvertido(archi,ini,fin);
}
void mostrarArchivo(char nombreArchivo[30]) //Ejercicio 2
{
    FILE *archivo1 = fopen(nombreArchivo,"rb");
    int R;
    if(archivo1!=NULL)
    {
        while(fread(&R,sizeof(int),1,archivo1))
              {
                  printf("Cargado: %d\n",R);
              }
    fclose(nombreArchivo);
    }
}



