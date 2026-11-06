#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
El horario
Cree dos tipos de registro: uno tipoHora, con hora y minuto, y otro tipoClase, con
nombre, sala y hora de inicio y final (ambos tipoHora). Cree un código que lea las clases
de un dia y compare si hay un choque de horarios
*/

typedef struct
{
    int hora;
    int minuto;
} tipoHora;

typedef struct
{
    char nombre[40];
    int sala;
    tipoHora inicio;
    tipoHora final;
    
}tipoClase;

void registrar_clases (tipoClase *a)
{
    printf("ingrese el titulo de la clase, para finalizar escriba -1 ");
    scanf(" %39[^\n]",a->nombre);
    if(strcmp(a->nombre,"-1") == 0) return;
    
    printf("ingrese la sala de la clase ");
    scanf("%i",&a->sala);
    
    printf("ingrese la hora de inicio de la clase (hora_minutos) ");
    scanf("%i %i",&a->inicio.hora, &a->inicio.minuto);
    
    printf("ingrese la hora de finalizacion de la clase (hora_minutos) ");
    scanf("%i %i",&a->final.hora, &a->final.minuto);
    
}

ver_choques ( tipoClase *a , int size_vector)
{
    //hacer un vector que guarde inicio y final
    
    int horas_minutos[size_vector*2];
    int k=0;
    for(int i=0;i<size_vector;i++){
        
        //unir la hora y los minuos a un numero de 3 cifras
        horas_minutos[k] = (a->inicio.hora)*100 + (a->inicio.minuto);
        k++
        horas_minutos[k] = (a->inicio.hora)*100 + (a->inicio.minuto);
        k++
    }
    //revisar si hay cosas que se repitan haciendo busqueda 
    
}

int main()
{
    //inicializar vector con clases
    int size_vector=1;
    tipoClase *vector = (tipoClase *) malloc(sizeof(tipoClase) * size_vector);
    if(vector == NULL) return EXIT_FAILURE;
    
    //escanear por 1era vez fuera del for 
    
    tipoClase clase_temporal;
    
    registrar_clases(&clase_temporal);
    
    while(strcmp(clase_temporal.nombre,"-1") != 0){
        
        //aumentar el tamaño del vector para que quepa la ultima lectura
        size_vector++;
        
        //realloc
        tipoClase *temporal = (tipoClase *) realloc(vector, sizeof(tipoClase) * size_vector);
        if(temporal == NULL){
            free(vector);
            return EXIT_FAILURE;
        }
        vector=temporal;
        
        //guardar ya leida
        
        vector[size_vector-1] = clase_temporal;
        
        //pedir nueva lectura
        
        registrar_clases(&clase_temporal);
    }
    
    //ver si hay choques de horario, suponiendo que estamos en la PUCV
    
    //osea que tenemos horarios fijos, por lo tanto solo tengo que ver si hay coincidentes
    
    
    
    free(vector);
    
}
