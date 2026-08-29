#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2
#define M 2
#define P 2

int main()
{
    int A[N][M], B[M][P], C[N][P], D[N][P];
    
    int i,j,k,n,s_mult;
    
    srand(time(NULL));
    
    // inicializa matriz A
    
    for (i=0 ; i< N ; i++)
    {
        for (j=0 ; j< M ; j++)
        {
            n=rand()%6;
            A[i][j]=n;
            printf("%i ",A[i][j]);
        }
        printf("\n");
    }
    
    printf("-------------------\n");
    
    // inicializa matriz B
    
    for (i=0 ; i<M ; i++)
    {
        for (j=0 ; j<P ; j++)
        {
            n=rand()%6;
            B[i][j]=n;
            printf("%i ",B[i][j]);
        }
        printf("\n");
    }
    printf("-------------------\n");
    
    // Sumar matrices en C[N][M]
    
    if (N==M && M==P)
    {
        printf("Si se pueden sumar las matrices\n");
        printf("-------------------\n");
        for (i=0 ; i< N ; i++)
        {
            for (j=0 ; j< M ; j++)
            {
                C[i][j]=A[i][j]+B[i][j];
                printf("%i ",C[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("No se pueden sumar las matrices\n");
        printf("-------------------\n");
    }
    
    printf("-------------------\n");
    printf("Multiplicacion de las matrices\n");
    printf("-------------------\n");
    
    // AJAJJAJJAJAJA, estaba 90% bien 
    
    for (i=0 ; i<N ; i++) // este hace que cambie de fila de matriz izq
    {
        for (j=0 ; j<P ; j++) // cambiar de columna en matriz derecha
        {
            s_mult=0;
            for(k=0 ; k<M ; k++) // cambiar cuales se estan multiplicando
            {
                s_mult+=A[i][k] * B[k][j];
            }
            D[i][j]=s_mult;
            printf("%i ",D[i][j]);
        }
        printf("\n");
    }
    //Costo, pero se pudo burro
    
    
    
}
