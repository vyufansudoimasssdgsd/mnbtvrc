#include <stdio.h>
#define size 10

int main()
{
    int i,j,n,index;
    char vect[size] ;
    char pal,sube,baja,asked;
    
    index=-1;
    printf("numero de caracteres ?");
    scanf("%i",&n);
    
    for (i=0 ; i<n ; i++)
    {
        printf("caracter a ingresar ?");
        scanf(" %c",&pal);
        vect[i]=pal;
    }
    
    j=n-1;
    i=0;
    while (i < j)
    {
        sube=vect[i];
        baja=vect[j];
        vect[i]=baja;
        vect[j]=sube;
        j--;
        i++;
    }
    
    printf("caracter a buscar ?");
    scanf(" %c",&asked);
    
    printf("vector dado vuelta = ");
    for (i=0 ;i<n ; i++)
    {
        printf("%c",vect[i]);
        if (vect[i] == asked)
        {
            index = i;
        }
    }
    
    printf("\nel indice del buscado es %i",index);
}