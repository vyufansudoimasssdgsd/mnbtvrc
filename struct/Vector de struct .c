#include <stdio.h>

#define N 3

typedef struct 
{
    char nombre[21];
    float nota;
} tipoEstudiante;



int main()
{
    tipoEstudiante curso[N];
    
    float acumulador_notas=0.0;
    
    //for para ingresar datos
    
    for(int i=0;i<N;i++){
        printf("ingrese name ");
        scanf(" %20[^\n]",(curso[i].nombre));
        printf("ingrese la nota ");
        scanf(" %f",&(curso[i].nota));
        
        //aca mismo acumulador de notas
        acumulador_notas+=curso[i].nota;
    }
    
    
    //for para printear
    
    for(int i=0;i<N;i++){
        printf("El estudiante %s tuvo nota %f \n",curso[i].nombre,curso[i].nota);
    }
    
    //aca printf promedio 
    printf("El promedio del curso es de %.2f",acumulador_notas/N);

    return 0;
}
