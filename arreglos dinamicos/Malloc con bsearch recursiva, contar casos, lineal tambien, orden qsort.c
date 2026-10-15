#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*

Contexto: Dado un arreglo dinámico de enteros, debes encontrar valores usando dos estrategias distintas.

Requisitos:

Si no existe, informa.

free de ambos arreglos.

Concepto clave: malloc + copia de arreglos + comparación de eficiencia entre búsquedas.

*/

int comparar_enteros(const void *a, const void *b)
{
    int x=*(int *)a;
    int y=*(int *)b;
    if(x>y)return 1;
    if(x<y)return -1;
    return 0;
}

void show(int A[],int size){
    
    for(int i=0;i<size;i++){
        printf("%i ",A[i]);
    }
    printf("\n--------------------------------------\n");
}

void busqueda_binaria_recursiva( int A[] , int size, int pos_menor, int pos_mayor, int buscado, int comparaciones)
{
    if(pos_menor>pos_mayor){
        printf(" o algo salio mal o no esta lo que buscas, pero pasaron %i comparaciones",comparaciones);
        return;
    }
    
    int pos_central=(pos_mayor+pos_menor)/2;
    
    comparaciones++;
    
    if(buscado==A[pos_central]) printf("Encontrado en posicion %i con %i comparaciones",pos_central,comparaciones);
    else{
        if(A[pos_central]>buscado) return busqueda_binaria_recursiva (A,size,pos_menor,pos_central-1,buscado,comparaciones);
        return busqueda_binaria_recursiva (A,size,pos_central+1,pos_mayor,buscado,comparaciones);
    }
    
    
    
}


int main()
{
    srand(time(NULL));
    
    int size;
    
    //Pide N (validado entre 1 y 200).
    
    do{
        printf("cuanto es el tamaño del vector ?? ");
        scanf("%i",&size);
    }while (size<1 || size > 200);
    
    //Reserva con malloc, verifica NULL, llena con enteros aleatorios entre 1 y 500.
    
    int *vector;
    int *vector_desordenado;
    
    // vector = (int *) malloc (sizeof(), *size);
    vector = (int *) malloc( sizeof(int) *size);
    vector_desordenado = (int*) malloc ( sizeof(int) * size);
    
    
    if(vector == NULL) return EXIT_FAILURE;
    if(vector_desordenado == NULL) return EXIT_FAILURE;
    
    for(int i=0;i<size;i++){
        vector[i]=(rand()%500)+1;
        vector_desordenado[i]=vector[i];
    }
    
    printf("\n--------------------------------------\n");
    
    show(vector,size);
    
    //Ordena con qsort (usa tu comparador propio).

    qsort(vector,size,sizeof(int),comparar_enteros);
    
    printf("ordenado == \n");
    show(vector,size);
    
    //Pide un número buscado al usuario.
    
    int buscado;
    
    printf("QUe vamos a buscaerAsnjdaniksd ?");
    scanf("%i",&buscado);
    
    //Búscalo con búsqueda lineal en el arreglo original (haz una copia antes de ordenar) → reporta posición y comparaciones.
    
    //busqueda_lineal jadjsadjsajda
    
    int encontrado=0;
    
    for(int i=0;i<size;i++){
        if(vector_desordenado[i] == buscado){
            printf("Encontrado en busqueda lineal en posicion %i , con %i comparaciones\n",i,i+1);
            encontrado=1;
            break;
        }
    }
    if(encontrado == 0){
        printf("No encontrado tras %d comparaciones\n", size);
    }
    
    //Búscalo con búsqueda binaria recursiva en el arreglo ordenado → reporta posición y comparaciones.
    
    //void busqueda_binaria_recursiva( int vector , int size, int pos_menor, int pos_mayor, int buscado)
    //empieza con vector, tamaño, pos_menor =0, pos_mayor = N-1, buscando y contador_comparaciones = 1
    busqueda_binaria_recursiva(vector,size,0,size-1,buscado,0);
    
    free(vector);
    free(vector_desordenado);
    
    return 0;
}
