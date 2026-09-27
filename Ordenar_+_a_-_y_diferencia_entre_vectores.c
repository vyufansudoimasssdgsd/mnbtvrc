#include <stdio.h>
#include <stdlib.h>


void llenar_vector(int A[], int n)
{
    int i,dato;
    for(i=0;i<n;i++){
        scanf("%i",&dato); //tomar
        A[i]=dato; //guardar
    }
}

int comparaEnteros(const void *a, const void *b)
{
    int *ptrA = (int *)a;
    int *ptrB = (int *)b;
    if( *ptrA > *ptrB )
        return 1;
    else
        return 0;
    
}

int diferencia_pedida(int A[], int B[], int n)
{
    int i,acumulador,diferencia;
    acumulador=0;
    for(i=0;i<n;i++){
        diferencia=A[i]-B[i];
        if( diferencia <0 ) diferencia= diferencia*(-1);
        acumulador+=diferencia; 
    }
    return acumulador;
}

int main()
{
    //primero, tengo que hacer se entren los datos 
    int n,acumulador;
    n=1;
    
    while (1==1)
    {
        scanf("%i",&n); //casos
        if(n==0) break;
        int A[n],B[n];
        
        //llenar los datos en si
        llenar_vector(A,n);
        llenar_vector(B,n);
        
        //ordenar los datos del vector de - a +
        //voy a probar qsort
        
        
        qsort(A,n,sizeof(int),comparaEnteros);
        qsort(B,n,sizeof(int),comparaEnteros);
        
        //ir pasando por los 2 vectores y acumulador de (-)
        acumulador=diferencia_pedida(A,B,n);
        printf("%i\n",acumulador);
    }
    
    return 0;
}