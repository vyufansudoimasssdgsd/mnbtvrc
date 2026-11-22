/******************************************************************************

Abre sucio.txt (lectura) y limpio.txt (escritura).

Usa un while con fgetc para leer carácter por carácter.

Si el carácter leído NO es un espacio (' '), usa fputc para escribirlo en el archivo limpio.

Cierra ambos archivos.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *archivo = fopen("sucio.txt","r");
    if(archivo == NULL)return EXIT_FAILURE;
    
    FILE *archivo_2 = fopen("limpio.txt","w");
    if(archivo_2 == NULL)return EXIT_FAILURE;
    
    char c;
    
    while( ( c=fgetc(archivo) ) != EOF){
        if(c != ' ')fputc(c,archivo_2);
    }
    
    fclose(archivo);
    fclose(archivo_2);
    

    return 0;
}
