#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
#define M 3

int main()
{
    // hacer ejercicios donde el for no vaya de 1 en 1 
    //codeforce rayo 800
    int A[N][M],B[N-1][M],B2[N][M-1],C[N-1][M-1];
    
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
    //hacer un fpr con un if que ignore los que no se deben copiar
    //inicializar k y l que seran para el chico
    k=0;
    l=0;
    for (i=0 ;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            if (j!=c_el)
            {
                B[k][l]=A[i][j];
                printf("%i ",B[k][l]); // bien fila, mal columna
                l+=1;   // entonces hacerlo 2 veces, 1 normal y otra trans
            }
        }
        k+=1;
        
        printf("\n");
    }
    printf("------------------------\n");
    //aca ya me dio quitando la fila, ahora sacar columna repitiendo
    //ocupar trans en chica y sacarle su columna deseada
    
    //sacarle transpuesta a una matriz B
    l=0;
    k=0;
    for (i=0 ;i<N-1;i++)
    {
        for(j=0;j<M;j++)
        {
            B2[j][i]=B[i][j];
            printf("%i ",B2[j][i]);
        }
        printf("\n");
    }
    printf("------------------------\n");
    
    k=0;
    l=0;
    for (i=0 ;i<N-1;i++)
    {
        for(j=0;j<M;j++)
        {
            if (j!=c_el)
            {
                C[k][l]=B[j][i];
                printf("%i ",C[k][l]); // bien fila, mal columna
                l+=1;   // entonces hacerlo 2 veces, 1 normal y otra trans
            }
        }
        k+=1;
        
        printf("\n");
    }
    printf("------------------------\n");
    
}
