#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int invertido;
    int ganado;
    float radio;
} ciudad;


int comparar(const void *a, const void *b)
{ //si es ==, dejar de + a - invertido
    ciudad *c1 = (ciudad *)a;
    ciudad *c2 = (ciudad *)b;
    
    //ordenar ascendente segun invertido
    if(c1->invertido != c2->invertido) return c1->invertido - c2->invertido;
    return c1->ganado - c2->ganado; //sino ganado 
}

int main()
{
    //crear vector dinamico de base struct para invertido-ganado 
    ciudad *vector = NULL;
    int size_vector=0; //inicializar vector == 0
    
    ciudad temporal; // crear temporal que despues pasa a vector
    
    int flag_seguir=1; //ocupar flag para ver si esta dentro o fuera del for
    int i;
    
    scanf("%i",&temporal.invertido);
    
    //si el primer dato es 0
    if(temporal.invertido == 0) flag_seguir = 0;
    if(flag_seguir)scanf(" %i",&temporal.ganado);
    
    for(i=0;flag_seguir!=0;i++)
    {
        //aumentar size vector y realloc
        size_vector++;
        ciudad *temporal_vector = realloc(vector,sizeof(ciudad) * size_vector);
        if(temporal_vector == NULL){
            free(vector);
            return EXIT_FAILURE;
        }
        vector=temporal_vector; // si todo bien, vector realloc
        
        //ingresar datos al vector
        
        vector[i].invertido = temporal.invertido;
        vector[i].ganado = temporal.ganado;
        
        //escanear nuevos datos 
        
        scanf("%i",&temporal.invertido);
        
        //si el primer dato es 0
        if(temporal.invertido == 0) flag_seguir = 0;
        if(flag_seguir)scanf(" %i",&temporal.ganado);
        
    }
    
    //probemos qsort, ordenar segun invertido y si == ganado
    qsort(vector,size_vector,sizeof(ciudad), comparar);
    
    int flag_justa=1; // empezar con que la tombola es justa
    
    
    //pasar por el vector y verificar que a más invertido más ganado 
    for(int j=1;j<size_vector;j++){
        if(vector[j-1].invertido < vector[j].invertido){
            if(vector[j-1].ganado >= vector[j].ganado)flag_justa=0;
        } 
    }
    
    if(i!=0){ //Si se ejecuto el for, imprimir si fue justo o no 
        if(flag_justa){
            printf("SI FUE JUSTA\n");
        }
        else printf("NO FUE JUSTA\n");
    }
    
    return 0;
}
