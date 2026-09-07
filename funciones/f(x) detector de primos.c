#include <stdio.h>

int es_primo(int n)
{
    int divisores,i;
    divisores=1;
    
    for (i=1;i<n;i++)
    {
        if(n%i==0)
        {
            divisores++;
        }
    }
    
    if (divisores < 3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{
    
    int n1;
    scanf("%i",&n1);
    
    printf("aja %i",es_primo(n1));
    
}



