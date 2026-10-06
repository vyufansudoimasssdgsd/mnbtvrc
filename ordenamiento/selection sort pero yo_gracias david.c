#include <stdio.h>
#define N 9

void ordenar(int vector[], int size)
{
    //parto desde el inicio, no es necesario el ultimo porque
    //ese se va a intercambiar con el penultimo
    for(int i=0;i<size-1;i++){
        //el posible menor es el actual
        int posmenor=i;
        // parto desde el i+1 para no revisar el mismo que es teoricamente menor
        for(int k=i+1; k<size;k++){
            //si justo los que estoy viendo el otro es menor
            if(vector[k]>vector[posmenor]){
                posmenor=k;
                //cambiar el posible menor
            }
            
        }
        //si de toda la lista el actual es mayor que el posible menor
        if(vector[i]<vector[posmenor])
        {
            int temporal = vector[i];
            vector[i]=vector[posmenor];
            vector[posmenor]=temporal;
            //los cambio de lugar
        }
        
    }
    
    
}


int main()
{
    int vector[N]={0,1,2,3,4,5,6,7,8};

    ordenar(vector,N);
    
    for(int i=0;i<N;i++){
        printf("%i",vector[i]);
    }
    printf("\n");
    return 0;
}
