#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 100
#define max_size 200

int main()
{
    int vect_1[size], vect_2[size], vect_3[max_size];
    int i,j,k,dato,n,n_2,min_v1,max_v1,min_v2,max_v2,ordenado,chu;
    
    srand(time(NULL));
    min_v1=100;
    min_v2=100;
    max_v1=-1;
    max_v2=-1;
    
    
    printf("Ingrese la cantidad de datos para el 1er vector: ");
    scanf("%i",&n);
    
    
    // datos de 1er vecto
    for (i=0 ; i<n ; i++)
    {
        printf("ingrese el dato [0,99]: "); //agregar aca verificador de que sea entre el rango permitido
        do
        {
            scanf("%i",&dato);
            if (dato < 0 || dato >99)
            {
                printf("dato no valido, vuelva a intentar");
            }
        }
        while (dato < 0 || dato >99);
        vect_1[i]=dato;
        printf("dato ingresado = %i\n",vect_1[i]);
    }
    
    //datos 2do vector, son random 
    
    printf("Ingrese la cantidad de datos para el 2do vector: ");
    scanf("%i",&n_2);
    
    for (i=0 ; i<n_2 ;i++)
    {
        vect_2[i]=rand() % 100;
        printf("dato creado es %d\n",vect_2[i]);
    }
    
    // sacar max y min de v1
    
    for (i=0 ; i<n ; i++)
    {
        if (vect_1[i] > max_v1)
        {
            max_v1=vect_1[i];
        }
        if (vect_1[i] < min_v1)
        {
            min_v1=vect_1[i];
        }
    }
    
    printf("minimo v1 = %i\n",min_v1);
    printf("maximo v1 = %i\n",max_v1);
    
    // max y min de v2
    
    for (i=0 ; i<n_2 ; i++)
    {
        if (vect_2[i] > max_v2)
        {
            max_v2=vect_2[i];
        }
        if (vect_2[i] < min_v2)
        {
            min_v2=vect_2[i];
        }
    }
    
    printf("minimo v2 = %i\n",min_v2);
    printf("maximo v2 = %i\n",max_v2);
    
    printf("ahora voy a unir los 2 en un vector unificado y ordenado...\n");
    
    for (i=0 ; i < n ; i++)
    {
        vect_3[i]=vect_1[i];
    }
    
    for (i=n ; i < n+n_2 ; i++)
    {
        vect_3[i]=vect_2[i-n];
    }
    
    printf("unidos..., mira, esta desordenado\n");
    printf("[");
    for (i=0 ; i < (n+n_2) ; i++)
    {
        if (i != n+n_2-1)
        {
            printf("%i,",vect_3[i]);
        }
        else if ( i== n+n_2-1)
        {
            printf("%i",vect_3[i]);
        }
    }
    printf("]");
    
    printf("bueno, a ordenarlos...\n");
    
    for (j=0 ; j < n+n_2-1 ; j++)
    {
        ordenado=0;
        for (k=0 ; k < n+n_2-1 ; k++)
        {
            if (vect_3[k] > vect_3[k+1])
            {
                chu=vect_3[k]; // se copia el grande a una variable temporal
                
                vect_3[k]=vect_3[k+1]; // se pone el menor donde deberia
                
                vect_3[k+1]=chu; // con la temporal se pone el mayor donde deberia
                
                ordenado =1;
            }
        }
        
        if (ordenado == 0)
        {
            break;
        }
    }
    
    printf("Mira, ya los ordene, que taL ?[");
    for (i=0 ; i < (n+n_2) ; i++)
    {
        if (i != n+n_2-1)
        {
            printf("%i,",vect_3[i]);
        }
        else if ( i== n+n_2-1)
        {
            printf("%i",vect_3[i]);
        }
    }
    printf("]");
}