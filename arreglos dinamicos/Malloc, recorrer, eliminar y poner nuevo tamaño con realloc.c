#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand(time(NULL));
    
    //Pide N (validado entre 1 y 100).
    
    int N;
    do{
        printf("Size ?? ");
        scanf("%i",&N);
    }while (N<1 || N>100);
    
    //Reserva con malloc (verifica NULL)
    
    int * vector_numeros = (int *) malloc (sizeof(int) * N);
    
    if(vector_numeros == NULL) return EXIT_FAILURE;
    
    //llena con enteros aleatorios entre 1 y 10 (habrá repetidos).
    printf("Arreglo desordenado = [");
    for(int i=0;i<N;i++){
        vector_numeros[i]= (rand()%10) +1;
        printf("%i ",vector_numeros[i]);
    }
    printf("] \n");
    
    //Pide un valor eliminar.
    int eliminar;
    printf("QUe valor queremos matar ? (recuerde [0,10]) ");
    scanf("%i",&eliminar);
    
    //Recorre el arreglo y compacta los elementos distintos a eliminar al inicio (sin usar un arreglo auxiliar, hazlo in-place).
    
    //hacer un for, llevar 2 index, uno para eliminar, otro para rellenar
    
    int index_normales=0;
    
    for(int i=0;i<N;i++){
        if(vector_numeros[i] != eliminar){
            vector_numeros[index_normales] = vector_numeros[i];
            index_normales++;
        }
    }
    
    //Cuenta cuántos elementos quedaron (nuevo_size) == index_normales
    //Usa realloc para reducir el bloque a nuevo_size enteros (si nuevo_size > 0).
    if(index_normales > 0){
        vector_numeros= (int *) realloc(vector_numeros, sizeof(int) * index_normales);
        printf("Se eliminaron %i elementos \n", N - index_normales);
        printf("El nuevo espacio del vector es de %i \n",index_normales * sizeof(int));
    }
    else printf("El nuevo tamaño es 0, asi que no hay vector\n");
    
    printf("Arreglo Ordenado = [");
    for(int i=0;i<index_normales;i++){
        printf("%i ",vector_numeros[i]);
    }
    printf("] \n");
    
    free(vector_numeros);
    
    return 0;
}
