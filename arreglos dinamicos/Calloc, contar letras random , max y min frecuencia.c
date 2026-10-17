#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*

free de ambos arreglos.

*/

int main()
{
    int N;
    
    srand(time(NULL));
    
    //Pide N (validado entre 1 y 100).
    do{
        printf("Ingrese tamaño ");
        scanf("%i",&N); 
    }while (N<1 || N>100);
    
    //Reserva un arreglo de N caracteres con malloc.
    char *vector_letras = (char *) malloc(sizeof(char) * (N+1));
    
    if( vector_letras == NULL) return EXIT_FAILURE;
    
    //Llena con letras aleatorias entre 'a' y 'z'.
    
    for(int i=0;i<N;i++)
    {
        vector_letras[i] = (rand()%26) + 97;
    }
    
    vector_letras[N]='\0';
    
    //Reserva un arreglo de 26 enteros con calloc (uno por letra)

    int *vector_contador = (int *) calloc (26, sizeof(int));
    
    if(vector_contador == NULL) return EXIT_FAILURE;
    
    //Recorre el arreglo de caracteres y cuenta cuántas veces aparece cada letra.
    
    for(int i=0;i<N;i++){
        int numero_letra = vector_letras[i] - 97;
        vector_contador[numero_letra]++;
    }
    
    //Imprime un histograma así:
    /*
    text
    a: ***
    b: *
    c: *****
    ...
    */
    
    for(int i=0;i<26;i++){
        if(vector_contador[i] != 0){
            char letra= i + 97;
            printf("%c:",letra);
            for(int k=0;k<vector_contador[i];k++){
                printf("*");
            }
            printf("\n");
        }
    }
    
    //Imprime cuál es la letra más frecuente y cuál la menos frecuente (ignora las de frecuencia 0).
    
    int min = N+1;
    int max = -1;
    int pos_min=-1;
    int pos_max=-1;
    
    
    //buscar el min y max 
    for(int i=0;i<26;i++){
        if(vector_contador[i] != 0){
            if(max < vector_contador[i]){
                max = vector_contador[i];
                pos_max=i;
            }
            if(min > vector_contador[i]){
                min = vector_contador[i];
                pos_min=i;
            }
            
        }
    }
    //printear segun posicion
    
    printf("La letra más repetida fue %c \n",(pos_max + 97));
    printf("La letra menos repetida fue %c \n",(pos_min + 97));
    
    free(vector_contador);
    free(vector_letras);
    
    return 0;
}
