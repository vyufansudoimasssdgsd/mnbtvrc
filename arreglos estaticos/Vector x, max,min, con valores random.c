#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10


int main()
{
    int vect_1[size];
    int n,i,max_v,min_v,suma_vector,c_sobre;
    float x;
    
    max_v=0;
    min_v=11;
    suma_vector=0;
    c_sobre=0;
    
    srand(time(NULL));
    
    for (i=0 ; i<10 ; i++)
    {
        //printf("ingrese un N° [1,10]\n");
        do
        {
            //scanf("%i",&n);
            n=(rand() % 10)+1; // rand() es entre 0 y 9, le sumo 1 y es entre 1 y 10
            if (n>10 || n<1)
            {
                printf("MAL\n");
            }
        }
        while (n>10 || n<1);
        printf("Numero creado =%i\n",n);
        vect_1[i]=n;
    }
    for (i=0 ; i<10 ; i++)
    {
        if (vect_1[i] > max_v)
        {
            max_v=vect_1[i];
        }
        if (vect_1[i] < min_v)
        {
            min_v=vect_1[i];
        }
        suma_vector+=vect_1[i];
    }
    
    x=suma_vector/10;
    
    for (i=0 ; i<10 ; i++)
    {
        if (vect_1[i] > x)
        {
            c_sobre+=1;
        }
    }
    
    printf("Maximo = %i\n",max_v);
    printf("Minimo = %i\n",min_v);
    printf("Promedio = %f\n",x);
    printf("Cantidad de valores que están por sobre el promedio = %i\n",c_sobre);
    
    //vect_1[i]=rand() % 10;
    
    
}