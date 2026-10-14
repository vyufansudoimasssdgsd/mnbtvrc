#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int N;
    
    srand(time(NULL));
    
    do{
        printf("ingrese tamaño ");
        scanf("%i",&N);
    }while (N<=0);
    
    
    //Ahora a hacer lo de memoria 
    
    //puntero a [] de datos
    
    char *vector;
    
    // con malloc se declara que es un "vector"
    vector = (char *) malloc (sizeof(char) * (N+1) ); // es N+1 
    
    if(vector == NULL) return EXIT_FAILURE;
    
    //rellenar codigo
    
    //97 -> 122
    
    int i;
    for(i=0;i<N;i++){
        vector[i]=(rand()%26)+97; // 0-26
    }
    
    vector[N]='\0';
    
    printf("%s",vector);
    
    free(vector);
    
    

    return 0;
}