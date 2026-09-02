#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define M 10

int main()
{
    // matriz sumar exterior
    
    int A[N][M];
    
    int i,j,suma,n;
    suma=0;
    
    srand(time(NULL));
    //llenar de basura
    printf("------------------------\n");
    for (i=0 ;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            n=rand()%10;
            A[i][j]=n;
            printf("%i ",n);
        }
        printf("\n");
    }
    printf("------------------------\n");
    //pasar por ella e ir sumando
    
    for (i=0 ;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            if(i==0)
            {
                suma+=A[i][j];
            }
            else if(i==N-1)
            {
                suma+=A[i][j];
            }
            else if(j==0)
            {
                suma+=A[i][j];
            }
            else if (j==M-1)
            {
                suma+=A[i][j];
            }
        }
    }
    printf("la suma es de %i",suma);
}    
    