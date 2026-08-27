#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 100
int main()
{
    srand(time(NULL));
    
    int vect[size];
    int i,n,cant_max,cant_act,numero_max,numero_act,lost;
    
    
    for (i=0 ; i<size ; i++)
    {
        n=rand()%6;
        n+=1;
        vect[i]=n;
        printf("N°%i = %i\n",i+1,n);
    }
    
    cant_max=1;
    cant_act=1;
    numero_act=vect[0];
    numero_max=vect[0];
    lost=0;
    
    for (i=1 ; i<size ; i++)
    {
        if ( vect[i] == vect[i-1])
        {
            printf("comparando %i e %i \n",vect[i-1],vect[i]);
            cant_act+=1;
            numero_act=vect[i];
        }
        
        if (cant_max < cant_act)
        {
            cant_max=cant_act;
            numero_max=numero_act;
        }
        
        if ( vect[i] != vect[i-1])
        {
            
            lost+=1;
            cant_act=1;
            numero_act=vect[i];
        }
        
        
    }
    
    printf("Racha más larga = %i\n",cant_max);
    printf("Numero repetido de la racha = %i\n",numero_max);
    printf("Veces perdida la racha = %i\n",lost);
    
}