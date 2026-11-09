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
    int PV;
    ataque mov_1;
    ataque mov_2;
} pokemon;


void mostrarEstado(pokemon p)
{ //p.mov_1.tipo,p1.mov_1.poder,p1.mov_1.energia);
    if(p.PV > 0)printf("EL pokemon %s, de tipo %s , tiene; PS = %i\n",p.nombre,p.tipo,p.PV,p.mov_1.nombre);
    printf("mov_1 = %s , tipo %s , poder %i, energia %i \n",p.mov_1.nombre,p.mov_1.tipo,p.mov_1.poder,p.mov_1.energia);
    
    
}

void simularCombate(pokemon *p1, pokemon *p2)    //tengo que pasar por referencia ajjajajaj
{//pi ataca, p2 sobrevive/o no
    
    //es como hacer combate, energia se quita a quien lo tira y poder al otro
    
    //elegir ataque de manera random
    if(rand()%2){
        //mov_1
        //restar vida al atacante
        p2->PV-=p2->mov_1.energia;
        //restar vida al defensor
        p1->PV-=p2->mov_1.poder;
        //imprimir mensaje
        printf("El pokemon %s ataco con %s a %s, realizando %i de daño\n",p1->nombre,p1->mov_1.nombre,p2->nombre,p2->mov_1.poder);
    }
    else{
        //mov_2
        //restar vida al atacante
        p2->PV-=p2->mov_2.energia;
        //restar vida al defensor
        p1->PV-=p2->mov_2.poder;
        //imprimir mensaje
        printf("El pokemon %s ataco con %s a %s, realizando %i de daño\n",p1->nombre,p1->mov_1,p2->nombre,p2->mov_2.poder);
    }
    
    //mantener el resto ==
    
    //CAMBIAR PlACAJE DESPUES.. //dejar espacio para dato de espacio de pokemon como comentario JJJAJjJA
    
    
    //si p1 se debilita o sigue vivo
    if(p1->PV>=0) printf("El pokemon %s quedo con %i PV\n");
    else printf("El pokemon %s esta KO, su energia lo alcanzo\n");
    
    //if p2.PV <=0 K.O ,sino, se sigue la batalla
    if(p1->PV <=0)printf("EL pokemon %s esta fuera de combate\n",p1->nombre);
    else printf("El pokemon %s le quedan %i PV, el combate sigue en pie\n",p1->nombre,p1->PV);
}



int main()
{
    srand(time(NULL));
    //Asi inicializar struct
    pokemon muk = {"Muk", "Veneno", 414, {"PLACAJE","Normal",10,2},{"Trasnformacion","Psiquico",0,5}}; 
    pokemon mew = {"Mew", "Psiquico", 404, {"PLACAJE","Normal",10,2},{"Fuerza","Normal",30,5}}; 
    
    mostrarEstado(muk);
    mostrarEstado(mew);
    simularCombate( &muk, &mew);
    
    
    return 0;
}
