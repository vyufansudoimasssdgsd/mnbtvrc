#include <stdio.h>
#include <stdlib.h>

int comparar_enteros(const void *a, const void *b)
{
    long int x=*(int *)a;
    long int y=*(int *)b;
    if(x>y)return -1;
    else if(x<y)return 1;
    return 0;
}

int binary_search_recursiva_posicion(long int A[], int size, int pos_baja, int pos_alta,long int buscado)
{
    if(pos_baja>pos_alta)return -1;
    int pos_central=(pos_baja+pos_alta)/2;
    if(A[pos_central] == buscado)return pos_central;
    else{ //esta al reves porque pidieron ordenarlo de + a - el bseach 
        if(A[pos_central]>buscado) return binary_search_recursiva_posicion(A,size,pos_central+1,pos_alta,buscado);
        else return binary_search_recursiva_posicion(A,size,pos_baja,pos_central-1,buscado);
    }
}

int binary_search_recursiva_swaps(long int A[], int size, int pos_baja, int pos_alta,long int buscado)
{
    if(pos_baja>pos_alta)return -10000;
    int pos_central=(pos_baja+pos_alta)/2;
    if(A[pos_central] == buscado)return 0;
    else{ //esta al reves porque pidieron ordenarlo de + a - el bseach 
        if(A[pos_central]>buscado) return 1 + binary_search_recursiva_swaps(A,size,pos_central+1,pos_alta,buscado);
        else return 1 + binary_search_recursiva_swaps(A,size,pos_baja,pos_central-1,buscado);
    }
}

long int selection_sort(long int A[], int size)
{
    int swaps=0;
    for(int i=0;i<size-1;i++){
        int posMenor=i;
        for(int k=i+1;k<size;k++){
            if(A[posMenor]<A[k]) posMenor=k;
        }
        if(posMenor != i){
            long int temporal=A[posMenor];
            A[posMenor]=A[i];
            A[i]=temporal;
            swaps++;
        }
    }
    return swaps;
}

int busqueda_lineal(long int A[], int size, long int buscado)
{
    for(int i=0;i<size;i++){
        if(A[i] == buscado)return i;
    }
    return -1;
}

int invertir(int n, int rev)
{
    if (n == 0) {
        return rev;
    }
    return invertir(n / 10, rev * 10 + n % 10);
}

int es_capicua(int n)
{
    if (n < 0) return 0;          // los negativos no se consideran capicúa
    return n == invertir(n, 0); // el == devuelve 0 o 1
}



int main()
{
    int N;
    // ingresar size de vector
    do{
        printf("ingrese el tamaño del vector ");
        scanf("%i",&N);
    }while (N<1 || N>50);
    
    long int ventas[N];
    
    //un for con cada venta registrada
    
    for(int i=0;i<N;i++){
        printf("ingrese venta N°%i ",i+1);
        scanf("%ld",&ventas[i]);
    }
    
    //hacer un acumulador, max, min juntos 
    //hago una f(x) recursiva booleana, con true y false de como va
    long int acumulador=0;
    long int contador_capicua=0;
    long int max = ventas[0];
    long int min = ventas[0];
    for(int i=0;i<N;i++){
        if(max<ventas[i]) max=ventas[i];
        
        if(min>ventas[i]) min=ventas[i];
        
        acumulador+=ventas[i];
        
        if(es_capicua(ventas[i])) contador_capicua++;
        
    }
    
    printf("max = %ld ,min = %ld, capicua = %ld, total recaudado = %ld\n",max,min,contador_capicua, acumulador);
    
    
    
    //ordenar todo con un selection sort y qsort
    
    long int ventas_copia_selection[N];
    for(int i=0;i<N;i++){
        ventas_copia_selection[i]=ventas[i];
    }
    
    printf("El selection sort hizo %i cambios \n",selection_sort(ventas_copia_selection,N));
    
    long int ventas_copia_qsort[N];
    for(int i=0;i<N;i++){
        ventas_copia_qsort[i]=ventas[i];
    }
    
    qsort(ventas_copia_qsort,N,sizeof(long int),comparar_enteros);
    
    int flag=1; //parte true
    
    for(int i=0;i<N;i++){
        if(ventas_copia_qsort[i] != ventas_copia_selection[i]) flag=0;
    }
    
    if(flag) printf("todo esta ordenado bien\n");
    else printf("no, qsort dice que son diferentes\n");
    
    //busqueda lineal 
    
    printf("En el vector original el numero %ld esta en la posicion %i\n",7,busqueda_lineal(ventas,N,7));
    
    //hacer bsearch recursiva, con f(x) imprimir cosas
    
    printf("En el vector decreciente con B_search propia el numero %ld esta en la posicion %i \n",7,binary_search_recursiva_posicion(ventas_copia_selection,N,0,N-1,7));
    
    printf("En el vector decreciente con B_search propia el numero %ld requirio %i swaps \n",7,binary_search_recursiva_swaps(ventas_copia_selection,N,0,N-1,7));
    
    

    return 0;
}
