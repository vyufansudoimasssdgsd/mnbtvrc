#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int code;
    int repo;
} song;

int comparar_enteros (const void *a, const void *b)
{ //recordar esta sintaxis
    song x=*(song *)a;
    song y=*(song *)b;
    //if(x.repo != y.repo)
    return y.repo - x.repo;
}

int main()
{
    
    song *vector=NULL;
    
    song temporal;
    int flag_while=0;
    int flag_existe=0;
    int flag_ejecucion=0;
    int i=0;
    int size_vector=0;
    scanf(" %i",&temporal.code);
    
    //escanear 1er codigo if!=0 entrar a un while(flag)
    if(temporal.code != 0) flag_while=1;
    
    while(flag_while)
    {
        flag_ejecucion=1;
        //escanear repo
        scanf(" %i",&temporal.repo);
        
        //los scanf separados, guardar en temporal 1 arria otro abajo, si llena 2do realloc 
        
        //JAJA tengo que revisar si esta dentro ya el codigo xD y sumarlo al que esta en el vector JAJA
        
        for(int j=0;j<size_vector;j++){
            if(temporal.code == vector[j].code){
                vector[j].repo+=temporal.repo;
                flag_existe=1;
                break;
            }
        }
        
        if(flag_existe == 0){
            size_vector++;
            song *temporal_vector = (song *) realloc(vector,sizeof(song)*size_vector);
            if(temporal_vector == NULL)return EXIT_FAILURE;
            vector=temporal_vector;
            
            vector[i].code=temporal.code;
            vector[i].repo=temporal.repo;
            i++;
        }
        
        flag_existe=0;
        scanf(" %i",&temporal.code);
        if(temporal.code == 0) flag_while=0;
        
    }
    
    if(flag_ejecucion){
        //si termina while, qsort y f(x) que compara probar solo con poner de +a- segun cistas 
        
        qsort(vector,size_vector,sizeof(song),comparar_enteros);
        
        //imprimir como sale en el codigo aJAJAJ
        
        printf(" _______________________ ________________________\n|    CODIGO CANCION     |  TOTAL REPRODUCCIONES  |\n|_______________________|________________________|\n|                       |                        |\n");
        
        for(i=0;i<size_vector;i++)
        {
            printf("|%22i |%22i  |\n",vector[i].code,vector[i].repo);
            
            
        }
        printf("|_______________________|________________________|\n");
    }
    else printf("NO SE INGRESARON DATOS!\n");
    
    
    return 0;
}
