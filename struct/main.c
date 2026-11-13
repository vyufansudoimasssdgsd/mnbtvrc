#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//revisar unistd.h sleep(1)

typedef struct
{
    char nombre[30];
    char tipo[20];
    float poder;
    int costo_energia; //restar a PE
} ataque;

typedef struct
{
    char nombre[30];
    char tipo[20];
    float PV; //PV, puntos vida
    int PE; //PE, puntos energia
    ataque mov_1;
    ataque mov_2;
    int ind_1;
    int ind_2;
} pokemon;

ataque* leer_ataques(int *tamano_at)
{
    //10. Implemente una funcion leer_ataques() 
    //que genere un array de 25 ataques, a partir del archivo ataques.txt.
    
    //crear vector dinamico
    ataque *vector_ataques = NULL;
    
    //abrir archivo
    FILE *archivo = fopen("ataques.txt","rt");
    if(archivo == NULL){
        printf("ERROR AL LEER ATAQUES, REVISAR CODIGO");
        return NULL; //revisar que esto se pueda
    }
    
    //leer cada parte con fscanf
    ataque temporal_at;
    int size_vector=-1;
    while ( fscanf(archivo, "%s %s %f %i",
        temporal_at.nombre,temporal_at.tipo, //guardar en temporal
        &temporal_at.poder,&temporal_at.costo_energia) == 4 )
        {
            //size ++
            size_vector++;
            
            //realloc
            ataque *temporal_fallo = (ataque *) realloc (vector_ataques,sizeof(ataque) * (size_vector+1) );
            if(temporal_fallo == NULL) {
                free(vector_ataques);
                return NULL; //revisar si se puede esto y antes
            }
            
            vector_ataques = temporal_fallo; 
            //guardar array de ataques de f(x) 
            vector_ataques[size_vector] = temporal_at;
        }
    
    //cerrar el archivo 
    fclose(archivo);
    
    //guardar tamano_at
    *tamano_at=size_vector+1;
    
    //devlver el vector lleno 
    return vector_ataques;
    
}

pokemon* leer_pokedex( ataque vector_ataques[], int* tamano_p)
{
    //Implemente una funcion leer_pokedex() que lea el archivo pokemones.txt y genere un array dinámico de Pokemones.
    //Los ataques están indicados con un número entero, que se corresponde con el índice del array de ataques generado en
    //la función anterior.
    
    //crear vector dinamico
    pokemon *vector_pokemon = NULL;
    
    //abrir archivo
    FILE *archivo = fopen("pokedex_gen1.txt","rt");
    if(archivo == NULL){
        printf("ERROR AL LEER POKEDEX, REVISAR CODIGO");
        return NULL; //revisar que esto se pueda
    }
    
    //leer cada parte con fscanf
    pokemon temporal_pk;
    int size_vector=-1;
    while ( fscanf(archivo, "%s %s %f %i %i %i",
        temporal_pk.nombre,temporal_pk.tipo, //guardar en temporal
        &temporal_pk.PV,&temporal_pk.PE,&temporal_pk.ind_1, &temporal_pk.ind_2) == 6 )
        {
            //size ++
            size_vector++;
            
            //realloc
            pokemon *temporal_fallo = (pokemon *) realloc (vector_pokemon,sizeof(pokemon) * (size_vector+1) );
            if(temporal_fallo == NULL) {
                free(vector_pokemon);
                return NULL; //revisar si se puede esto y antes
            }
            //guardar dinamico bien 
            vector_pokemon = temporal_fallo;
            
            //guardar 2 ataques de los pokemones
            temporal_pk.mov_1=vector_ataques[temporal_pk.ind_1];
            temporal_pk.mov_2=vector_ataques[temporal_pk.ind_2];
            
            //guardar array de ataques de f(x) 
            vector_pokemon[size_vector] = temporal_pk;
        }
    
    //cerrar el archivo 
    fclose(archivo);
    
    //tamano_p
    *tamano_p=size_vector+1;
    
    //devlver el vector lleno 
    return vector_pokemon;
    
}

pokemon* buscar_pokemon(pokemon vector_pokemon[], char p_ingresado[] , int tamano_p)
{
    for(int i=0;i<tamano_p;i++){
        //si el nombre ingresado y del pokemon calzan...
        if(strcmp(vector_pokemon[i].nombre,p_ingresado) == 0){
            return &vector_pokemon[i];
        }
    }
    return NULL;
}

