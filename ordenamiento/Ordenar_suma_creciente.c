#include <stdio.h>
#include <stdlib.h>

#define N 101

int strg_a_vector(char A[], int B[])
{
    char letra;
    int i,j,num;
    letra='0';
    i=0;
    num=0;
    j=0;
    while (1==1) 
    {
        if(A[i] == '\0') break;
        
        if(A[i] != '+'){
            B[j] =A[i] - '0';
            j++;
        }
        
        i++;
    }
    return j;
}

int comparaEnteros (const void *a, const void *b)
{
    int *ptrA = (int *)a;
    int *ptrB = (int *)b;
    if( *ptrA > *ptrB)
        return 1;
    else if ( *ptrA < *ptrB)
        return -1;
    else 
        return 0;
}

int main()
{
    char A[N],letra;
    int B[N/2],i,size_vector;
    
    //escanear el string, max 100 caracteres
    printf("Ingrese el string");
    scanf("%s",A); //sintaxis vector con characters
    
    //ocupar f(x) void para pasar de strg a vector 
    
    size_vector=strg_a_vector(A,B);
    
    //ordenar con qsort
    
    qsort(B,size_vector,sizeof(int),comparaEnteros);
    //pasar a qsort el tamaño de B real
    
    int j=0;
    //printear ordenado
    for(i=0;1==1;i++)
    {
        letra=A[i];
        if(letra == '\0') break;
        if(i%2==0){
            printf("%i",B[j]); //par
            j++;
        }
        else printf("+");
    }

    return 0;
}
