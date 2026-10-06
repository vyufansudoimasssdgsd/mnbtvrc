#include <stdio.h>
#include <stdbool.h>

bool es_hyperpar( unsigned long n)
{
    if (n == 0 ) return true;
    else if((n%10)%2 == 0) return es_hyperpar(n/10);
    else return false;
    
    
}

int main()
{
    unsigned long numero;
    scanf("%lu",&numero);
    
    if(es_hyperpar(numero)) printf("Es hyperpar");
    else printf("No es hyperpar");
    
    return 0;
}




