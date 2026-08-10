/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>


int main()
{
    //declarar
    int bisiesto;
    int verdadero;
    verdadero = 0;
    
    //entrada
    printf("ingrese el año a analizar");
    scanf ("%i", &bisiesto);
    
    //procesar
    
    if ( ((bisiesto%4 == 0) && (bisiesto%100 != 0)) || (bisiesto%400 == 0) )
    {
        verdadero = 1 ;
    }
    
    if (verdadero == 1)
    {
        printf("El año %i SI es bisiesto", bisiesto);
    }
    
    if (verdadero == 0)
    {
        printf("El año %i NO es bisiesto", bisiesto);  
    }
    
    return 0;
}