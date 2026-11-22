#include <stdio.h>
#include <stdlib.h>


int main()
{
    /*
    
    
    */
    
    //Abre mensaje.txt en modo lectura ("r") y mensaje_cifrado.txt en modo escritura ("w").
    FILE *archivo = fopen("mensaje.txt","rt");
    FILE *archivo_2 = fopen("mensaje_cifrado.txt","wt");
    
    //Usa un bucle while con fgetc para leer el archivo original carácter por carácter.
    
    char c;
    
    while( (c=fgetc(archivo)) != EOF)
    { //Usa un bucle while con fgetc para leer el archivo original carácter por carácter.
        c++;
        
        //Si el carácter no es el fin de archivo (EOF), usa fputc para escribir el carácter "cifrado" (el mismo carácter + 1) en el archivo nuevo.
        fputc(c,archivo_2);
        
    }
    
    //Cierra ambos archivos.
    fclose(archivo);
    fclose(archivo_2);

    return 0;
}
