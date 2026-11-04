#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    
    //tomar todas la frases
    
    char *cadena = (char *) malloc ( sizeof(char) * 1000);
    if( cadena == NULL) return EXIT_FAILURE;
    scanf("%[^\n]",cadena);
    
    //sacar tamaño real
    int size=0;
    while (cadena[size] != '\0')
    {
        size++;
    }
    // size no cuenta NULL
    
    cadena = (char *) realloc(cadena, sizeof(char) * size);
    if( cadena == NULL ) return EXIT_FAILURE;
    
    //convertir todo a minuscula 
    
    for(int i=0;i<size;i++){
        cadena[i]=tolower(cadena[i]);
    }
    
    //contar vocales, total letras+caracteris == size - espacios
    //contar no espacios
    int contar_vocales=0;
    int contador_caracteres_letras=0;
    for(int i=0;i<size;i++){
        if(isalpha(cadena[i]))contador_caracteres_letras++;
        if(cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u') contar_vocales++;
    }
    
    
    printf("DV = %.2f",(contar_vocales/(contador_caracteres_letras + 0.0))*100);
    
    
    return 0;
}