void mostrarEstado(pokemon vector_pokemon[], char p_ingresado[], int tamano_p)
{
    //buscar en el vector de pokedex al pokemon 
    int flag_encontrado = 0;
    pokemon *pokemon_puntero = buscar_pokemon(vector_pokemon,p_ingresado,tamano_p);
    if(pokemon_puntero != NULL) flag_encontrado = 1;
    
    if(flag_encontrado){
        pokemon pokemon_struct = *pokemon_puntero;
        if(pokemon_struct.PV < 0)printf("EL pokemon %s, de tipo %s , tiene PS = 0.00 y PE %i\n",pokemon_struct.nombre,pokemon_struct.tipo,pokemon_struct.PE);
        else printf("EL pokemon %s, de tipo %s , tiene PS = %.2f y PE %i\n",pokemon_struct.nombre,pokemon_struct.tipo,pokemon_struct.PV,pokemon_struct.PE);
        printf("mov_1 = %s , tipo %s , poder %.2f, CE %i \n",pokemon_struct.mov_1.nombre,pokemon_struct.mov_1.tipo,pokemon_struct.mov_1.poder,pokemon_struct.mov_1.costo_energia);
        printf("mov_2 = %s , tipo %s , poder %.2f, CE %i \n\n",pokemon_struct.mov_2.nombre,pokemon_struct.mov_2.tipo,pokemon_struct.mov_2.poder,pokemon_struct.mov_2.costo_energia);
    }
    else printf("El pokemon no fue encontrado o el nombre fue escrito de manera incorrecta\n");
    
}

int tipo_segun_clima(char tipo_mov[],int clima)
{
    if(clima == 0){//0 = soleado
        if(strcmp(tipo_mov,"planta") == 0)return 1;
        if(strcmp(tipo_mov,"fuego") == 0)return 1;
        if(strcmp(tipo_mov,"tierra") == 0)return 1;
    } 
    if(clima == 1){// 1 = Lluvioso
        if(strcmp(tipo_mov,"agua") == 0)return 1;
        if(strcmp(tipo_mov,"electrico") == 0)return 1;
        if(strcmp(tipo_mov,"insecto") == 0)return 1;
    }
    if(clima == 2){// 2 = Semi_nublado
        if(strcmp(tipo_mov,"normal") == 0)return 1;
        if(strcmp(tipo_mov,"roca") == 0)return 1;
    }
    if(clima == 3){// 3 = Nublado
        if(strcmp(tipo_mov,"hada") == 0)return 1;
        if(strcmp(tipo_mov,"lucha") == 0)return 1;
        if(strcmp(tipo_mov,"veneno") == 0)return 1;
    }
    return 0;
}

