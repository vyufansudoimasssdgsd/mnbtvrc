#include <stdio.h>

#define M 3
#define N 3

int main()
{
    int matriz[M][N];
    
    int i,j,n,suma;
    
    suma=0;
    
    //Ingresar datos
    
    for (i=0 ; i<M ; i++)
    {
        for(j=0 ; j<N ; j++)
        {
            printf("Ingrese un valor para a%i%i ",i+1,j+1);
            scanf("%i",&n);
            matriz[i][j]=n;
        }
    }
    
    printf("\n");
    
    // Printear
    
    for (i=0 ; i<M ; i++)
    {
        for(j=0 ; j<N ; j++)
        {
            printf("%i ",matriz[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    
    //Calcular suma
    
    for (i=0 ; i<M ; i++)
    {
        for(j=0 ; j<N ; j++)
        {
            suma+=matriz[i][j];
        }
    }
    
    printf("la suma de todos los valores de la matriz es de = %i\n",suma);
    
    // Matriz Transpuesta, debo cambiar el i por el j y era no ?
    
    for (i=0 ; i<M ; i++)
    {
        for(j=0 ; j<N ; j++)
        {
            printf("%i ",matriz[j][i]); //solo cambie aca el j por el i y era xD
        }
        printf("\n");
    }
    
    printf("\n");
    
}