#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 5

void maximo_matriz(int A[N][M], int *maximo, int *fila_pos, int *col_pos)
{
    int i,j;    
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if( *maximo < A[i][j]){
                 *maximo=A[i][j];
                 *fila_pos=i;
                 *col_pos=j;
            }
        }
    }
    printf("El numero más grande encontrado fue %i \n", *maximo);
    printf("Estaba en la fila %i columna %i", *fila_pos+1, *col_pos+1);
}

int main()
{
    int i,j,A[N][M],maximo,fila_pos,col_pos;
    
    srand(time(NULL));
    
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            A[i][j]=rand()%51;
            printf("%i ",A[i][j]);
        }
        printf("\n");
    }
    maximo=A[0][0];
    
    maximo_matriz(A,&maximo,&fila_pos,&col_pos);
    
    return 0;
}