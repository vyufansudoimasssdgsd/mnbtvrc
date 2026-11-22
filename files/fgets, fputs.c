#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 101

int main()
{
    /*
    Abre log.txt en lectura y errores.txt en escritura.

    Usa un bucle while con fgets para leer el archivo línea por línea.
    
    Dentro del bucle, usa strstr para ver si la línea contiene la palabra "ERROR".
    
    Si la contiene, usa fputs para escribir esa línea completa en errores.txt.
    
    ¿Por qué estas funciones? fgets lee líneas completas (respetando los espacios) y fputs escribe textos completos de manera directa.
    */
    
    FILE *archivo =fopen("log.txt","rt");
    FILE *archivo_2 = fopen("errores.txt","wt");
    
    char linea[N];
    //fgets se compara con NULL, fgetc con EOF
    while( (fgets(linea,100,archivo)) != NULL){
        if(strstr(linea,"ERROR")){
            fputs(linea,archivo_2);
        }
    }
    
    
    fclose(archivo);
    
    return 0;
}
