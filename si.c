#include <stdio.h>

int main ()
{
    float nota;
    
    printf("Nota a ingresar");
    scanf("%f",&nota);
    
    if (nota>=4.0 && nota <=7.0)
    {
        printf("Aprobaste");
    }
    else if (nota <4.0 && nota >=1.0)
    {
        printf("REProbaste porro");
    }
    else
    {
        printf("ajajja, error");
    }
}