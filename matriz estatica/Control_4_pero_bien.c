#include <stdio.h>

#define N 10
#define M 6

void interpolar (float matriz [N][M], int posicion_i, int posicion_j)
{ //INTERPOLAR ESTA MALO; ES SOLO LA MISMA CATEGORIA DIA ANTERIOR Y SGTE; LEEE BIEN 
    //caso == 1 ,superior
    //caso == 2 ,normal
    //caso == 3 ,inferior
    if(posicion_i == 0){
        matriz[posicion_i][posicion_j]=matriz[posicion_i+1][posicion_j];
    }
    else if(posicion_i == N-1){
        matriz[posicion_i][posicion_j]=matriz[posicion_i-1][posicion_j];
    }
    else{
        matriz[posicion_i][posicion_j]=(matriz[posicion_i-1][posicion_j]+matriz[posicion_i+1][posicion_j])/2;
    }
    
}

void show(float matriz[N][M])
{
    printf("     OPEN    CLOSE   HIGH    LOW      DTR     MA\n");
    for(int i=0;i<N;i++){
	    for(int j=0;j<M;j++){
	        if(j==0)printf("D%i | ",i);
	        printf("%6.2f ",matriz[i][j]);
	    }
	    printf("\n");
	}
	printf("------------------------------------------------\n");
}

int main()
{
	float matriz[N][M]={0};
	
	float open[10] = {5763.74, 5776.31, 5725.14, 5766.21, -1, 5711.27, 5661, 5662.38, 5634.8, 5615.28};
	float high[10] = {5768.98, 5821.68, 5776.31, -1, 5817.28, 5816.09, 5738.2, 5683.65, 5690.22, 5641.53};
	float low[10] = {5692.38, 5750.18, 5725.14, 5704.84, 5722.81, 5711.27, 5661, 5628.03, 5634.8, 5594.06};
	float close[10] = {5697.95, 5763.74, 5776.31, 5725.14, 5766.21, 5810.14, 5711.27, 5661, 5662.38, 5634.8};
	
	//pasar de vectores a matriz
	
	// N-1 porque ese espacio es para DTR y MA
	for(int i=0; i<M-1;i++){
	    for(int j=0;j<N;j++){
            if(i==0){
                matriz[j][i]= open[j];
            }
            if(i==1){
                matriz[j][i]= close[j];
            }
            if(i==2){
                matriz[j][i]= high[j];
            }
            if(i==3){
                matriz[j][i]= low[j];
            }
	    }
	}
	
	//pasar por todas las posiciones e interpolar las necesarias
	for(int i=0;i<N;i++){
	    for(int j=0;j<M;j++){
	        if(matriz[i][j] == -1.00){
	            interpolar(matriz,i,j);
	        }
	    }
	}
	
	show(matriz);
	
	//DTR, es high-low, siempre es la misma columna
	for(int i=0;i<N;i++){
	    matriz[i][M-2]=matriz[i][M-4]-matriz[i][M-3];
	}
	
	show(matriz);
	float acumulador_AM=0.0;
	//for para cada fila a interpolar
	for(int i=0;i<N;i++){
	    if(i<=1)matriz[i][M-1]=-1.00;
	    else{
	            for(int j=i-2;j<=i;j++){//por para cada columna de esa fila
                    acumulador_AM+=matriz[j][M-5];
	            }
                //despues de los for
                matriz[i][M-1]=acumulador_AM/3.0;
                acumulador_AM=0.0;
	        }
	    }
	
	show(matriz);
	
    return 0;
}