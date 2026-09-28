#include <stdio.h>

#define N 10
#define M 5

void pasar_datos(float A[N][M],float vect[10], int columna)
{
	int i,j;
	float suma;
	suma=0;
	
	for(i=0;i<N;i++){
		A[i][columna]=vect[i];
	}
	
}

void show_matriz(float matriz[N][M])
{
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("%f ",matriz[i][j]); //AJAJAJAJAJAJ
        }
        printf("\n");
    }
}

void interpolar(float matriz [N][M])
{
    int i,j,k,l,contador;
    float suma;
    contador=0;
    suma=0;
    for(i=0;i<=N;i++){
        for(j=0;j<=3;j++){ // hasta low
        
            if(matriz[i][j]<0){ //si pillo
                if(i==1) //inicio 
                {
                    k=i;
                    l=0;//desde fila misma a sgte
                    for(k=i;k<i+2;k++){
                        for(l=0;l<M;l++){
                            if(matriz[k][l]>0)suma+=matriz[k][l];
                            else contador++;
                        }
                    }//reemplazar
                    matriz[i][j]=suma/(4*2-contador);
                    
                }
                else if(i==N){//final
                    k=i;
                    l=0;//desde fila misma a anterior
                    for(k=i;k!=i-2;k--){
                        for(l=0;l<M;l++){
                            if(matriz[k][l]>0)suma+=matriz[k][l];
                            else contador++;
                        }
                    }//reemplazar
                    matriz[i][j]=suma/(4*2-contador);
                }
                
                else{//normal
                    l=0;//desde fila nterior a sgte
                    for(k=i-1;k<i+2;k++){
                        for(l=0;l<M;l++){
                            if(matriz[k][l]>0)suma+=matriz[k][l];
                            else contador++;
                        }
                    }//reemplazar
                    matriz[i][j]=suma/(4*2-contador);
                } 
            }
        }
    }
    
    
}

int main(){
	
	float matriz[N][M];
	
	float open[10] = {5763.74, 5776.31, 5725.14, 5766.21, -1, 5711.27, 5661, 5662.38, 5634.8, 5615.28};
	float high[10] = {5768.98, 5821.68, 5776.31, -1, 5817.28, 5816.09, 5738.2, 5683.65, 5690.22, 5641.53};
	float low[10] = {5692.38, 5750.18, 5725.14, 5704.84, 5722.81, 5711.27, 5661, 5628.03, 5634.8, 5594.06};
	float close[10] = {5697.95, 5763.74, 5776.31, 5725.14, 5766.21, 5810.14, 5711.27, 5661, 5662.38, 5634.8};
	
	int i,j;
	
	//primero llevar los datos a la matriz en si
	
	i=0;
	pasar_datos(matriz,open,i);	
	i++;
	pasar_datos(matriz,close,i);	
	i++;
	pasar_datos(matriz,high,i);	
	i++;
	pasar_datos(matriz,low,i);
	i++;
	
	
	//drt
	for(i=0;i<N;i++){
		matriz[i][4]=matriz[i][2]-matriz[i][3];
		//high - low 
	}
	
	interpolar(matriz);
	
	show_matriz(matriz);
	
	
}