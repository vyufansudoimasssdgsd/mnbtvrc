/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    //Declarar variables
    float numero_1;
    float numero_2;
    float resultado;
    char opcion;
    
    //entrada de datos
    printf("ingrese numero 1");
    scanf("%f", &numero_1);
    
    printf("ingrese numero 2");
    scanf("%f", &numero_2);
    
    printf("ingrese la opcion de s,r,d,m");
    scanf(" %c", &opcion); 
    
    //procesar los datos
    
    switch (opcion)
    {
        case 's' :
            resultado = numero_1 + numero_2;
            break;
        case 'r' :
            resultado = numero_1 - numero_2;
            break;
        case 'd' :
            resultado = numero_1 / numero_2;
            break;
        case 'm' :
            resultado = numero_1 * numero_2;
            break;
    }
    
    printf("el resultado es %f", resultado);

    return 0;
}
