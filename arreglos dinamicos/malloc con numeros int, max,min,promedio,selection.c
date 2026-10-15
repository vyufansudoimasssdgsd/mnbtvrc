#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//recordar poner librerias ajajajajjaja

/*

Contexto: Un torneo registra N puntajes enteros. Debes ordenarlos y analizarlos.

Requisitos:
free.

Concepto clave: malloc + arreglo dinámico + ordenamiento propio.

*/

void selection_sort( int A[], int size)
{
    for(int i=0;i<size-1;i++){
        int pos_menor=i;
        for(int k=i+1;k<size;k++){
            //descendiente si a[k] es el mayor
            if(A[pos_menor]<A[k])pos_menor=k;
        }
        if(i != pos_menor)
        {
            int temporal=A[pos_menor];
            A[pos_menor]=A[i];
            A[i]=temporal;
            
            
        }
    }
}

void show(int A[],int size){
    
    for(int i=0;i<size;i++){
        printf("%i ",A[i]);
    }
    printf("\n--------------------------------------\n");
}

int main()
{

	int size;

	srand(time(NULL));
	
	//Pide N (validado entre 1 y 100).
	do {
		printf("Cuanto es el tamaño del vector?? ");
		scanf("%i",&size);
	} while (size<1 || size>100);

	//malloc parte
    //Reserva memoria con malloc para N enteros.
	int *vector;

	vector = (int *) malloc (sizeof(int ) * size);
    
    //Verifica NULL.
	if(vector == NULL) return EXIT_FAILURE;

	//rellenar parte
    //Llena el arreglo con puntajes entre 0 y 1000 (puedes usar rand() o scanf).
	for(int i=0; i<size; i++) {
		vector[i]=rand()%1001;
	}

	float acumulador_promedio=0.0;

	//Calcula e imprime: promedio, máximo, mínimo.
	//promedio

	for(int i=0; i<size; i++) {
		acumulador_promedio+=vector[i];
	}

	float promedio=acumulador_promedio/size;

	//max y min ajajajajjaja

	int max=vector[0];
	int min=vector[0];

	for(int i=0; i<size; i++) {
		if(vector[i]<min) min=vector[i];
		if(vector[i]>max) max=vector[i];
	}

    printf("promedio == %.1f\n",promedio);
    printf("max == %i\n",max);
    printf("min == %i\n",min);
    
    //Ordénalo descendentemente con selection sort propio.
    selection_sort(vector,size);
    
    printf("--------------------------------------\n");
    
    //Imprime el arreglo ordenado.
    show(vector,size);
    
    //Bonus: cuántos puntajes son mayores que el promedio.
    
    int contador_sobre_promedio=0;
    
    for(int i=0;i<size;i++){
        if(vector[i]>promedio)contador_sobre_promedio++;
    }
    printf("Sobre el promedio = %i \n",contador_sobre_promedio);
    
    free(vector);
    
	return 0;
}
