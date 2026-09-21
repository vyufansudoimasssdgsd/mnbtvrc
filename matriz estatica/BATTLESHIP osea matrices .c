#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void mostrar_tablero(int mapa[N][N])

{
    int i,j,k,l;    
    printf("    ");
    j=0;
    for(k=1;k<=N;k++){ // hacer 1 al 10 fila
        printf("[%i] ",k);
    }
    printf("\n");
    for(i=0;i<N;i++){
        if(i+1!= 10)printf(" [%i] ",i+1);
        else printf("[%i] ",i+1);
        for(j=0;j<N;j++){
            printf("%4i",mapa[i][j]); // el 4 al lado del i hace que reserve espacios
            //asi no se desconfigura con el -1
        }
        printf("\n");
    }
    
    
}

int poner_barco(int mapa[N][N], int id,int angle, int size)
{
    int i,j,k,flag;
    flag=1;
    
    if(angle ==1){
        j=rand()%(N-size+1);
        i=rand()%10;
        for(k=0;k<size;k++){ //pasada para ver si es que hay barco
            if(mapa[i][j+k]!=0){
                flag=0;
            }
        }
        if(flag){ // si es que no hay barco ahí poner uno 
            for(k=0;k<size;k++){
                mapa[i][j+k]=id;
            }
        }
           
    }
    else{
        i=rand()%(N-size+1);
        j=rand()%10;
        for(k=0;k<size;k++){ //pasada para revisar sin barcos
            if(mapa[i+k][j]!=0)flag=0;
        }
        if(flag){ // si es que no hay barco ahí poner uno 
            for(k=0;k<size;k++){
                mapa[i+k][j]=id;
            }
        }
        
    }
    return flag;
    
}

int disparo(int mapa[N][N], int x, int y)
{
    if(mapa[x][y] == 0) return 0; //si no le dio a nada
    else if(mapa[x][y] ==-1 ) return 1; //le di a un blanco ya dado
    else
    {
        //Buscar en todo el tablero la ubicacion con el id del barco
        int id,i,j;
        id = mapa[x][y];
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                if(mapa[i][j] == id)
                {
                    mapa[i][j]=-1;
                    
                }
            }
        }
        return -1;
    }
}

int sigue_partida(int mapa[N][N])

{
    int i,j,flag;
    flag=0; //true
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(!(mapa[i][j] == 0 || mapa[i][j] == -1)){
                //si me pillo algo distinto de 0 o -1, la partida sigue
                flag=1;
                break;
            } 
        }
        if(flag==1)break;
    }
    return flag;
    
}


int main()
{
    srand(time(NULL));
    //primero hacer mapa
    int mapa[N][N] = {0}; //matriz llena de 0 
    int que_es,i,posicion,talla,fin_partida,x,y,le_dio,disparos_totales,choque;
    //poner 5 barcos en el mapa
    for(i=1;i<=5;i++){//Aprovechar que la talla y la posicion de los 5 barcos sea aleatoria
        talla=rand()%(N-1)+1;
        posicion=rand()%2;
        while(1==1){ //hacer hasta que el barco no choque con uno ya existente
            choque=poner_barco(mapa,i,posicion,talla);
            if(choque)break;
        }
    }
    printf("----------------------------------------------\n");
    mostrar_tablero(mapa);
    printf("----------------------------------------------\n");
    //Hacer disparos en el mapa
    fin_partida=1;
    disparos_totales=0;
    
    while(fin_partida !=0){
        //el jugador debe ver cada turno que disparo se realizo de manera aleatoria
        x=rand()%10;
        y=rand()%10;
        le_dio=disparo(mapa,x,y);
        //Luego si se hundio algun barco mostrar el mapa
        if(le_dio == -1){ //si le dio a un barco, mostrar mapa 
            mostrar_tablero(mapa);
            printf("----------------------------------------------\n");
        }
        disparos_totales++;//y contar cuantos disparos consto hundirlos todos
        fin_partida=sigue_partida(mapa);
    }
    
    printf("FIN DE LA PARTIDAAAAA\n");
    printf("Disparos totales == %i",disparos_totales);
    
    
    
    
}