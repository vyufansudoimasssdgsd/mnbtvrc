#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define M 4

int main()
{
    // matriz sumaro sobre diagonal y bajo esta 
    
    int A[N][M];
    
    int i,j,k,n,temporal,fila_1,fila_2,asked;
    float factor;
    
    asked=0;
    
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
    
    //preguntar
    
    while (asked !=-1)
    {
        printf("Que deseas hacer 0=cambiar filas 1=multiplicar factor a una fila 2=la larga -1=terminar ");
        scanf("%i",&asked);
        if (asked ==0)
        {
            printf("Que filas deseas cambiar de lugar?\n");
            printf("Fila 1 =");
            scanf("%i",&fila_1);
            printf("Fila 2 =");
            scanf("%i",&fila_2);
            
            //cambiar
            k=fila_2;
            i=fila_1;
            for(j=0;j<M;j++)
            {
                temporal=A[i][j];
                A[i][j]=A[k][j];
                A[k][j]=temporal;
            }
        }
        else if (asked==1)
        {
            printf("Que fila ?");
            scanf("%i",&fila_1);
            printf("Y por cuanto? (si es fraccion poner en decimal plis)");
            scanf("%f",&factor);
            i=fila_1;
            for(j=0;j<M;j++)
            {
                A[i][j]=(A[i][j]*factor);
            }
        }
        else if (asked==2)
        {
            printf("Que filas deseas sumar/restar\n");
            printf("Fila 1 =");
            scanf("%i",&fila_1);
            printf("Fila 2 =");
            scanf("%i",&fila_2);
            printf("Y por cual factor?");
            scanf("%f",&factor);
            //cambiar
            k=fila_2;
            i=fila_1;
            for(j=0;j<M;j++)
            {
                A[i][j]=(A[i][j]+(factor*A[k][j]));
            }
        }
        //Printear para comparar
        if(asked!=-1)
        {
            printf("------------------------\n");
            for (i=0 ;i<N;i++)
            {
                for(j=0;j<M;j++)
                {
                    printf("%i ",A[i][j]);
                }
                printf("\n");
            }
            printf("------------------------\n");
        }
    }
    
}    
    