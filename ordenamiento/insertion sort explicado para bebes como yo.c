#include <stdio.h>

//aprenderme insertion, selection, qsort, bsearch

void insertion_sort(int vector[], int size)
{ //parte en 1 para el 0 tenerlo de "ordenado", poner adelante o altras el sgte
    for(int i=1;i<size;i++){
        //temporal sera el guardado izquierdo de los no ordenados 
        int temporal=vector[i];
        // k = i-1, el -1 para empezar a comparar con los ordenados 
        int k=i-1;
        //mientras no toquemos el finaol, y que en el cual comparemos sea 
        //mayor que el temporal, asi se ordena de - a +, porque se pone el 
        //temporal a la izq del grande 
        while ( (k>=0) && (vector[k] >= temporal) ){
            // el sgte/temporal sera borrado y se mueve a la derecha el otro
            vector[k+1] = vector[k];
            k--; // k-- para seguir con el sgte, y asi a la derecha...
            
        }
        //al final el temporal va a ir donde uno de las copias que este a su 
        //derecha sea el ultimo mayor o igual que este, o temporal es el menor posible
        // que es cuando k=-1, ahi va en 0
        vector[k+1] = temporal;
    }
    
}