#include<stdio.h>

int main()

{
    int n,i,i_2,i_3;
    
    scanf("%i",&n);
    
    for (i=0;i<n;i++)
    {
        if (i%2!=0)
        {
            for (i_2=0; i_2 <n; i_2++)
            {
                if(i_2%2!=0)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        else
        {
            for (i_3=0 ; i_3<n ; i_3++)
            {
                if(i_3%2==0)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
                
            }
        }
        printf("\n");
        
    }
    
    
}

