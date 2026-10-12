#include <stdio.h>
#include <stdlib.h>

#define N 8

int comparar_enteros( const void *a, const void *b)
{
	int x=*(int *)a;
	int y=*(int *)b;
	if(x>y)return 1;
	else if (x<y)return -1;
	return 0;
}


void selection_sort( int A[] )
{
    int contador_swaps=0;
    for(int i=0;i<N-1;i++){
        
        int posMenor=i;
        
        for(int k=i+1;k<N;k++){
            
            if(A[k]<A[posMenor]){
                posMenor=k;
            }
            
        }
        
        if(posMenor != i){
            int temporal=A[i];
            A[i]=A[posMenor];
            A[posMenor]=temporal;
            contador_swaps++;
        }
        
    }
    printf("cantidad de swaps en selection_sort = %i\n", contador_swaps);
}

void insertion_sort (int A[])
{
    int contador_swaps=0;
    for(int i=1;i<N;i++){
        int temporal = A[i];
        int k=i-1;
        while ( k>=0 && (temporal < A[k]) )
        {
            A[k+1]=A[k];
            k--;
            contador_swaps++;
        }
        A[k+1]=temporal;
    }
    printf("cantidad de swaps en insertion_sort = %i\n", contador_swaps);
}

void busqueda_lineal(int datos[], int buscado)
{
    int contador_busqueda=0;
    for(int i=0;i<N;i++){
        if(datos[i] == buscado){
            printf("la cantidad de iteraciones en la busqueda_lineal son %i\n",contador_busqueda);
            break;
        }
        else{
            contador_busqueda++;
        }
    }
}

void busqueda_binaria(int datos[],int posBaja, int posAlta, int buscado, int contador_busqueda)
{
    //posicion no valida
    if(posBaja>posAlta) printf("POSICION NO VALIDA\n");
    else{
        int posCentral=(posBaja + posAlta)/2;
        if(buscado == datos[posCentral]){
            printf("la cantidad de iteraciones en la busqueda_binaria son %i\n",contador_busqueda);
        }
        else if (buscado < datos[posCentral]) busqueda_binaria(datos, posBaja, posCentral-1, buscado, contador_busqueda+1);
        else busqueda_binaria(datos, posCentral+1, posAlta, buscado, contador_busqueda+1);
        
        
    }
    
}

int main()
{
    //Parte 1 
    
    int datos[N]= {29,10,14,37,13,5,41,8};
    int datos_2[N]= {29,10,14,37,13,5,41,8};
    int datos_3[N]= {29,10,14,37,13,5,41,8};
    
    
    insertion_sort(datos);
    selection_sort(datos_2);
    
    qsort(datos_3, N, sizeof(int), comparaEnteros);
    
    //vamos a buscar el 29
    
    busqueda_lineal(datos,29);
    busqueda_binaria(datos_2,0,N-1,29,0);
    // en binaria es 1ero el vector, posBaja,posAlta,buscado
    

    return 0;
}
