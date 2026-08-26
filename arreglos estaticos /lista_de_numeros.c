#include <stdio.h>
#include <stdlib.h>
#define size 1001

int main()
{
    int n, i,j,size_user, dato,max,flag_cre; 
    int list [size];
    
    size_user=-1;
    max=-1;
    flag_cre=1; //true 
    
    while (size_user <0){
    printf("tamaño ?");
    scanf("%i",&size_user);
    }
    
    for (i=1 ; i<= size_user ; i++ )
    {
        printf("dato N°%i ",i);
        scanf("%i",&dato);
        list[i]=dato;
    }
    
    for (j=1 ; j<= size_user ; j++ )
    {
        dato=list[j];
        if (j>1)
        {
            if (list[j] < list[j-1])
            {
                flag_cre=0;   //false
            }
            if (abs(list[j] - list[j-1]) > max)
            {
                
                max=abs(list[j] - list[j-1]);
            }
        }
    }
    
    printf("La maxima diferencia entre 2 numeros es de = %i\n",max);
    if (flag_cre){
    printf("Si es creciente");
    }
    else{
    printf("No es creciente");
    }
}
