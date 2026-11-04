#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *frase_usuario= (char *) malloc (sizeof(char) * 9);
    
    if(frase_usuario == NULL) return EXIT_FAILURE;
    scanf(" %8[^\n]",frase_usuario);
    
    char frase_oficial[9] ="VERANO26"; 
    
    if(strcmp(frase_usuario,frase_oficial) == 0) printf("DESCUENTO APLICADO");
    else printf("CODIGO INVALIDO");
    
    free(frase_usuario);
    return 0;
}
