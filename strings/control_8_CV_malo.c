#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int str_a_n (char *A, int posicion)
{
	if(A[posicion] == '1') return 1;
	if(A[posicion] == '2') return 2;
	if(A[posicion] == '3') return 3;
	if(A[posicion] == '4') return 4;
	if(A[posicion] == '5') return 5;
	if(A[posicion] == '6') return 6;
	if(A[posicion] == '7') return 7;
	if(A[posicion] == '8') return 8;
	if(A[posicion] == '9') return 9;
	if(A[posicion] == '0') return 0;
}



int main()
{
	//escanear los 2 tamaños iniciales de los vectores
	
	int size_1,size_2;
	
	printf("jugadores equipo 1 ?\n");
	scanf("%i",&size_1);
	
	printf("jugadores equipo 2 ?\n");
	scanf("%i",&size_2);
	
	
	//crear los 2 vectores con calloc para puntaje jugador
	
	int *equipo_1 = (int *) calloc (sizeof(int), size_1);
	if(equipo_1 == NULL) return EXIT_FAILURE;
	
	int *equipo_2 = (int *) calloc (sizeof(int), size_2);
	if(equipo_2 == NULL) return EXIT_FAILURE;
	
	//crear 2 vectores para ingresar los datos con malloc
	
	char *input_1 = (char *) malloc (sizeof(char) * 6); // 4 porque 2 numeros 1 espacio 1 \0
	if(input_1 == NULL) return EXIT_FAILURE;
	
	char *input_2 = (char *) malloc (sizeof(char) * 6);
	if(input_2 == NULL) return EXIT_FAILURE;
	
	//while punt_1 y punt_2 >0 , se lee afuera y luego entra al while 
	
	//ingresa como char
	scanf(" %5[^\n]",input_1);
	
	if((strcmp(input_1,"-1 -1") !=0 || strcmp(input_1,"0 0") !=0)) scanf(" %5[^\n]",input_2);
	
	int pos_1,pos_2,punt_1,punt_2;
	
	int total_puntaje_1=0;
	int total_puntaje_2=0;
	
	//tengo que restructurar el while porque si el equipo 1 termina no se guardan esos datos 
	//usar strcmp
	while( if ( strcmp(input_1,"-1 -1") !=0 ) && ((strcmp(input_2,"-1 -1") != 0 ) ))
	{
		
		//guardar en la pos del 1ero y el valor del 2do
		
		//para eso podemos hacer tabla de if, pero en f(x)
		
		//al leer añadir el puntaje en la posicion del jugador
		pos_1=str_a_n(input_1,0);
		pos_2=str_a_n(input_2,0);
		
		punt_1=str_a_n(input_1,2);
		punt_2=str_a_n(input_2,2);
		
		//si la pos es mayor que el size, realloc
		if(pos_1 > size_1){
			size_1=pos_1 + 1;
			equipo_1 = (int *) realloc (equipo_1, sizeof(int) * size_1);
		}
		
		if(pos_2 > size_2){
			size_2=pos_2 + 1;
			equipo_2 = (int *) realloc (equipo_2, sizeof(int) * size_2);
		}
		
		//guardar los datos en los vectores
		
		equipo_1[pos_1]=punt_1;
		equipo_2[pos_2]=punt_2;
		
		//guardar el puntaje para ver ganador
		
		total_puntaje_1+=punt_1;
		total_puntaje_2+=punt_2;
		
		//volver a escanear los jugadores
		scanf(" %5[^\n]",input_1);
		if (strcmp(input_1,"-1 -1") !=0 ) scanf(" %5[^\n]",input_2;
	}
	
	printf("Marcador Final %i %i\n",total_puntaje_1,total_puntaje_2);
	if(total_puntaje_2 > total_puntaje_1) printf("Ganador: Equipo 2\n");
	else if(total_puntaje_2 < total_puntaje_1) printf("Ganador: Equipo 1\n");
	else printf("Empate\n");
	
	
}
