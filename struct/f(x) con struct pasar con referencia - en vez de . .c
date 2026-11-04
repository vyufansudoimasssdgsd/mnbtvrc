#include <stdio.h>

typedef struct
{
    char nombre[20];
    float precio;
} tipoProducto;


void aplicarDescuento (tipoProducto *p, float porcentaje)
{
    p->precio=p->precio*porcentaje;
}

int main()
{
    tipoProducto qwerty;
    
    scanf("%19[^\n] %f",qwerty.nombre,&qwerty.precio);
    
    printf("El precio de %s es de %f \n",qwerty.nombre,qwerty.precio);
    
    aplicarDescuento(&qwerty,0.8);
    
    printf("El NUEEEVO precio de %s es de %f \n",qwerty.nombre,qwerty.precio);
    
    

    return 0;
}
