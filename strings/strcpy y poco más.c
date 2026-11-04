#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main()
{
    //reservar observacion completa
    
    char *observacion = (char *) malloc ( sizeof(char) * 101);
    if( observacion == NULL ) return EXIT_FAILURE;
    
    //guardar observacion completa
    
    scanf(" %100[^\n]",observacion);
    
    //if strlen > 12, strncopy a otra cadena + 3 puntos
    
    if(strlen(observacion) > 12){
        
        char *copia_observacion = (char *) malloc (sizeof(char) * (12+4));
        strncpy(copia_observacion,observacion,12);
        //index -1 
        copia_observacion[12]='.';
        copia_observacion[13]='.';
        copia_observacion[14]='.';
        copia_observacion[15]='\0';
        
        
        printf("observacion = %s , copia_observacion %s ",observacion, copia_observacion);
        free(copia_observacion);
        
    }
    else printf("observacion = %s",observacion);
    
    //else, entera
    
    free(observacion);
    
    return 0;
}
