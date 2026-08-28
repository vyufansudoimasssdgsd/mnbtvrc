#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5


int main()
{
    int vect[N][N];
    int i,j,n,sum_diagonal,sum_ant,es_simetrica;
    
    es_simetrica=1; // inicializada en true 
    sum_diagonal=0;
    sum_ant=0;
    
    srand(time(NULL));
    
    //Llenar matriz de datos basura
    
    for(i=0 ; i<N ; i++)
    {
        for (j=0 ; j<N ; j++)
        {
            vect[i][j]=rand()%9;
            printf("%i ",vect[i][j]);
            //Hacer suma de diagonal
            if (i ==j)
            {
                sum_diagonal+=vect[i][j];
            }
            // hacer summa antidiagonal
            if (i + j == N-1) 
            {
                sum_ant+=vect[i][j];
            }
        }
        printf("\n");
    }
    
    for(i=0 ; i<N ; i++)
    {
        for (j=0 ; j<N ; j++)
        {
            if (vect[i][j] != vect[j][i])
            {
                es_simetrica=0;
            }
        }
    }
    
    printf("la suma de la diagonal es = %i\n",sum_diagonal);
    printf("la suma de la antidiagonal es = %i\n",sum_ant);
    
    if (es_simetrica)
    {
        printf("La matriz es simetrica\n");
    }
    else
    {
        printf("La matriz no es simetrica\n");
    }
}
