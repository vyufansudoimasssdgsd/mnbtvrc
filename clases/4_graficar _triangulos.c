#include <stdio.h>


int main()
{
    int n,i,i_2,i_3,n_que_baja,n_que_sube;
    
    scanf("%i",&n);
    
    n_que_baja=n;
    n_que_sube=1;
    
    for (i=0 ; i < n ; i++)
    {
        for (i_2=0 ; i_2 <n_que_sube ; i_2++)
        {
            //hacer un if con si y el otro con no 
            printf("*");
        }
        for (i_3=0 ; i_3 <n_que_baja ; i_3++)
        {
            //hacer un if con si y el otro con no 
            printf(" ");
        }
        printf("\n");
        n_que_sube+=1;
        n_que_baja-=1;
        //cambiar el que baja con el que sube en las 
        //variables para hacerlo de arriba hacia abajo o de abajo hacia arriba
    }   
    
    
}



