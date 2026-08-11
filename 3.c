#include <stdio.h>

int main()
{
    //definir variables
    int a;
    int b;
    int c;
    int discriminante;
    
    // entrada
    
    scanf("%i", &a);
    scanf("%i", &b);
    scanf("%i", &c);
    
    //procesar
    
    discriminante = (b*b) - (4*a*c);
    
    if (discriminante == 0)
    {
        printf("Tiene una única solución");
    }

    if (discriminante > 0)
    {
        printf("Tiene 2 soluciones");
    }

    if (discriminante < 0)
    {
        printf("No tiene soluciones");
    }

    return 0;
}
