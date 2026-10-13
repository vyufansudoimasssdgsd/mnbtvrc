#include <stdio.h>

#define N 150

int comparar_enteros( const void *a, const void *b)
{
	int x=*(int *)a;
	int y=*(int *)b;
	if(x>y) return 1;
	if(x<y) return -1;
	return 0;
	
}

void selection_sort(int A[], int size)
{
	int i,k;
	for(i=0;i<size-1;i++){
		int pos_menor=i;
		for(k=i+1;k<size;k++){
			if(A[pos_menor]>A[k])pos_menor=k;
		}
		if(i!=pos_menor){
			int temporal=A[pos_menor];
			A[pos_menor]=A[i];
			A[i]=temporal;
		}
	}
		
}


int valores[N] = {
    126981, 307698, 204191, 144973, 114842, 290706, 390000, 405290, 63369, 150738,
    490000, 345726, 100000, 46313, 21663, 286137, 439846, 100000, 351692, 410310,
    393786, 313944, 8407, 122026, 100000, 100000, 181472, 269951, 53625, 337911,
    124484, 27780, 226571, 329282, 133393, 340243, 449331, 185331, 390000, 324360,
    387589, 149194, 194600, 488548, 297002, 390000, 146530, 372955, 54123, 380400,
    57953, 459286, 456782, 191264, 490000, 372696, 391123, 58587, 46833, 490000,
    460763, 90669, 344757, 496076, 390000, 78158, 226208, 320631, 334588, 490000,
    402833, 20622, 203461, 156722, 86516, 300000, 18912, 90277, 18112, 193208,
    245870, 143685, 314588, 196277, 100000, 105814, 100000, 88707, 359785, 490000,
    407817, 247357, 120574, 50580, 338281, 119629, 428167, 393323, 356364, 120141,
    29025, 199081, 42435, 242717, 490000, 117886, 58736, 94725, 429374, 204295,
    299254, 109248, 446897, 55707, 490171, 70444, 203943, 100000, 340544, 100000,
    411847, 127049, 390000, 469231, 390000, 285043, 371026, 387272, 240514, 158709,
    363935, 453432, 133351, 427481, 472759, 183389, 290929, 442314, 374398, 363375,
    365795, 175017, 224949, 100000, 150684, 41466, 321526, 390000, 150852, 100000
};

int main(){
	
	int i;
	
	selection_sort(valores,N);
	
	
	int flag_hubo_errores=1;
	int contador_5=0;
	int flag_no_null=1;
	
	for(i=0;i<N;i++){
		
		int revisando=valores[i];
		
		if(revisando != 0){
			
			while(flag_no_null){
				
				int *puntero = (int *) bsearch(&revisando,valores,N,sizeof(int),comparar_enteros);
				
				//si no es null, es que se encontro
				if(puntero != NULL){
					valores[*puntero]=0;
					contador_5++;
				}
				
				// si se encuentra un Null, se hace la revision de los 5
				else if (puntero == NULL){
					
					if(contador_5 >= 5){
						printf("Atencion,posible fraude detectado (monto %i)\n",revisando);
						flag_hubo_errores=0;
					}
					contador_5=0;
					flag_no_null=0; 
				}	
			}	
		}	
	}
	
	if(flag_hubo_errores)printf("Transacciones diarias OK\n");
	
	return 0;
	
}
