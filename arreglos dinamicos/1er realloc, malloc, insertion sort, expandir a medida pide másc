#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int vector[], int size)
{ // 1 == "ordenado"
    for(int i=1;i<size;i++){
        int temporal = vector[i];
        int k=i-1;
        while ( k>=0 && (vector[k] > temporal)){
            vector[k+1]=vector[k];
            k--;
        }
        vector[k+1] = temporal;
    }
}


int main()
{
	//Empieza con capacidad cap = 2 y size = 0.
	int cap=2;
	int size=0;
	
	//Reserva con malloc espacio para 2 enteros. Verifica NULL.
	int *vector = (int *) malloc ( sizeof(int) * cap);
	
	if(vector == NULL) return EXIT_FAILURE;
	
	//Pide números al usuario en un bucle while:
	int n;
	int contador_realloc=0;
	
	printf("Ingrese un número (-1 para terminar): ");
	scanf("%i",&n);
	
	//Si el usuario ingresa -1, termina el bucle.
    while (n != -1){
        //guardar en el vector
	    vector[size] = n;
	    size++;
	    
	    if ( cap == size ){
	        //Si size == cap, duplica la capacidad (cap = cap * 2) usando realloc y verifica que no devuelva NULL.
	        cap= cap * 2; // cap ^2
	        
	        //realoc es igual que malloc pero antes agregas el vector, lo otro a la der con ,
	        // vector = (int *) realloc ( vector, sizeof(int) * cap );
	        
	        int *temporal_vector = (int *) realloc ( vector , sizeof(int) * cap);
	        
	        if(temporal_vector == NULL ){
                free(vector);
	            return EXIT_FAILURE;
	        }
	        vector=temporal_vector;
	        
	        //Lleva un contador de cuántas veces haces realloc.
	        contador_realloc++;
	    }
	    
	    printf("Ingrese un número (-1 para terminar): ");
	    scanf("%i",&n);
    }
	
	printf("realloc se hizo %i veces\n",contador_realloc);
	printf("Se utiliza %i bytes\n",cap * sizeof(int));
	
	insertion_sort(vector,size);
	
	printf("Queda ordenado como => [");
	for(int i=0;i<size;i++){
	    printf("%i ",vector[i]);
	}
    printf("] \n");
    
    printf("Cantidad de numeros ingresados: %i\n", size);
    
    free(vector);
	return 0;
}
