#include <stdio.h>
#include <stdlib.h>

/*
La biblioteca
Una biblioteca quiere implementar un sistema para organizar mejor su catálogo y distintas
funcionalidades. Tomando en cuenta que cada libro cuenta con ciertos atributos (código,
autor, etc.) , diseñe un programa que pueda cumplir las siguientes funciones :
● agregar libro
● prestar libro
● devolver libro
● lista de libros disponibles
● lista de libros según su autor

*/

typedef struct
{//titulo, autor, codigo de barra, disponible/no disponible, 
    char titulo[20];
    char autor[20];
    int codigo_barra;
    int disponibilidad;
} info_libro;

int agregar_libro (info_libro *A, int size_vector)
{
    //para agregar scanear todos los datos necesarios en uno temporal y al final agregarlos al vector dinamico
    //antes de agregar +1size
    
    return 0;
}

void prestar_libro (info_libro *A, int size_vector)
{
    //prestar ingresar titulo, si bien titulo , cambiar de 1 a 0, mal titulo, erroreo, decir si ya esta prestado
    
    
}

void devolver_libro (info_libro *A, int size_vector)
{
    //devolver libro, todo bien cambiar 0 a 1, mal titulo decir que no existe o mal, decir si ya esta devuelto
    
    
}

void lista_libro_disponibles (info_libro *A, int size_vector)
{
    //lista de libros disponibles crearla y mostrarla en base a 0 o 1 de prestado/no, lineal 
    
    
}

void lista_libro_autor (info_libro *A , int size_vector)
{
    //lista segun autor crear en base coincidencia con autor, busqueda lineal
    
    
}

int main()
{
    //la base de la biblioteca va a ser un vector dinamico
    
    //crear vector
    //cada valor en el vector va a ser un struct
    info_libro *vector = NULL;
    
    int opcion;
    int size_vector=0;
    
    do
    {
        //hacer un "menu" con varios if, de agregar, pretar, devolver, lista libros disponible, disponible segun autor
        printf("---------MENU_BIBLIOTECA---------\n");
        printf("Opcion 1: agregar libro\nOpcion 2: prestar libro\n");
        printf("Opcion 3: devolver libro\nOpcion 4: lista de libros disponibles (titulos/autor)\n");
        printf("Opcion 5: lista de libros según autor\nSi desea salir del menu escriba -1 \n");
        printf("Elijo... ");
        scanf("%i",&opcion);
        
        if(opcion == 1) size_vector = agregar_libro(vector,size_vector);
        if(opcion == 2) prestar_libro(vector,size_vector);
        if(opcion == 3) devolver_libro(vector,size_vector);
        if(opcion == 4) lista_libro_disponibles(vector,size_vector);
        if(opcion == 5) lista_libro_autor(vector,size_vector);
        
        
    }while(opcion !=-1);
    
}
