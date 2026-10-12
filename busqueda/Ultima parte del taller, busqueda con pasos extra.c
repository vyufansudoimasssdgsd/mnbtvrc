#include <stdio.h>

void selection_sort( int vector[], int size)
{
    for(int i=0;i<size-1;i++){
        
        int posMenor=i;
        for(int k=i+1;k<size;k++){
            if(vector[k]<vector[posMenor])posMenor=k;
        }
        if(i != posMenor){
            int temporal=vector[i];
            vector[i]=vector[posMenor];
            vector[posMenor]=temporal;
        }
        
    }
    
    
}


int main()
{
    //ingresar datos
    
    int corredores;
    printf("ingrese la cantidad total de corredores");
    scanf("%i",&corredores);
    
    int tiempos_corredores[corredores];
    
    for(int i=0; i<corredores;i++){
        printf("tiempo corredor %i =",i+1);
        scanf("%i",&tiempos_corredores[i]);
    }
    //ordenar vector de tiempos
    
    selection_sort(tiempos_corredores, corredores);
    
    for(int i=0;i<corredores;i++){
        
        printf("%i ",tiempos_corredores[i]);
        
    }
    
    int consultas_cantidad;
    int cantidad_a_consultar;
    printf("ingrese la cantidad de consultas");
    scanf("%i",&consultas_cantidad);
    
    //cantidad de consultas, hacer un gran for
    
    for(int i=0;i<consultas_cantidad;i++)
    {
        int flag=1;
        //revisar en el vctor ordenado de + a - si 
        // la i suma funciona, una vez que supere 
        //el ideal, se printea no
        //cuando eventualmente alguna suma calce, si
        
        printf("ingrese la cantidad a consultar ");
        scanf("%i",&cantidad_a_consultar);
        
        
        for(int j=0;j<consultas_cantidad;j++){
            
            for(int k=i+1;k<corredores;k++){
                if(tiempos_corredores[k] + tiempos_corredores[j] == cantidad_a_consultar){
                    printf("SI, los tiempos son %i y %i \n",tiempos_corredores[k],tiempos_corredores[j]);
                    flag=0;
                    break;
                }
                else if (tiempos_corredores[k] + tiempos_corredores[j] > cantidad_a_consultar) break;
            }
            
        }
        //printf si con los N°s o no 
        if(flag) printf("NO, no hay\n");
        
    }

    return 0;
}
