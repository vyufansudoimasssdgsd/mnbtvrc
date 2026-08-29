#include <stdio.h>

#define N 3

int main()
{
    int A[N][N],B[N*N];
    int i,j,n,k,suma_constante,suma_constante_referencial,es_magico,contador,meta_contador;
    
    contador=0;
    meta_contador=N*N;
    suma_constante=0;
    suma_constante_referencial=(N*((N*N)+1))/2;
    es_magico=1; //
    
    printf("suma_constante_referencial es %i\n",suma_constante_referencial);
    
    //Poblar Matriz A
    
    printf("-----------------------\n");
    for (i=0 ; i<N ; i++)
    {
        for(j=0 ; j<N ;j++)
        {
            printf("Ingrese el numero a%i%i ",i+1,j+1);
            scanf("%i",&n);
            A[i][j]=n;
        }
    }
    printf("-----------------------\n");
    
    //Printearla porque soy un ser visual
    for (i=0 ; i<N ; i++)
    {
        for(j=0 ; j<N ;j++)
        {
            printf("%i ",A[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------\n");
    
    //Crear vector B[N*N] para revisar el invervalo despues
    
    for (i=0 ; i<N*N ; i++)
    {
        B[i]=i+1;
    }
    //Compararla con el vector B[N*N] para 
    //revisar que esten los valores en el intervalo [1..N^2]
    // Y que M=si
    
    for (i=0 ; i<N ; i++)
    {
        for(j=0 ; j<N ;j++)
        {
            for(k=0 ; k<N*N ; k++)
            {
                if (A[i][j] == B[k]) // si es que lo pilla
                {
                    contador+=1;
                    B[k]=-1;
                }    
            }
        }
    }
    
    if (contador != meta_contador)
    {
        es_magico=0; //marcado
    }
    
    //Revisar que la suma de filas sea igual a M
    
    for (i=0 ; i<N ; i++)
    {
        suma_constante=0;
        for(j=0 ; j<N ;j++)
        {
            suma_constante+=A[i][j];
        }
        if (suma_constante != suma_constante_referencial)
        {
            es_magico=0;
        }
    }
    
    //Revisar que la suma de columnas sea igual a M
    
    for (i=0 ; i<N ; i++)
    {
        suma_constante=0;
        for(j=0 ; j<N ;j++)
        {
            suma_constante+=A[j][i];
        }
        if (suma_constante != suma_constante_referencial)
        {
            es_magico=0;
        }
    }
    
    //Revisar que la suma de la diagonal sea M
    
    suma_constante=0;
    for (i=0 ; i<N ; i++)
    {
        for(j=0 ; j<N ;j++)
        {
            if (i == j)
            {
                suma_constante+=A[i][j];    
            }
        }
    }
    if (suma_constante != suma_constante_referencial)
    {
        es_magico=0;
    }
    
    // Revisar que la suma de la antidiagonal sea M
    suma_constante=0;
    for (i=0 ; i<N ; i++)
    {
        for(j=0 ; j<N ;j++)
        {
            if (i+j == N-1)
            {
                suma_constante+=A[i][j];    
            }
        }
    }
    if (suma_constante != suma_constante_referencial)
    {
        es_magico=0;
    }
    
    if (es_magico)
    {
        printf("El cuadrado es magico, felicidades");    
    }
    else
    {
        printf("NO hay magia para ti");
    }
    
}