void simular_ataque(pokemon *p1, pokemon *p2, int mov_elegido, int clima)
{
    if(mov_elegido == 1){
        //mov_1
        //restar PE al atacante
        p1->PE-=p1->mov_1.costo_energia;
        printf("Le quedan %i PE al pokemon %s\n",p1->PE,p1->nombre);
        
        //ver si se potencia por el clima
        int potenciar_clima = tipo_segun_clima(p1->mov_1.tipo,clima);
        if(potenciar_clima)printf("Se potencio el ataque gracias al clima\n");
        
        //restar vida al defensor
        if(potenciar_clima) p2->PV-=((p1->mov_1.poder)*(1.5));
        else p2->PV-=p1->mov_1.poder;
        
        //imprimir mensaje ataque 
        if(potenciar_clima)printf("El pokemon %s ataco con %s a %s, realizando %.2f de daño\n",p1->nombre,p1->mov_1.nombre,p2->nombre,(p1->mov_1.poder)*(1.5));
        else printf("El pokemon %s ataco con %s a %s, realizando %.2f de daño\n",p1->nombre,p1->mov_1.nombre,p2->nombre,p1->mov_1.poder);
        
    }
    else if (mov_elegido == 2){
        //mov_2

        if( (p1->PE - p1->mov_2.costo_energia) >= 0){
            //restar PE al atacante
            p1->PE-=p1->mov_2.costo_energia;
            printf("Le quedan %i PE al pokemon %s\n",p1->PE,p1->nombre);
            
            //ver potenciar_clima
            int potenciar_clima = tipo_segun_clima(p1->mov_2.tipo,clima);
            if(potenciar_clima)printf("Se potencio el ataque gracias al clima\n");
            
            //restar vida al defensor
            if(potenciar_clima) p2->PV-=((p1->mov_2.poder)*(1.5));
            else p2->PV-=p1->mov_2.poder;
            
            //imprimir mensaje
            if(potenciar_clima) printf("El pokemon %s ataco con %s a %s, realizando %.2f de daño\n",p1->nombre,p1->mov_2.nombre,p2->nombre,(p1->mov_2.poder)*(1.5));
            else printf("El pokemon %s ataco con %s a %s, realizando %.2f de daño\n",p1->nombre,p1->mov_2.nombre,p2->nombre,p1->mov_2.poder);
        }
        else{
            printf("El pokemon no tiene suficiente PE, por lo que ocupa COMBATE\n");
            
            //ver potenciar_clima
            int potenciar_clima = tipo_segun_clima(p1->mov_2.tipo,clima);
            if(potenciar_clima)printf("Se potencio el ataque gracias al clima\n");
            
            //restar vida al defensor
            if(potenciar_clima) p2->PV-=((10)*(1.5));
            else p2->PV-=10;
            
            //restar vida al atacante
            p1->PV-=5;
            
            //imprimir mensaje
            if(potenciar_clima) printf("El pokemon %s ataco con COMBATE a %s, realizando %.2f de daño\n",p1->nombre,p1->mov_2.nombre,p2->nombre,(10)*(1.5));
            else printf("El pokemon %s ataco con COMBATE a %s, realizando %.2f de daño\n",p1->nombre,p1->mov_2.nombre,p2->nombre,10);
            printf("Oh no, el pokemon se ha hecho 5 de daño a si mismo\n");
            
        }
        
    }
}

