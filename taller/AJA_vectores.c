#include <stdio.h>

int main()
{
    char clave[20];
    int i, son_iguales;
    
    // nombre [tamaño]
    
    char correcta[]= "Clave123";
    
    scanf("%9s",clave); // al ocupar vectores no utilizar el & '\0'
    
    i=0;
    son_iguales=1; // true
    
    for (i=0 ; i<9 ; i++)
    {
        if (correcta[i] != clave[i])
        {
            son_iguales=0;
        }
        
    }
    if (son_iguales)
    {
        printf("tdoo bien por aca");
    }
    else
    {
        printf("nonoono");
    }
    
    return 0;
}