#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{//titulo, autor, codigo de barra, disponible/no disponible, 
    char titulo[20];
    char autor[20];
    int codigo_barra;
    int disponibilidad;
} info_libro;


int agregar_libro (info_libro **A, int size_vector)
{
    //para agregar aumentar el tamaño en 1 y agregarlos de manera directa
    
    //agregar +1
    size_vector++;              //en el realloc solo cambia *A poruqe es **A
    info_libro *temporal = (info_libro *) realloc (*A , sizeof(info_libro) * (size_vector));
    if(temporal == NULL){
        return -1;
    }
    *A=temporal;
    
    //escanear todos los datos necesarios
    //como es vector, ya es puntero, asi que . en vez ->
    
    info_libro nuevo_libro;
    
    printf("ingrese el titulo de la obra ");
    scanf(" %19[^\n]",nuevo_libro.titulo);
    
    printf("ingrese el autor de la obra ");
    scanf(" %19[^\n]",nuevo_libro.autor);
    
    printf("ingrese el codigo de barra ");
    scanf(" %i",&nuevo_libro.codigo_barra);
    
    //como se acaba de añadir si o si disponible
    nuevo_libro.disponibilidad=1;
    
    //agregar al original
    (*A)[size_vector-1]=nuevo_libro;
    
    return size_vector;
    
}

void prestar_libro (info_libro *A, int size_vector)
{
    //prestar ingresar titulo, si bien titulo , cambiar de 1 a 0, mal titulo, erroreo, decir si ya esta prestado
    
    //ingresar el titulo
    char titulo_buscado[20];
    printf("ingrese el titulo del libro a prestar ");
    scanf(" %19[^\n]",titulo_buscado);
    
    //buscar linealmente el libro con un for y ocupar el i como posicion para despues
    int se_encontro=0;
    int i;
    for(i=0;i<size_vector;i++){
        if(strcmp(A[i].titulo,titulo_buscado) == 0){
            se_encontro=1;
            break;
        }
    }
    //si se encontro, ver si esta disponibles
    if(se_encontro){
        //si esta disponible, cambiar a prestado
        if(A[i].disponibilidad){
            A[i].disponibilidad = 0;
            printf("El libro esta disponible para ser prestado\n");
        }
        //si no esta disponible
        else printf("El titulo si esta en la biblioteca, pero no disponible en este momento\n");
        
    }
    //sino no se encontro
    else{
        printf("El libro ingresado no esta registrado en la biblioteca\n");
    }
}

void devolver_libro (info_libro *A, int size_vector)
{
    //devolver libro, todo bien cambiar 0 a 1, mal titulo decir que no existe o mal, decir si ya esta devuelto
    
    //ingresar el titulo
    char titulo_buscado[20];
    printf("ingrese el titulo del libro a devolver ");
    scanf(" %19[^\n]",titulo_buscado);
    
    //buscar linealmente el libro con un for y ocupar el i como posicion para despues
    int se_encontro=0;
    int i;
    for(i=0;i<size_vector;i++){
        if(strcmp(A[i].titulo,titulo_buscado) == 0){
            se_encontro=1;
            break;
        }
    }
    //si se encontro, ver si esta devuelto
    if(se_encontro){
        //si esta, cambiar a devuelto
        if(A[i].disponibilidad == 0){
            A[i].disponibilidad = 1;
            printf("El libro ha sido devuelto exitosamente\n");
        }
        //si el libro ya esta devuelto
        else printf("El libro ya estaba devuelto o disponible en la biblioteca\n");
        
    }
    //sino no se encontro
    else{
        printf("El libro ingresado no esta registrado en la biblioteca\n");
    }
    
}

