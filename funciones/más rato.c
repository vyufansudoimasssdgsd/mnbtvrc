#include <stdio.h>

int buscar_grande(int A[],int n)
{
    int i,izq,der;
    
    //buscar el 1er numero de izq a der != 0
    
    for(i=0;i<n;i++){
        if(A[i] != 0){
            izq=A[i];
            break;
        }
    }
    //buscar el 1er numero de der a izq != 0
    for(i=n;i>=0;i--){
        if(A[i] != 0){
            der=A[i];
            break;
        }
    }
    if(izq > der){
        
        return izq;
        
    }
    else if(izq < der){
        
        return der;
        
    }
    else {
        return der;
    }
}


int main()
{
    int i,n,resultado;
    
    //http://codeforces.com/problemset/problem/381/A
    
    printf("Ingrese la cantidad de numeros a ver ");
    scanf("%i",&n);
    
    int A[n];
    //aca como lo pasa con espacios, es necesario hacer un for 
    printf("ingrese el string con los numeros en si ");
    
    for(i=0;i<n;i++){ //nose como, pero eso es solo 1 linea 
        scanf(" %d",&A[i]); //recordar vectores sin &
    }
    
    
    resultado=buscar_grande(A,n);
    
    printf("aja %i",resultado);



    return 0;
}
