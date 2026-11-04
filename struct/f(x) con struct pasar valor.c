#include <stdio.h>

typedef struct
{
    float base;
    float altura;
} tipoRectangulo;

//recordar que esto no es como los vectores, estas pasando el valor, no referencia
void mostrarArea (tipoRectangulo r)
{
    float Area = r.base * r.altura;
    
    printf("El area del rectangulo es de %f",Area);
}

int main()
{
    tipoRectangulo ladrillo;
    
    printf("ingrese la base ");
    scanf("%f",&ladrillo.base);
    
    printf("ingrese la altura ");
    scanf("%f",&ladrillo.altura);
    
    mostrarArea(ladrillo);

    return 0;
}
