#include <stdio.h>

int es_factorial(int);
int main()

{
    int n;
    
    printf("ingrese el numero para calcularle el factorial");
    scanf("%i",&n);
    
    printf("El factorial de %i es de %i",n,es_factorial(n));
    
}

int es_factorial(int n) // el 1er int es del return, el de adentro es de lo ingesado a la f(x)
{
    int i,producto;
    producto=1;
    
    if (n==0)
    {
        producto=1;
    }
    
    for (i=1; i<=n ;i++)
    {
        producto*=i;
        printf("%i y %i \n",i,producto);
    }
    
    return producto;
}
