#include <stdio.h>

struct tipoVehiculo
{
    char marca[21];
    int anio;
}; // ACA VA un ";"



int main()
{
    struct tipoVehiculo Mazda;
     //recordar espacio entre %% y Sin & el char 
    scanf("%20[^\n] %i",Mazda.marca,&Mazda.anio);
    
    printf("Su atuto es un %s del anyo %i", Mazda.marca, Mazda.anio);
    

    return 0;
}
