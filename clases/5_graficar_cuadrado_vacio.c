#include <stdio.h>

int main()
{
    int n, menos_2,i,i_2,i_3;
    
    scanf("%i",&n);
    
    menos_2 = n-2;
    
    for (i_2 =0 ; i_2<n ; i_2++)
    {
        printf("*");
    }
    printf("\n");
    for (i=0 ; i<menos_2 ; i++)
    {
        printf("*");
        for (i_3=0 ; i_3<menos_2 ;i_3++ )
        {
            printf(" ");
        }
        printf("*");
        
        printf("\n");
    }
    
    for (i_2 =0 ; i_2<n ; i_2++)
    {
        printf("*");
    }
    printf("\n");
    
    
}