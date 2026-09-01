#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
#define M 2

int main()
{
    // matriz y su trans
    
    int A[N][M],B[M][N];
    
    int i,j,n;
    
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
    
    //Ahora a pasar de normal a trans
    for (i=0 ;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            B[j][i]=A[i][j];
        }
    }
    //Printear
    for (i=0 ;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%i ",B[i][j]);
        }
        printf("\n");
    }
    printf("------------------------\n");
    
    
    
    
}    
    