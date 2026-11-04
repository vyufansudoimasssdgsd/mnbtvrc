#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void a_minus(char A[])
{
    for(int i=0;A[i] != '\0';i++){
        A[i] = tolower(A[i]);    
    }
}

int main()
{
    char *nombre = (char *) malloc( sizeof(char) * 20);
    char *apellido = (char *) malloc( sizeof(char) * 20);
    
    if( nombre == NULL) return EXIT_FAILURE;
    if( apellido == NULL) return EXIT_FAILURE;
    
    scanf(" %[^\n]",nombre);
    scanf(" %[^\n]",apellido);
    
    a_minus(nombre);
    a_minus(apellido);
    
    //concatenar jaajajaja
    
    char *correo = (char *) malloc (sizeof(char) * 55) ;
    
    strcpy(correo,nombre);
    strcat(correo,".");
    strcat(correo,apellido);
    strcat(correo,"@alumnos.cl");
    
    printf("%s",correo);
    
    free(nombre);
    free(apellido);
    free(correo);
    
    return 0;
}
