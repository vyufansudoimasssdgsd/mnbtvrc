#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define N 3

//definir struct 2, 1 para puntos y otro para figuras

typedef struct
{
	int x;
	int y;
} punto;

typedef struct
{
	punto p_1;
	punto p_2;
	punto p_3;
	char nombre_f[15];
} figura;

void generar_figuras ( figura *A[] )
{
	srand(time(NULL));
	//f(x) es 2 rand bien escritos, que devuelva un vector de struct con los ya generados
	
	int i,j;
	for(i=0;i<N;i++){
		
		int puntos_generar = (rand()%2)+2;
		
		if(puntos_generar == 2){
			
			A[i]->p_1.x = rand()%10;
			A[i]->p_1.y = rand()%10;
			
			A[i]->p_2.x = rand()%10;
			A[i]->p_2.y = rand()%10;
			
			A[i]->p_3.x = -1;
			A[i]->p_3.y = -1;
		}
		else if (puntos_generar == 3)
		{
			A[i]->p_1.x = rand()%10;
			A[i]->p_1.y = rand()%10;
			
			A[i]->p_2.x = rand()%10;
			A[i]->p_2.y = rand()%10;
			
			A[i]->p_3.x = rand()%10;
			A[i]->p_3.y = rand()%10;
		}
		
	}
	
}

void deterimnar_formas ( figura *A[])
{
	int i;
	for(i=0;i<N;i++){
		//es triangulo si tiene 3 puntos
		if(A[i]->p_3.y != -1){
			//A[i]->nombre_f = "triangulo.";
			strcpy(A[i]->nombre_f,"triangulo.");
		}
		else{
			
			if( (A[i]->p_1.x == A[i]->p_2.x) || ( A[i]->p_1.y == A[i]->p_2.y ) ){
				//A[i]->nombre_f = "circulo.";
				strcpy(A[i]->nombre_f,"circulo.");
				
			}
			else{
				//A[i]->nombre_f = "rectangulo.";
				strcpy(A[i]->nombre_f,"rectangulo.");
			}
		}
		
	}
	
}

void mostrar_formas ( figura A[])
{
	int i;
	for(i=0;i<N;i++){
		figura F = A[i];
		if(strcmp(F.nombre_f,"triangulo")){
			printf(" F%i: (%i,%i) (%i,%i) %s\n",F.p_1.x, F.p_1.y, F.p_2.x, F.p_2.y, F.nombre_f);
		}
		else{
			printf(" F%i: (%i,%i) (%i,%i) (%i,%i) %s\n",F.p_1.x, F.p_1.y, F.p_2.x, F.p_2.y, F.p_3.x, F.p_3.y, F.nombre_f);
		}
	}
	
	
}


int main()
{
	
	figura vector_r[N];
	
	generar_figura(&vector_r);
	
	determinar_formas(&vector_r);
	
	mostrar_formas (vector_r);
	
	return 0;
}
