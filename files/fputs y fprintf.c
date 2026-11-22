/******************************************************************************
Abre diario.txt en modo append ("a"), que permite agregar al final.

Usa fputs para escribir un separador visual, por ejemplo: "------------------------\n".

Pide al usuario el día (ej: "Lunes") y una frase de lo que hizo.

Usa fprintf para guardar: "Día: %s | Frase: %s\n".

Cierra el archivo.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *archivo = fopen("diario.txt","at");
    
    fputs("------------------------\n",archivo);
    
    char dia[11];
    char frase[50];
    
    printf("Ingrese usuario el dia ");
    scanf(" %10[^\n]",dia);
    printf("Bueno, ahora ingresa la frase del dia ");
    scanf(" %49[^\n]",frase);
    
    fprintf(archivo,"Dia: %s Frase: %s\n",dia,frase);
    
    fclose(archivo);
    return 0;
}
