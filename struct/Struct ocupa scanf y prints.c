#include <stdio.h>

typedef struct 
{
    char nombre[21];
    int duracion_segundos;
} tipoCancion;


int main()
{
    //crear y la otra pedir
    
    tipoCancion Lala = {"Lala, de Lolo", 361};
    tipoCancion pedida_usuario;
    //char sin & por amor de la Kira 
    scanf("%20[^\n] %i", (pedida_usuario.nombre), &(pedida_usuario.duracion_segundos));
    
    printf("Su cancion pedida fue %s con duracion %i\n", pedida_usuario.nombre, pedida_usuario.duracion_segundos);
    printf("Nuestra cancion pedida fue %s con duracion %i\n", Lala.nombre, Lala.duracion_segundos);
    
    return 0;
}
