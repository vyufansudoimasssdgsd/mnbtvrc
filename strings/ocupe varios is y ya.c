#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    //ingresar linea completa
    
    char *frase = (char *) malloc (sizeof(char) * 101);
    if( frase == NULL) return EXIT_FAILURE;
    
    printf("hey, ingresa lo de la bodega ");
    scanf(" %100[^\n]",frase);
    
    
    //contar por letra, otro por digito, otro por espacio y lo demás
    
    int contador_letras=0;
    int contador_digitos=0;
    int contador_espacios=0;
    int contador_otros=0;
    
    for(int i=0; frase[i] != '\0' ;i++){
        if( isalpha(frase[i]) ) contador_letras++;
        else if (isdigit(frase[i])) contador_digitos++;
        else if(isspace(frase[i])) contador_espacios++;
        else contador_otros++;
    }
    
    
    //separr en letras, digitos, espacios en blanco y lo demás
    
    printf("contadores: \n letras = %i \n digitos = %i \n espacios = %i \n otros = %i \n",contador_letras,contador_digitos,contador_espacios,contador_otros);
    
    free(frase);
    
    return 0;
}
