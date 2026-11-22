#include <stdlib.h>
#include <stdio.h>


typedef struct
{// numero sucursal, codigo, ventas
    int sucursal;
    int codigo;
    int ventas;
} datos_productos;

int main()
{
    //crear vector dinamico NULL
    
    datos_productos *vector = NULL;
    
    //Al recibir datos guardar en temporal
    int size_vector=0;
    int ingresar_datos=0;
    datos_productos temporal;
    //leer el 1ero
    scanf("%i",&temporal.sucursal);
    
    while(temporal.sucursal != 0){
        ingresar_datos=1;
        //si no es 0, se leen los otros
        scanf("%i %i",&temporal.codigo,&temporal.ventas);
        //buscar si hay un codigo ==
        
        //flag para ver si esta repetido
        int ingresado=0;
        
        for(int j=0;j<size_vector;j++){
            if(temporal.codigo == vector[j].codigo){
                vector[j].ventas+=temporal.ventas;
                ingresado=1;
                
                //printf("vector repetido = %i %i %i\n",vector[j].sucursal,vector[j].codigo,vector[j].ventas);
            }
        }
        //sino, aumetar vector size y añadir nuevo codigo
        if(ingresado == 0){
            //aumentar size
            size_vector++;
            datos_productos *v_temporal = (datos_productos *) realloc(vector,sizeof(datos_productos) * (size_vector));
            if(v_temporal == NULL) return EXIT_FAILURE;
            vector=v_temporal;
            
            //añadir nuevo codigo
            vector[size_vector-1].sucursal=temporal.sucursal;
            vector[size_vector-1].codigo=temporal.codigo;
            vector[size_vector-1].ventas=temporal.ventas;
            //printf("vector = %i %i %i\n",vector[size_vector-1].sucursal,vector[size_vector-1].codigo,vector[size_vector-1].ventas);
            
        }
        //printf("temporal %i %i %i\n",temporal.sucursal,temporal.codigo,temporal.ventas);
        
        scanf("%i",&temporal.sucursal);
    }
    
    //al dejar de recibir datos con selection sort hacer orden de + a - ventas, llevar consigo los otros datos
    
    //selection sort djawidja
    
    for(int i = 0; i < size_vector - 1; i++){
        int pos_menor = i;
        for(int j = i + 1; j < size_vector; j++){
            
            // Si el actual tiene MÁS ventas...
            if(vector[j].ventas > vector[pos_menor].ventas) {
                pos_menor = j;
            }
            // Si tienen las MISMAS ventas, pero el actual tiene MENOR código
            else if (vector[j].ventas == vector[pos_menor].ventas) {
                if (vector[j].codigo < vector[pos_menor].codigo) {
                    pos_menor = j;
                }
            }
        }
        
        //Hacer el swap
        if(pos_menor != i){
            datos_productos swap_temp = vector[pos_menor];
            vector[pos_menor] = vector[i];
            vector[i] = swap_temp;
        }
    }
    
    //tabla de ranking
    if(ingresar_datos){
        printf(" _______________________ ________________________\n");
        printf("|     RANKING NACIONAL DE VENTAS POR PRODUCTO     |\n");
        printf("|_______________________ ________________________ |\n");
        printf("|    CODIGO PRODUCTO    | TOTAL UNIDADES VENDIDAS |\n");
        printf("|_______________________|________________________ |\n");
        printf("|                       |                         |\n");
        for(int i=0;i<size_vector;i++){
            printf("| %22i| %23i |\n", vector[i].codigo, vector[i].ventas);
        }
        printf("|_______________________|_________________________|\n");
    }
    else printf("No se Ingresaron Datos.\n");
    
    free(vector);
}