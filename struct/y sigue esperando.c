#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[20];
    
} cheat;

int distancia(int a, int b, int **matriz)
{
    return matriz[a][b];
}

char* nombre_ciudad(int i, cheat *vector_nombres)
{
    return vector_nombres[i].nombre;
}

int main()
{
    
    int N,M;
    //Numero de ciudaddes N, distancia a ingresar M
    do{
        printf("Ingrese cantidad de ciudades ");
        scanf(" %i",&N);
    }while(N<=0);
    
    do{
        printf("Ingrese cantidad de distancia ");
        scanf(" %i",&M);
    }while(M<=0);
    
    //Repasar como se escriben matrices dinamicas
    int **matriz = (int **) malloc(sizeof(int *) * N);
    if(matriz == NULL) return EXIT_FAILURE;
    for(int i=0;i<N;i++){
        matriz[i] = (int *) malloc(sizeof(int) * N);
        if(matriz[i] == NULL) return EXIT_FAILURE;
    }
    
    //llenar matriz de -1 y 0
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j){
                matriz[i][j]=0;
            }
            else{
                matriz[i][j]=-1;
            }
        }
    }
    
    int ciudad_a;
    int ciudad_b;
    int ciudad_c;
    int metros;
    
    //luego formato ciudad a - ciudad b - distancia
    //pedir por las distancias
    for(int i=0;i<M;i++){
        printf("Ingrese la distancia %i formato 'ciudad a - ciudad b - distancia' ",i+1);
        scanf(" %i %i %i",&ciudad_a,&ciudad_b,&metros);
        
        //ingresar a matriz
        //LLenar esos datos en la matriz posicion xy-yx
        matriz[ciudad_a][ciudad_b]=metros;
        matriz[ciudad_b][ciudad_a]=metros;
        
    }
    
    //crear vector dinamico para nombre de cada ciudad 
    cheat *vector_nombres = (cheat *) malloc(sizeof(cheat) * N);
    if(vector_nombres == NULL)return EXIT_FAILURE;
    
    //pedir nombre para cada ciudad
    
    for(int i=0;i<N;i++){
        printf("ingrese el nombre de la ciudad indice %i",i);
        scanf(" %19[^\n]",vector_nombres[i].nombre);
        
    }
    
    //entrar loop de request a usuario
     //pedir 2 o 3 ciudades para ver distancia entre ciudades, rellenar -1 si no ciudad 3era
    printf("ingrese la distancia a estimar entre 2 o 3 ciudades (si solo 2, llene la 3era posicion con -1)");
    scanf(" %i",&ciudad_a);
    
    int distancia_total=0;
    int distancia_1,distancia_2;
    
    while(ciudad_a != -1){ //seguir pidiendo 2/3 hasta ingresado como 1ero -1
        scanf(" %i %i",&ciudad_b,&ciudad_c);
        
        if(ciudad_c == -1) //si solo 2 ciudades
        {//usar internamente "nombre_ciudad(i)" para ver indice->nombre 
            distancia_total = distancia(ciudad_a,ciudad_b,matriz);
            if(distancia_total == -1) printf("%s -> %s: no hay camino posible.\n",nombre_ciudad(ciudad_a,vector_nombres),nombre_ciudad(ciudad_b,vector_nombres));
            else printf("%s -> %s: %i kms.\n",nombre_ciudad(ciudad_a,vector_nombres),nombre_ciudad(ciudad_b,vector_nombres),distancia_total);
        }
        else{ //3 ciudades
            distancia_1 = distancia(ciudad_a,ciudad_b,matriz);
            if(distancia_1 == -1 ) printf("%s -> %s -> %s: no hay camino posible.\n",nombre_ciudad(ciudad_a,vector_nombres),nombre_ciudad(ciudad_b,vector_nombres),nombre_ciudad(ciudad_c,vector_nombres));
            
            else{
                distancia_2 = distancia(ciudad_b,ciudad_c,matriz);
                if(distancia_2 == -1 ) printf("%s -> %s -> %s: no hay camino posible.\n",nombre_ciudad(ciudad_a,vector_nombres),nombre_ciudad(ciudad_b,vector_nombres),nombre_ciudad(ciudad_c,vector_nombres));
                
                else{
                    distancia_total = distancia_1 + distancia_2;
                    printf("%s -> %s -> %s: %i kms.\n",nombre_ciudad(ciudad_a,vector_nombres),nombre_ciudad(ciudad_b,vector_nombres),nombre_ciudad(ciudad_c,vector_nombres),distancia_total);
                }
                
            }
        }
        
        printf("ingrese la distancia a estimar entre 2 o 3 ciudades (si solo 2, llene la 3era posicion con -1)");
        scanf(" %i",&ciudad_a);
    }
    
    free(vector_nombres);
    for(int i=0;i<N;i++){
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
