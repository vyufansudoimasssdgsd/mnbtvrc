#include <stdio.h>

int contar_digitos(int);

int main()
{
    int n;
    scanf("%i",&n);
    
    printf("la cantidad de digitos de %i son %i",n,contar_digitos(n));
}

int contar_digitos(int n)
{
    int i,digitos;
    digitos=0;
    
    if(n<0)
    {
        n=n*-1;
    }
    
    if (n==0) //te falto esto master
    {
        digitos++;
    }
    
    
    while (n>0)
    {
        n=n/10;
        digitos++;
    }
    
    
    return digitos;
}

