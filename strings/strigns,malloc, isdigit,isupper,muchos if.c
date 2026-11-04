#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    //leer codigo
    char *codigo = (char *) malloc( sizeof(char) * 20 );
    scanf(" %8[^\n]",codigo);
    
    if( strlen(codigo) != 6){
        printf("CODIGO INVALIDO\n");
        free(codigo);
        return 0;
    }
    //revisar mayus
    
    if( ! isupper(codigo[0]) || ! isupper(codigo[1])  ){
        printf("CODIGO INVALIDO\n"); 
        free(codigo);
        return 0;    
    }
    
    //revisar numeros
    
    if( !isdigit(codigo[2]) || !isdigit(codigo[3]) || !isdigit(codigo[4]) || !isdigit(codigo[5]) ){
        printf("CODIGO INVALIDO\n");
        free(codigo);
        return 0;
    } 
    
    printf("CODIGO VALIDO\n");
    free(codigo);
    
    
    return 0;
}
