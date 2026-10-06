#include <stdio.h>

#define N 100

void selectionSort(int vector[], int size)
{
    int contador_swaps=0;
    for(int i=0;i<size-1;i++){
        //size-1 porque ultimos 2 juntos
        int posMenor=i;
        for(int k=i+1;k<size;k++){
            if(vector[k]<vector[posMenor]){
                posMenor=k;
            }
            
        }
        if(posMenor != i){
            int temporal=vector[i];
            vector[i]=vector[posMenor];
            vector[posMenor]=temporal;
            contador_swaps++;
        }
    }
    printf("SelectionSort : %i", contador_swaps);
    
}

void insertionSort(int vector[], int size)
{
    int contador_swaps=0;
    for(int i=1;i<size;i++)
    {
        int temporal=vector[i];
        int k=i-1; //porque mover todo a la derecha
        while(k>=0 && (temporal < vector[k])) // el = no es necesario
        {
            vector[k+1]=vector[k];
            k--;
            contador_swaps++;
        }
        vector[k+1]=temporal;
    }
    printf("insertionSort : %i \n", contador_swaps);
    
}


int main()
{
    int vector[N] ={
        742, 19, 853, 412, 67, 938, 205, 11, 624, 489, 31, 876, 502, 143, 981,
        267, 88, 715, 334, 950, 42, 618, 829, 174, 551, 96, 380, 793, 221, 645,
        112, 907, 438, 58, 864, 309, 726, 185, 994, 531, 73, 682, 249, 816, 463,
        127, 958, 371, 604, 28, 840, 495, 162, 739, 386, 913, 230, 677, 54, 821,
        408, 179, 966, 343, 710, 257, 884, 521, 93, 636, 471, 138, 785, 322, 949,
        206, 863, 510, 47, 694, 431, 188, 925, 362, 759, 296, 833, 570, 81, 618,
        445, 192, 979, 356, 723, 240, 897, 514, 63, 668
    };
    
    int vector_1[N] ={
        742, 19, 853, 412, 67, 938, 205, 11, 624, 489, 31, 876, 502, 143, 981,
        267, 88, 715, 334, 950, 42, 618, 829, 174, 551, 96, 380, 793, 221, 645,
        112, 907, 438, 58, 864, 309, 726, 185, 994, 531, 73, 682, 249, 816, 463,
        127, 958, 371, 604, 28, 840, 495, 162, 739, 386, 913, 230, 677, 54, 821,
        408, 179, 966, 343, 710, 257, 884, 521, 93, 636, 471, 138, 785, 322, 949,
        206, 863, 510, 47, 694, 431, 188, 925, 362, 759, 296, 833, 570, 81, 618,
        445, 192, 979, 356, 723, 240, 897, 514, 63, 668
    };
    
    /*
    LA eficiencia de utilizar binary search al buscar algun valor en el peor de los casos es 2+2log2(5)
    o log2(100),en el mejor de los casos es que lo pilla altiro, osea que en la 1era iteracion es el mismo dato
    */
    
    insertionSort(vector,N);
    
    selectionSort(vector_1,N);


    return 0;
}
