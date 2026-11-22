#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[26];
    int price;
    int cant;
    float nota;
    
}Sandwich;

int main()
{
    FILE *archivo = fopen("menu.txt","rt");
    if(archivo == NULL) exit(1);
    
    int i;
    char *maximo_nombre;
    float maximo_nota;
    int total_ganado=0;
    Sandwich temporal;
    //Base de todo un for
    for(i=0; fscanf(archivo," %s %i %i %f",temporal.name,&temporal.price,&temporal.cant,&temporal.nota) == 4;i++){
        //sacar total plata
        total_ganado+= (temporal.price * temporal.cant);
        
        //sacar el maximo
        if(i==0){
            maximo_nota=temporal.nota;
            maximo_nombre=temporal.name;
        }
        else{
            if(maximo_nota < temporal.nota){
                maximo_nota=temporal.nota;
                maximo_nombre=temporal.name;
            }
        }
    }
    
    fclose(archivo);
    
    printf("El total ganado en el dia anterior fue %i\n",total_ganado);
    printf("El Sandwich con mayor nota es el %s, con %.1f\n",maximo_nombre,maximo_nota);
    
    archivo = fopen("menu.txt","at");
    if(archivo == NULL) exit(1);
    
    fprintf(archivo,"\nSopaipipleto_Mayo_Casera 2500 0 0.0");
    
    fclose(archivo);
    
    return 0;
}
