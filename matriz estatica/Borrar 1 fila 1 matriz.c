#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
#define M 3

int main()
{
    // hacer ejercicios donde el for no vaya de 1 en 1 
    //codeforce rayo 800
    int A[N][M],C[N-1][M-1];
    
    int i,j,k,l,n,f_el,c_el;
    
    srand(time(NULL));
    //llenar de basura
    printf("------------------------\n");
    for (i=0 ;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            n=rand()%90;
            n+=10;
            A[i][j]=n;
            printf("%i ",n);
        }
        printf("\n");
    }
    printf("------------------------\n");
    // cuales vamos a eliminar
    printf("Dime, que fila vamos a matar ? (que este entre 0 y %i)\n",N-1);
    scanf("%i",&f_el);
    
    printf("Dime, que Columna vamos a matar ? (que este entre 0 y %i)\n",M-1);
    scanf("%i",&c_el);
    printf("------------------------\n");
    
    k=0;
    l=0;
    for (i=0 ;i<N;i++)
    {
        if (i==f_el)
        {
            i+=1;
        }
        for(j=0;j<M;j++)
        {
            if (j==c_el)
            {
                j+=1;
            }
            C[k][l]=A[i][j];
            printf("%i ",A[i][j]);
            l+=1;
        }
        printf("\n");
        k+=1;
    }

}