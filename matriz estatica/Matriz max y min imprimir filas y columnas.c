#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 5
#define N 5
int main()
{
    int matriz[M][N];
    int i,j,n,c_fila,c_columna,max_fila,max_columna,index_f,index_c;
    
    max_columna=0;
    max_fila=0;
    index_c=0;
    index_f=0;
    
    srand(time(NULL));
    
    //Poblar la matriz con datos basura
    
    for (i=0 ; i <M ; i++) // recorre por filas porque i estatico j dinamico 
    {
        for (j=0 ; j< N ; j++)
        {
            n=rand()%9;
            n+=1;
            matriz[i][j]=n;
            printf("%i  ",matriz[i][j]);
        }
        printf("\n\n");
    }
    
    //Contar, buscar y definir la fila con más 1
    
    for (i=0 ; i <M ; i++) // recorre por filas porque i estatico j dinamico 
    {
        c_fila=0;
        
        for (j=0 ; j< N ; j++)
        {
            if (matriz[i][j]==1)
            {
                c_fila+=1;
            }
        }
        if (c_fila > max_fila)
        {
            max_fila=c_fila;
            index_f=i;
        }
        
    }
    
    //Contar, buscar y definir la Columna con más 1
    
    for (j=0 ; j <N ; j++) // recorre por Columnas porque i dinamico j estatico 
    {
        c_columna=0;
        for (i=0 ; i< M ; i++)
        {
            if (matriz[i][j]==1)
            {
                c_columna+=1;
            }
        }
        if (c_columna > max_columna)
        {
            max_columna=c_columna;
            index_c=j;
        }
        
    }
    
    printf("------------------------------\n\n");
    
    // Imprimir fila con más 1
    
    for (i=0 ; i <M ; i++) // recorre por filas porque i estatico j dinamico 
    {
        if ( i == index_f)
        {
            for (j=0 ; j< N ; j++)
            {
               printf("%i ",matriz[i][j]); 
            }
        }
    }
    
    printf("\n\n------------------------------\n\n");
    // Imprimir columna con más 1
    
    for (j=0 ; j<N ; j++) // recorre por columnas porque i dinamico j estatico 
    {
        if ( j == index_c)
        {
            for (i=0 ; i<M ; i++)
            {
               printf("%i\n",matriz[i][j]); 
            }
        }
    }
    
    printf("\n------------------------------\n\n");
    printf("Fila con más unos: %i (tiene %i unos)\n",index_f+1,max_fila);
    printf("Columna con más unos: %i (tiene %i unos)\n",index_c+1,max_columna);
    
}