#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define M 4

void matriz_trans(int A[N][M])
{
    int i,j,temporal;
    
    for(i=0;i<N;i++){
        for(j=i+1;j<M;j++){
            temporal=A[i][j];
            A[i][j]=A[j][i];
            A[j][i]=temporal;
        }
    }
    
    
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("%i ",A[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------\n");
}

int main()
{
    printf("-----------------------\n");
    int i,j,A[N][M];
    
    srand(time(NULL));
    
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            A[i][j]=rand()%10;
            printf("%i ",A[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------\n");
    //SIN MATRIZ AUXILIAR xD
    matriz_trans(A);
    return 0;
}