#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define M 10

int main()
{
    // matriz sumaro sobre diagonal y bajo esta 
    
    int A[N][M];
    
    int i,j,suma_sobre,suma_debajo,n;
    suma_sobre=0;
    suma_debajo=0;
    
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
            if(i>j)
            {
                suma_debajo+=A[i][j];
            }
            else if (i<j)
            {
                suma_sobre+=A[i][j];
            }
        }
    }
    
    printf("Suma sobre la diagonal es de %i, debajo es de %i",suma_sobre,suma_debajo);
}    
    