#include <stdio.h>
#include <stdlib.h>

#define N 12

int insertion_sort( int A[], int size)
{
    int swaps = 0;
    for(int i=1;i<size;i++){
        int temporal=A[i];
        int k=i-1;
        
        while( (k>=0) && (A[k] > temporal) ){
            A[k+1]=A[k];
            k--;
            swaps++;
        }
        
        A[k+1]=temporal;
        
    }
    return swaps;
    
}

int selection_sort( int A[], int size)
{
    int swaps=0;
    for(int i=0;i<size-1;i++){
        int posMenor=i;
        for(int k=i+1;k<size;k++){
            if(A[posMenor]>A[k])posMenor=k;
        }
        if(posMenor != i){
            int temporal=A[posMenor];
            A[posMenor]=A[i];
            A[i]=temporal;
            swaps++;
        }
        
    }
    return swaps;
    
}

int comparar_enteros_asciende(const void *a, const void *b)
{
    int x=*(int *)a;
    int y=*(int *)b;
    if(x>y)return 1;
    else if(x<y)return -1;
    return 0;
    
}

int comparar_enteros_desciende(const void *a, const void *b)
{
    int x=*(int *)a;
    int y=*(int *)b;
    if(x<y)return 1;
    else if(x>y)return -1;
    return 0;
    
}

int b_search_normal( int A[], int size, int buscado )
{
    int posBaja=0, posAlta=N-1, posCentral;
    while (posBaja <= posAlta){
        
        posCentral=(posBaja + posAlta) / 2;
        if( A[posCentral] == buscado) return posCentral;
        else{
            if(buscado < A[posCentral] )posAlta = posCentral-1;
            else posBaja = posCentral+1;
        }
    }
    return -1;
    
}

int b_search_recursivo_mejor(int A[],int posBaja, int posAlta,int buscado)
{
    if(posBaja>posAlta)return -1;
    else{
        int posCentral=(posBaja+posAlta)/2;
        if(buscado==A[posCentral]) return posCentral;
        else{
            if(buscado < A[posCentral]){ // cambia la alta por central -1
                return b_search_recursivo_mejor(A,posBaja,posCentral-1,buscado);
            }
            else return b_search_recursivo_mejor(A,posCentral+1,posAlta,buscado);
        }
        
    }
    
    
}

int main()
{
    int num[N]={34, 3, 65, 12, 52, 8, 46, 21, 59, 15, 40, 27};
    int num_2[N]={34, 3, 65, 12, 52, 8, 46, 21, 59, 15, 40, 27};
    int num_3[N]={34, 3, 65, 12, 52, 8, 46, 21, 59, 15, 40, 27};
    int num_4[N]={34, 3, 65, 12, 52, 8, 46, 21, 59, 15, 40, 27};
    
    qsort(num_3,N,sizeof(int),comparar_enteros_asciende);
    qsort(num_4,N,sizeof(int),comparar_enteros_desciende);
    
    printf("swaps en insertion_sort, el penca, %i \n",insertion_sort(num,N));
    printf("swaps en selection_sort, el bacan, %i \n",selection_sort(num_2,N));
    
    printf("qsort asciende = ");
    for(int i=0;i<N;i++)
    {
        printf("%i ",num_3[i]);
    }
    
    printf("\nqsort desciende = ");
    for(int i=0;i<N;i++)
    {
        printf("%i ",num_4[i]);
    }
    
    //vamos a buscar el 12
    
    printf("\nposicion en b_search_normal = %i",b_search_normal(num,N,12));
    
    printf("\nposicion en b_search_bacan = %i",b_search_recursivo_mejor(num,0,N-1,12));
    
    int buscado_b_search=12;
    int * resultado_b_search=(int *) bsearch(&buscado_b_search,num,N,sizeof(int),comparar_enteros_asciende);
    printf("\nposicion en b_search_funcion = %i", resultado_b_search - num );
    
    
    return 0;
}