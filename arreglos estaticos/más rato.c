#include <stdio.h>

int buscar_grande(int A[],int n)
{
    int i,izq,der;
    
    //buscar el 1er numero de izq a der != 0
    
    for(i=0;i<n;i++){
        if(A[i] != 0){
            izq=A[i];
        }
    }
    
    //buscar el 1er numero de der a izq != 0
    
    for(i=n;i>0;i--){
        if(A[i] != 0){
            der=A[i];
        }
    }
    
    if(izq > der){
        
        return izq;
        
    }
    if(izq < der){
        
        return der;
        
    }
    
}

int sumar_sereja_dima()


int main()
{
    int i,n;
    
    //http://codeforces.com/problemset/problem/381/A
    
    printf("Ingrese la cantidad de numeros a ver ");
    scanf("%i",&n);
    
    in A[n];
    
    printf("ingrese el string con los numeros en si ");
    scanf(" %s",A); //recordar vectores sin &
    
    comparar_en_si(A,n);

    return 0;
}