int lista_libro_disponibles (info_libro *A, int size_vector)
{
    //lista de libros disponibles crearla y mostrarla en base a 0 o 1 de prestado/no, lineal 
    
    //crear arreglo dinamico
    
    info_libro *lista_disponibles = NULL;
    
    //for viendo si esta disponible o no
    int size_disponibles=0;
    for(int i=0;i<size_vector;i++){
        //si lo esta size+1 y añadir
        if(A[i].disponibilidad){
            //size+1 y realloc 
            size_disponibles++;
            info_libro *temporal = (info_libro *) realloc (lista_disponibles, sizeof(info_libro) * size_disponibles);
            if(temporal == NULL) return -1;
            lista_disponibles = temporal;
            //añadir
            lista_disponibles[size_disponibles-1]=A[i];
        }
    }
    
    //al final otro for para printear disponibles
    if(size_disponibles >0){
        printf("LIsta de libros disponibles:\n");
        for(int i=0;i<size_disponibles;i++){
            printf("Titulo = %s \nAutor = %s\ncodigo de barra =%i\n",lista_disponibles[i].titulo,lista_disponibles[i].autor,lista_disponibles[i].codigo_barra);
        }
    }
    else printf("NO hay libros disponibles \n");
    
    free(lista_disponibles);
    return 0;
}

int lista_libro_autor (info_libro *A , int size_vector)
{
    //lista segun autor crear en base coincidencia con autor, busqueda lineal
    
    //pregutar autor buscado 
    char autor_buscado[20];
    printf("QUe autor dijiste ?");
    scanf(" %19[^\n]",autor_buscado);
    
    
    info_libro *lista_autores = NULL;
    
    //for viendo si coinciden o no
    int size_autores=0;
    
    for(int i=0;i<size_vector;i++){
        //si lo esta size+1 y añadir
        if(strcmp(A[i].autor,autor_buscado) == 0){
            //size+1 y realloc 
            size_autores++;
            info_libro *temporal = (info_libro *) realloc (lista_autores, sizeof(info_libro) * size_autores);
            if(temporal == NULL) return -1;
            lista_autores = temporal;
            //añadir
            lista_autores[size_autores-1]=A[i];
        }
    }
    
    //al final otro for para printear titulos segun autor 
    
    if(size_autores>0){
        printf("LIsta de libros del autor %s:\n",autor_buscado);
        for(int i=0;i<size_autores;i++){
            printf("Titulo = %s \nCodigo de barra =%i\nDisponibilidad %i\n",lista_autores[i].titulo,lista_autores[i].codigo_barra,lista_autores[i].disponibilidad);
        }
    }
    else printf("No hay libros para ese autor\n");
    
    free(lista_autores);
    return 0;
}

int main()
{
    //la base de la biblioteca va a ser un vector dinamico
    
    //crear vector
    //cada valor en el vector va a ser un struct
    info_libro *vector = NULL;
    
    int opcion;
    int size_vector=0;
    int fallo=0;
    do
    {
        //hacer un "menu" con varios if, de agregar, pretar, devolver, lista libros disponible, disponible segun autor
        printf("---------MENU_BIBLIOTECA---------\n");
        printf("Opcion 1: agregar libro\nOpcion 2: prestar libro\n");
        printf("Opcion 3: devolver libro\nOpcion 4: lista de libros disponibles (titulos/autor)\n");
        printf("Opcion 5: lista de libros según autor\nSi desea salir del menu escriba -1 \n");
        printf("Elijo... ");
        scanf("%i",&opcion);
        
        if(opcion == 1) {
            size_vector = agregar_libro(&vector,size_vector);
            if(size_vector == -1){
                free(vector);
                return EXIT_FAILURE;    
            }
        }  
        if(opcion == 2) prestar_libro(vector,size_vector);
        if(opcion == 3) devolver_libro(vector,size_vector);
        if(opcion == 4){
            fallo = lista_libro_disponibles(vector,size_vector);
            if(fallo == -1){
                free(vector);
                return EXIT_FAILURE;
            }
        }
        
        if(opcion == 5){
            fallo = lista_libro_autor(vector,size_vector);
            if(fallo ==-1){
                free(vector);
                return EXIT_FAILURE;
            }
        }
        
        
    }while(opcion !=-1);
    
    free(vector);
    
}
