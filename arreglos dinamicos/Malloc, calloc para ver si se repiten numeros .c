#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Recorre el arreglo principal:

Si vistos[valor] == 0, márcalo con 1.

Si ya estaba marcado (== 1), ¡encontraste el primer duplicado! Imprímelo y detente (break).

Si terminas el recorrido sin duplicados, informa que no hubo.

Bonus: imprime cuántos números distintos había en total.

free de ambos arreglos al final.

*/

int main()
{
    //Pide N (validado entre 1 y 50).
    
    srand(time(NULL));
    
    int N;
    do{
        printf("ingrese un N ");
        scanf("%i",&N);
    }while(N<1 || N>50);
    
    //Reserva el arreglo principal con malloc (verifica NULL)
    
    // int *vector = (int *) malloc (sizeof (int) * size);
    
    int *vector_numeros = (int *) malloc ( sizeof (int) * N );
    
    if(vector_numeros == NULL) return EXIT_FAILURE;
    
    //llénalo con enteros aleatorios entre 1 y 50 (con rand()).
    
    printf("Arreglo rellenado =[ ");
    for(int i=0;i<N;i++){
        vector_numeros[i]= (rand()%50) + 1;
        printf("%i ",vector_numeros[i]);
    }
    printf("]\n");
    
    //Reserva un arreglo auxiliar de 51 enteros (índices 0 a 50) con calloc (verifica NULL). El índice 0 no se usa.
    
    int *vector_flags = (int *) calloc ( 51 , sizeof(int));
    
    if( vector_flags == NULL) return EXIT_FAILURE;
    
    /*
    Recorre el arreglo principal:

    Si vistos[valor] == 0, márcalo con 1.
    
    Si ya estaba marcado (== 1), ¡encontraste el primer duplicado! Imprímelo y detente (break).
    
    Si terminas el recorrido sin duplicados, informa que no hubo.
    */
    
    int primer_coincidencia=0; //el unico que no puede existir
    int cantidad_distintos=0;
    
    for(int i=0;i<N;i++){
        
        if (vector_flags[vector_numeros[i]] == 0){
            vector_flags[vector_numeros[i]]++;
            cantidad_distintos++;
        } 
        else if (primer_coincidencia == 0) primer_coincidencia = vector_numeros[i];
        
    }
    
    //Si terminas el recorrido sin duplicados, informa que no hubo.
    
    if(primer_coincidencia != 0) printf("¡Primer duplicado encontrado! -> %i\n",primer_coincidencia);
    else printf("No se encontraron números duplicados.\n");
    
    printf("Cantidad de números distintos: %i\n",cantidad_distintos);
    
    free(vector_numeros);
    free(vector_flags);
    
    return 0;
}
