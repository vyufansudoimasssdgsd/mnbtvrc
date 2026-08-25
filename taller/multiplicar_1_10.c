#include <stdio.h>

int main()
{
    int n,i;
    
    n=-5;
    
    while (n<0)
    {
        scanf("%i",&n);
    }
    
    for (i=1 ; i <=12 ; i++)
    {
        printf("%i \n",(n*i));
    }
    
    
    
}