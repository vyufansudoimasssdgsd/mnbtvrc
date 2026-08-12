
//cambios ocupar sumatorio en vez de while innecesario 
//printf para que no sea solo terminal
//datos a int 


#include<stdio.h>

int main ()

{
	//define 
	
	int n;
	int sumatoria;
	
	//entrada
	
	do 
	{
		printf("ingrese el numero para la sumatoria ");
		scanf("%i", &n);
		if (n<=0)
		{
			printf("Error, ingrese un numero valido\n ");
		}
	} while (n<=0); // aca poner;
	
	//procesamiento 
	
	sumatoria = (n*(n+1))/2;
	
	// salida
	
	printf("La sumatoria de los valores entre el 1 y el %i es %i ", n, sumatoria);
	return 0;
	
	
 } 







