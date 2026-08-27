#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 5
#define N 5

int main()
{
    int matriz[M][N];
    
    int i,j,n,suma;
    
    srand(time(NULL)); // DONT FORGET, IM WITH YOU IN THE DARKKKKK
    
    n=0;
    
    for (i=0 ; i <M ; i++)
    {
        for (j=0 ; j<N ; j++)
        {
            n=rand()%20;
            n+=1;
            matriz[i][j]=n;
            printf("%i ",n);
        }
        printf("\n\n");
    }
    
    for (i=0 ; i< M ;i++) //aca como es estatico el i, estoy sumando filas
    {
        suma=0;
        for (j=0 ; j<N ; j++)
        {
            suma+=matriz[i][j];
        }
        printf("Suma de la fila %i = %i\n",i+1,suma);
    }
    
    for (j=0 ; j< N ;j++) //aca como es estatico el j, estoy sumando columnas
    {
        suma=0;
        for (i=0 ; i<M ; i++)
        {
            suma+=matriz[i][j];
        }
        printf("Suma de la columna %i = %i\n",j+1,suma);
    }
}