void simularCombate(char p1_ingresado[], char p2_ingresado[], pokemon vector_pokemon[], int tamano_p)
{
    //buscar los pokemones ingresados
    pokemon *p1=buscar_pokemon(vector_pokemon,p1_ingresado,tamano_p);
    
    //Si no se encuentran decir cual estuvo mal escrito
    if(p1 == NULL){ 
        printf("El Primer pokemon ingresado esta mal escrito o no existe \n");
        return;
    }
    pokemon *p2=buscar_pokemon(vector_pokemon,p2_ingresado,tamano_p);
    if(p2 == NULL){
        printf("El Segundo pokemon ingresado esta mal escrito o no existe \n");
        return;
    }
    
    //sale un clima random por combate
    int clima=rand()%4;
    if (clima == 0) printf("[CLIMA ACTUAL: SOLEADO]\n");
    if (clima == 1) printf("[CLIMA ACTUAL: LLUVIOSO]\n");
    if (clima == 2) printf("[CLIMA ACTUAL: SEMI-NUBLADO]\n");
    if (clima == 3) printf("[CLIMA ACTUAL: NUBLADO]\n");
    int potenciar_clima=0;
    
    //si ya hay un pokemon KO
    if(p1->PV == 0 ){
        printf("El combate no inicio porque el pokemon %s esta KO",p1->nombre);
        return;
    }
    else if (p2->PV == 0){
        printf("El combate no inicio porque el pokemon %s esta KO",p2->nombre);
        return;
    }
    
    //ocupar contador par o impar para decidir de quien es el turno
    int turno=0;
    int mov_elegido;
    int flag_ko=1;
    
    //guardar PV y PE antes del combate para luego curarlos
    
    float PV_de_p1 = p1->PV;
    int PE_de_p1 = p1->PE;
    float PV_de_p2 = p2->PV;
    int PE_de_p2 = p2->PE;
    
    while (flag_ko){ //mientras uno siga vivo
        if(turno%2 == 0){ // turno p1
            printf("Es el turno del pokemon %s \nPV=%.2f-----PE=%i\n",p1->nombre,p1->PV,p1->PE);
            printf("1-%s tipo %s (ATK=%.2F|CE=%i)\n",p1->mov_1.nombre,p1->mov_1.tipo,p1->mov_1.poder,p1->mov_1.costo_energia);
            printf("2-%s tipo %s (ATK=%.2F|CE=%i)\n",p1->mov_2.nombre,p1->mov_2.tipo,p1->mov_2.poder,p1->mov_2.costo_energia);
            printf("Elijo... (-1 para terminar)");
            scanf("%i",&mov_elegido);
            
            if(mov_elegido != -1){
                simular_ataque(p1,p2,mov_elegido,clima);
            }
            else if(mov_elegido == -1){
                printf("Combate finalizado de manera prematura\n");
                flag_ko=0;
            }
            else if (p2->PV <= 0)flag_ko=0;
        }
        else{ //turno p2
            printf("Es el turno del pokemon %s \nPV=%.2f-----PE=%i\n",p2->nombre,p2->PV,p2->PE);
            printf("1-%s tipo %s (ATK=%.2F|CE=%i)\n",p2->mov_1.nombre,p2->mov_1.tipo,p2->mov_1.poder,p2->mov_1.costo_energia);
            printf("2-%s tipo %s (ATK=%.2F|CE=%i)\n",p2->mov_2.nombre,p2->mov_2.tipo,p2->mov_2.poder,p2->mov_2.costo_energia);
            printf("Elijo... (-1 para terminar)");
            scanf("%i",&mov_elegido);
            
            if(mov_elegido != -1){
                simular_ataque(p2,p1,mov_elegido,clima);
            }
            else if(mov_elegido == -1){
                printf("Combate finalizado de manera prematura\n");
                flag_ko=0;
            }
            else if (p1->PV <= 0)flag_ko=0;
            
        }
    }
    
    
    //si p1 o p2 se debilita
    if(p1->PV <=0)printf("El pokemon %s esta KO, ha ganado %s\n");
    else printf("El pokemon %s tiene PV=%.2f\n");
    
    if(p2->PV <=0)printf("El pokemon %s esta KO, ha ganado %s\n");
    else printf("El pokemon %s tiene PV=%.2f\n");
    
    //restaurar vida y PE para el proximo combate
    
    p1->PV = PV_de_p1;
    p1->PE = PE_de_p1;
    p2->PV = PV_de_p2;
    p2->PE = PE_de_p2; 
    
}

int main()
{
    srand(time(NULL));
    
    int input_usuario;
    int tamano_p;
    int tamano_at;
    
    //leer ataque de txt
    ataque *vector_ataques = leer_ataques(&tamano_at);
    if( vector_ataques == NULL) return EXIT_FAILURE;
    
    //leer pokedex 
    pokemon *vector_pokemon = leer_pokedex(vector_ataques, &tamano_p);
    if( vector_pokemon == NULL) return EXIT_FAILURE;
    
    do{
        printf("-----------------MENU----POKEMON-----------------\n");
        printf("1-Agregar Pokemon (disponible gen1,2,3)\n");
        printf("2-Ver estado pokemon elegido\n");
        printf("3-Combatir pokemones\n");
        printf("4-Terminar ejecucion\nElijo... ");
        
        if (scanf("%i", &input_usuario) != 1) {
            while(getchar() != '\n'); // Limpia el buffer
            input_usuario = 0; // Para que no se salga
        }
        
        if(input_usuario == 1){
            printf("funicon por añadir\n");
        }
        if(input_usuario == 2){
            char pokemon_elegido[30];
            printf("Que pokemon desea ver (Ej: Cubone)??");
            scanf(" %29[^\n]",pokemon_elegido);
            mostrarEstado(vector_pokemon,pokemon_elegido,tamano_p);
        }
        if(input_usuario == 3){
            char pokemon_elegido_1[30];
            char pokemon_elegido_2[30];
            printf("Ingrese pokemon_1 (atacante)");
            scanf(" %29[^\n]",pokemon_elegido_1);
            
            printf("Ingrese pokemon_2 (defensor)");
            scanf(" %29[^\n]",pokemon_elegido_2);
            
            simularCombate(pokemon_elegido_1,pokemon_elegido_2,vector_pokemon,tamano_p);
        }
    }while (input_usuario != 4);
    
    free(vector_pokemon);
    free(vector_ataques);
    return 0;
}
