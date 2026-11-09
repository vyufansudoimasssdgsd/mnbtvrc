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
    float energia;
} ataque;

typedef struct
{
    char nombre[30];
    char tipo[20];
    float PV;
    ataque mov_1;
    ataque mov_2;
} pokemon;


void mostrarEstado(pokemon p)
{ //p.mov_1.tipo,p1.mov_1.poder,p1.mov_1.energia);
    if(p.PV < 0)printf("EL pokemon %s, de tipo %s , tiene; PS = 0.00\n",p.nombre,p.tipo,p.PV);
    else printf("EL pokemon %s, de tipo %s , tiene; PS = %.2f\n",p.nombre,p.tipo);
    printf("mov_1 = %s , tipo %s , poder %.2f, energia %.2f \n",p.mov_1.nombre,p.mov_1.tipo,p.mov_1.poder,p.mov_1.energia);
    printf("mov_2 = %s , tipo %s , poder %.2f, energia %.2f \n\n",p.mov_2.nombre,p.mov_2.tipo,p.mov_2.poder,p.mov_2.energia);
    
}

void simularCombate(pokemon *p1, pokemon *p2)    //tengo que pasar por referencia ajjajajaj
{//p1 ataca, p2 sobrevive/o no

    //es como hacer combate, energia se quita a quien lo tira y poder al otro
    
    //ver lo de simular el clima, segun rand que salgan 1 de 4 
    //rand()%4 0 a 3 c/u 
    
    int clima=rand()%4;
    int potenciar_clima=0;
    
    if(clima == 0){//0 = soleado
        if(strcmp(p1->tipo,"planta") == 0)potenciar_clima=1;
        if(strcmp(p1->tipo,"fuego") == 0)potenciar_clima=1;
        if(strcmp(p1->tipo,"tierra") == 0)potenciar_clima=1;
    } 
    if(clima == 1){// 1 = Lluvioso
        if(strcmp(p1->tipo,"agua") == 0)potenciar_clima=1;
        if(strcmp(p1->tipo,"electrico") == 0)potenciar_clima=1;
        if(strcmp(p1->tipo,"insecto") == 0)potenciar_clima=1;
    }
    if(clima == 2){// 2 = Semi_nublado
        if(strcmp(p1->tipo,"normal") == 0)potenciar_clima=1;
        if(strcmp(p1->tipo,"roca") == 0)potenciar_clima=1;
    }
    if(clima == 3){// 3 = Nublado
        if(strcmp(p1->tipo,"hada") == 0)potenciar_clima=1;
        if(strcmp(p1->tipo,"lucha") == 0)potenciar_clima=1;
        if(strcmp(p1->tipo,"veneno") == 0)potenciar_clima=1;
    }
    
    if(potenciar_clima)printf("Se potencio el ataque gracias al clima\n");
    //else if strcmp == 0 ,flag ->  p1->mov_x.tipo -= *1.5
    
    //elegir ataque de manera random
    int n_random=rand()%2;
    if(n_random == 1){
        //mov_1
        //restar vida al atacante
        p1->PV-=p1->mov_1.energia;
        //restar vida al defensor
        if(potenciar_clima) p2->PV-=((p1->mov_1.poder)*(1.5));
        else p2->PV-=p1->mov_1.poder;
        //imprimir mensaje
        if(potenciar_clima)printf("El pokemon %s ataco con %s a %s, realizando %.2f de daño\n",p1->nombre,p1->mov_1.nombre,p2->nombre,(p1->mov_1.poder)*(1.5));
        else printf("El pokemon %s ataco con %s a %s, realizando %.2f de daño\n",p1->nombre,p1->mov_1.nombre,p2->nombre,p1->mov_1.poder);
    }
    else{
        //mov_2
        //restar vida al atacante
        p1->PV-=p1->mov_2.energia;
        //restar vida al defensor
        if(potenciar_clima) p2->PV-=((p1->mov_2.poder)*(1.5));
        else p2->PV-=p1->mov_2.poder;
        //imprimir mensaje
        if(potenciar_clima) printf("El pokemon %s ataco con %s a %s, realizando %.2f de daño\n",p1->nombre,p1->mov_2.nombre,p2->nombre,(p1->mov_2.poder)*(1.5));
        else printf("El pokemon %s ataco con %s a %s, realizando %.2f de daño\n",p1->nombre,p1->mov_2.nombre,p2->nombre,p1->mov_2.poder);
    }
    
    //mantener el resto ==
    
    //CAMBIAR PlACAJE DESPUES.. //dejar espacio para dato de espacio de pokemon como comentario JJJAJjJA
    
    
    //si p1 se debilita o sigue vivo
    if(p1->PV>=0) printf("El pokemon %s quedo con %.2f PV\n",p1->nombre,p1->PV);
    else printf("El pokemon %s esta KO, su energia lo alcanzo\n",p1->nombre);
    
    //if p2.PV <=0 K.O ,sino, se sigue la batalla
    if(p2->PV <=0)printf("EL pokemon %s esta fuera de combate\n",p2->nombre);
    else printf("El pokemon %s le quedan %.2f PV, el combate sigue en pie\n",p2->nombre,p2->PV);
}



int main()
{
    srand(time(NULL));
    //Asi inicializar struct de ejemplo
    pokemon muk = {"Muk", "veneno", 414, {"PLACAJE","Normal",10,2},{"Fuerza","normal",30,5}}; 
    pokemon mew = {"Mew", "psiquico", 404, {"PLACAJE","Normal",10,2},{"Trasnformacion","psiquico",0,5}}; 
    int input_usuario;
    do{
        printf("-----------------MENU----POKEMON-----------------\n");
        printf("1-Agregar Pokemon (disponible gen1,2,3)\n");
        printf("2-Ver estado pokemon elegido\n");
        printf("3-Combatir pokemones\n");
        printf("4-Revivir Maximo + Restaura todo\n")
        printf("5-Terminar ejecucion\nElijo... ");
        scanf("%i",&input_usuario);
        
        if(input_usuario == 1){
            printf("funicon por añadir\n");
        }
        if(input_usuario == 2){
            char pokemon_elegido[30];
            printf("Que pokemon desea ver ??");
            scanf(" %29[^\n]",pokemon_elegido);
            //ver manera de buscarlo en el txt si esta y hacerlo coincidir con struct 
            if(1/*si esta*/) mostrarEstado(/*struct pokemon elegido*/);
            else printf("El pokemon mencionado no esta en la pokedex\n");
        }
        if(input_usuario == 3){
            char pokemon_elegido_1[30];
            char pokemon_elegido_2[30];
            printf("Ingrese pokemon_1 (atacante)");
            scanf(" %29[^\n]",pokemon_elegido_1);
            //buscarlo en el txt y hacerlo coincidir, o decir si no (while), tambien decir si esta KO
            
            printf("Ingrese pokemon_2 (defensor)");
            scanf(" %29[^\n]",pokemon_elegido_2);
            //buscarlo en el txt y hacerlo coincidir, o decir si no (while), tambien decir si esta KO
            
        }
        if(input_usuario == 4){
            char pokemon_elegido[30];
            printf("ingrese el pokemon a tratar\n");
            scanf(" %29[^\n]",pokemon_elegido);
            //buscarlo en el txt y hacerlo coincidir, o decir si no (while)
            
        }
    }while (input_usuario != 5);
    
    
    return 0;
}
