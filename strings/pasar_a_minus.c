#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char *frase = (char *) malloc (sizeof(char) *121);
    if(frase == NULL) return EXIT_FAILURE;
    
    scanf(" %120[^\n]",frase);
    
    //pasar a minus
    
    for(int i=0;frase[i] != '\0';i++){
        frase[i]=tolower(frase[i]);
    }
    
    if( strstr (frase,("fraude")) != NULL || strstr (frase,("estafa")) != NULL ){
        printf("ALERTA: revisar comentario");
        return 0;
    }
    
    printf("SIN ALERTAS\n");
    
    free(frase);
    return 0;
}
