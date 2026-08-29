#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2
#define M 2
#define P 2

int main()
{
    int A[N][M], B[M][P], C[N][P], D[N][P], C_2[N][P];
    
    int i,j,k,n,s_mult,flag;
    
    flag=1; // Para ver si al sumar C con E/0 cambia, compararndo con C_2  
    
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
    
    // AJAJJAJJAJAJA, estaba 90% bien, digo, multiplicar A y B en matriz D[N][P]
    
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
    
    // Sumar a C[N][P] una matriz vacia (E[N][P]) e ir comparando si hay algun cambio
    
    //1ero poblar E de 0's
    
    int E[N][P] = {} ; // creo que era asi para llenarlo con 0, tambien es asi -> {0}
    
    //sumarlas y printear, me robe el codigo de arriba
    
    printf("-------------------\n");
    printf("Sumar C con 0 a ver si pasa algo\n");
    printf("-------------------\n");
    
    for (i=0 ; i< N ; i++)
    {
        for (j=0 ; j< M ; j++)
        {
            C_2[i][j]=C[i][j]+E[i][j];
            
            if (C_2[i][j] != C[i][j])
            {
                flag=0;
            }
            printf("%i ",C_2[i][j]);
        }
        printf("\n");
    }
    
    printf("-------------------\n");
    
    if (flag)
    {
        printf("Bien, sumar 0 a algo sigue siendo ese mismo algo");
    }
    else
    {
        printf("ERROR");
    }
    printf("-------------------\n");
}
