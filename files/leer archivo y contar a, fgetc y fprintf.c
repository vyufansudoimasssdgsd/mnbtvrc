#include <stdio.h>
#include <stdlib.h>

int main()
{
    // crear puntero
    FILE *archivo_x;
    
    //leer archivo
    archivo_x = fopen("entrada_cre.txt","rt");
    //ver que se haya creado correctamente 
    if(archivo_x == NULL){
        printf("Error al abrir modo lectura\n");
        exit(1);
    }
    
    char caracter_leido;
    int contador_a = 0;
    //ver caracter por caracter que sea == a 'a'
    while ( (caracter_leido = fgetc(archivo_x)) != EOF){
        if(caracter_leido == 'a') contador_a ++;
    }
    
    //cerrar archivo 
    fclose(archivo_x);
    
    printf("Leidos == %i",contador_a);
    return 0;
}
