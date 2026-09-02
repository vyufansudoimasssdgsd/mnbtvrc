#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define M 10

int main()
{
    // matriz y a buscar un N° dentro de esta
    
    int A[N][M];
    
    int i,j,n,asked,count_index,index_f,index_c,last_index_f,last_index_c;
    count_index=0;
    
    srand(time(NULL));
    //llenar de basura
    printf("------------------------\n");
    for (i=0 ;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            n=rand()%51;
            A[i][j]=n;
            printf("%i ",n);
        }
        printf("\n");
    }
    printf("------------------------\n");
    
    printf("Y que buscaremos hoy?");
    scanf("%i",&asked);
    printf("------------------------\n");
    
    //Ciclo que pase por toda la matriz buscandolo
    for (i=0 ;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            if(A[i][j]==asked && count_index>1)
            {
                count_index+=1;
                last_index_f=i+1;
                last_index_c=j+1;
            }
            else if (A[i][j]==asked)
            {
                index_f=i+1;
                index_c=j+1;
                count_index+=1;
            }
        }
        
    }
    
    if(count_index==0)
    {
        printf("NO se encontro tu numero");
    }
    else if (count_index==1)
    {
        printf("Se encontro lo que buscabas, 1 vez, pero esta en la fila %i columna %i",index_f,index_c);
    }
    else
    {
        printf("Se encontro lo que buscabas %i veces\n",count_index);
        printf("Tambien, aparecio por primera vez en fila %i columna %i y por ultima vez en fila %i columna %i \n",index_f,index_c,last_index_f,last_index_c);
    }
    
}    
    