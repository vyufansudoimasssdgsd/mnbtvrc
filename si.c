#include <stdio.h>

int main()
{
    int n;
    int divisible; // 0 no 1 si 
    
    divisible = 0;
    
    printf("Numero a analizar");
    scanf("%i",&n);
    
    if (n%3== 0)
    {
        divisible = 1;
    }
    
    if (divisible)
    {
        printf("El numero %i SI es divisible",n );
    }
    else
    {
        printf("El numero %i NO es divisible",n);
    }
}