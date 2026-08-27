#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 5


int main()
{
    int vec_1[size];
    int i,n,valor,c_par,c_impar,s_pos,s_neg;
    
    c_par=0;
    c_impar=0;
    s_pos=0;
    s_neg=0;
    
    srand(time(NULL));
    
    for (i=0 ; i<size ; i++)
    {
        n=rand() %101;
        n-=50;
        vec_1[i]=n;
        printf("valor %i = %i\n",(i+1),n);
    }
    
    for (i=0 ; i<size ; i++)
    {
        valor=vec_1[i];
        
        if (valor %2 ==0 )
        {
            c_par+=1;
        }
        else
        {
            c_impar+=1;
        }
        
        if(valor >= 0)
        {
            s_pos+=valor;
        }
        else
        {
            s_neg+=valor;
        }
        
    }
    printf("Numeros pares = %i\n",c_par);
    printf("Numeros impares = %i\n",c_impar);
    printf("Suma numeros positivos = %i\n",s_pos);
    printf("Suma numeros negativos = %i\n",s_neg);
    
}