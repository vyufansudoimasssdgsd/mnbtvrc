#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    // guardar toda la info 1ero
    
    char *etiqueta = (char *) malloc(sizeof(char) * 101);
    if(etiqueta == NULL) return EXIT_FAILURE;
    
    
    //escanear toda la info
    
    scanf("%100[^\n]",etiqueta);
    
    // ocupar strchr para buscar el "-"
    
    char *pos_guion= strchr(etiqueta, '-');
    
    //una vez encontrado, te dan un puntero,restalo con el vector y asi posicion - 
    if( pos_guion != NULL){
        // en base posicion del guion, +1 hasta el final para saber el resto 
        int pos_index_guion = pos_guion - etiqueta;
        
        //crear una copia del prefijo
        char *prefijo = (char *) malloc (sizeof(char) * (pos_index_guion+1) );
        if (prefijo == NULL) return EXIT_FAILURE;
        
        
        //copiar todo antes del guion , este agrega el '\0'
        prefijo[0]='\0';
        strncat(prefijo,etiqueta,pos_index_guion);
        
        //crear copia del resto de la palabra
        
        char *resto = (char *) malloc ( sizeof(char) * ( (strlen(etiqueta)) - pos_index_guion ) );
        if( resto == NULL ) return EXIT_FAILURE;
        
        
        //que copie lo que esta adelante del guion y ya
        strcpy(resto,pos_guion +1 );
        
        printf("el prefijo = %s y el resto del guion es %s ",prefijo,resto);
        free(prefijo);
        free(resto);
        
    }
    else{
        printf(" NO se encontro el guion");
    }
    
    free(etiqueta);
    
    return 0;
}
