#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

//insertion sort void 
void insertionSort(int *A)
{
    int i,k;
    int temporal;
    
    for(i=1; i<N ;i++) // loop externo
    {
        temporal=A[i]; // probaremos con este 1ero
        
        k=i-1; //index desde el anterior al elegido
        
        
        while( (k>=0) && (A[k] >= temporal) ) 
        {//como se revisa de der a izq, k>=0, tambien A[k] (anteriores) tienen que ser 
            
            A[k+1]=A[k];
            k--
        }
        A[k+1] = temporal;
        
    }
    
    
}



int main()
{
    srand(time(NULL));
    //hacer 3 vectores ==
    
    int A[N];
    int B[N];
    int C[N];
    int i;
    
    for(i=0;i<N;i++){
        A[i]=rand()%10;
    }
    for(i=0;i<N;i++){
        B[i]=A[i];
    }
    for(i=0;i<N;i++){
        C[i]=A[i];
    }
    
    //crear 3 sistemas de ordenamiento
    
    
    
    //ver cuanto tiempo se tarda c/u

    return 0;
}
