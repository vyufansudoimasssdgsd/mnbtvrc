#include <stdio.h>

typedef struct 
{
    char calle[30];
    int numero;
} tipoDireccion;



typedef struct
{
    char nombre[20];
    char rut[13];
    tipoDireccion direccion;
    
} tipoCliente;

void registrarClientes (tipoCliente *c)
{
    printf("ingrese el nombre ");
    scanf(" %19[^\n]",c->nombre);
    
    printf("ingrese el rut ");
    scanf(" %12[^\n]",c->rut);
    
    printf("ingrese la calle ");
    scanf(" %29[^\n]",c->direccion.calle);
    
    printf("ingrese el numero ");
    scanf(" %i",&c->direccion.numero);
    
    
}

void mostrarFicha (tipoCliente c)
{
    printf("Su nombre es %s \nsu rut es %s\n la calle es %s\n el numero es %i\n",c.nombre,c.rut,c.direccion.calle,c.direccion.numero);
    
    
}


int main()
{
    tipoCliente juan;
    
    registrarClientes(&juan);
    mostrarFicha(juan);
    return 0;
}
