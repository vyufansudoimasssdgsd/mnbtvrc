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
    for(i=n;i>=0;i--){ //n-1 porque jaja, asi funcionan los vectores 
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

void eliminar_usado(int A[],int max,int n)
{
    int i;
    for(i=0;i<n;i++){
        if(A[i]==max){
            A[i]=0; // se quita de la lista el usado
        }
    }
    
}

int main()
{
    int i,j,n,resultado,sereja,dima;
    
    //http://codeforces.com/problemset/problem/381/A
    
    printf("Ingrese la cantidad de numeros a ver ");
    scanf("%i",&n);
    
    int A[n];
    
    //aca modificacion porque ajja pensado en C++
    
    for(i=0;i<n;i++){
        printf("ingrese el string con los numeros en si ");
        scanf("%i",&A[i]); //recordar vectores sin &
    }
    
    
    sereja=0;
    dima=0;
    
    //aca va a encontrar el más chico, y como no se repiten, eliminarlo altiro del vector
    
    for(j=0;j<n;j++){
        
        resultado=buscar_grande(A,n);
        
        if(j%2==0){
           sereja+=resultado; 
        }
        else{
            dima+=resultado;
        }
        
        eliminar_usado(A,resultado,n);
        
    }
    printf("Sereja tiene %i, Dima tiene %i",sereja,dima);


    return 0;
}
