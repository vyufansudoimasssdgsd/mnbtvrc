#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sumar(int vector[],int i,int largo,int acumulador)
{
    if(i<largo)
    {
        acumulador=+vector[i];
        i++;
        sumar(vector,i,largo,acumulador);
    }
    else{
        printf("acumulador= %i",acumulador);
    }
}

int main()
{
    srand(time(NULL));
    int largo,i,j,acumulador;

    scanf("%i",&largo);
    
    int vector[largo];
    
    for(i=0;i<largo;i++){
        vector[i]=rand()%10;
        printf("%i",vector[i]);
    }
    printf("\n");
    
    acumulador=0;
    sumar(vector,j,largo,acumulador);

    return 0;
}
