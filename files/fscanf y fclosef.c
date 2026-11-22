#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int dia;
    float T;
} dato;

int main()
{
    FILE *archivo = fopen("temperaturas.txt","rt");
    if(archivo == NULL) return EXIT_FAILURE;
    
    //leer N 
    int N;
    fscanf(archivo,"%i",&N);
    
    //guardar en un vector con struct dia y temperatura 
    dato vector[N];
    
    float min;
    int dia_min;
    float max;
    int dia_max;
    
    float promedio_t=0;
    
    int contador_sobre_promedio=0;
    
    for(int i=0;i<N;i++){
        fscanf(archivo,"%i %f",&vector[i].dia,&vector[i].T);
        
        if(i==1){
            min=vector[i].T;
            max=vector[i].T;
            dia_min=i+1;
            dia_max=i+1;
        }
        else{//revisar max y min
            if(max <vector[i].T){
                dia_max=i+1;
                max=vector[i].T;
            }
            if(min > vector[i].T){
                dia_min=i+1;
                min=vector[i].T;
            }
            
        }
        
        
        promedio_t+=vector[i].T;
    }
    
    fclose(archivo);
    

    
    promedio_t = promedio_t/N;
    
    for(int i=0;i<N;i++){
        if( vector[i].T > promedio_t){
            contador_sobre_promedio++;
        }
    }
    
    archivo = fopen("informe.txt","wt");
    if(archivo== NULL)return EXIT_FAILURE;
    
    fprintf(archivo,"El día más cálido es %i y su temperatura es %.2f\n",dia_max,max);
    fprintf(archivo,"El día más frío es %i y su temperatura es %.2f\n",dia_min,min);
    fprintf(archivo,"La temperatura promedio es %.2f\n",promedio_t);
    fprintf(archivo,"La cantidad de días con temperatura estrictamente mayor que el promedio son %i\n",contador_sobre_promedio);
    
    fclose(archivo);
    return 0;
}
