#include <stdio.h>

int imprimir_triangulitos(int);

int main()
{
    int n;
    scanf("%i",&n);
    imprimir_triangulitos(n);
    
}
//la idea es que la f(x) busque manejar todo de un sector en especifico
int imprimir_triangulitos(int n)
{
    int i,j;
    for (i=n;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

