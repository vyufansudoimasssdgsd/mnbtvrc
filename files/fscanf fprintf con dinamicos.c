#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *archivo_estudiantes = fopen("estudiantes.txt","rt");
    if(archivo_estudiantes == NULL) {
        printf("No se pudo crear estudiante.txt\n");
        exit (1);
    }
    FILE *archivo_reporte = fopen("reporte.txt","wt");
    if(archivo_reporte == NULL){
        printf("No se encontro reportes.txt");
        exit(1);
    }
    
    
    int N;
    //escanear 1era linea
    fscanf(archivo_estudiantes,"%i",&N);
    
    //crear vector
    float *vector = (float *) malloc (sizeof(float) * N);
    if(vector == NULL)return EXIT_FAILURE;
    //empezar ciclo
    
    float nota1,nota2,nota3;
    float promedio_estudiante;
    float promedio_curso=0;
    char nombre[31];
    int contador_aprobados=0;
    
    if(N>0){
        for(int i=0;i<N;i++){
            fscanf(archivo_estudiantes,"%s %f %f %f",nombre,&nota1,&nota2,&nota3);
            promedio_estudiante = (nota1 + nota2 + nota3) /3.0;
            promedio_curso+=promedio_estudiante;
            
            if(promedio_estudiante >= 4.0){
                fprintf(archivo_reporte,"%s %.1f APROBADO\n",nombre,promedio_estudiante);
                contador_aprobados++;
            }
            else fprintf(archivo_reporte,"%s %.1f REPROBADO\n",nombre,promedio_estudiante);
            
            vector[i]=promedio_estudiante;
        }
        
        promedio_curso = promedio_curso/N;
        
        fprintf(archivo_reporte,"Promedio del curso = %.1f\nCantidad de aprobados = %i\n",promedio_curso,contador_aprobados);
        
        fclose(archivo_estudiantes);
        fclose(archivo_reporte);
        free(vector);
    }
    return 0;
}
