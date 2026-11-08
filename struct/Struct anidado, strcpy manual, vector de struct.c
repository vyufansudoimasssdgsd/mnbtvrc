#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char nombre[30];
    char apellido[30];
} nombre_persona;

typedef struct
{
    char rut[11];
    nombre_persona nombre_apellido;
} tipoPersona;

int main()
{
    //ingresar los N datos a ser ingresados
    int N;
    printf("Cuantos datos ingresaremos hoy? ");
    scanf("%i",&N);
    
    tipoPersona vector[N];
    //for de N tamaño para ir guardando los datos
    
    for(int i=0;i<N;i++){
        
        printf("Ingrese su rut (ej;24567121-9)");
        scanf(" %10[^\n]",vector[i].rut);
        while (getchar() != '\n');
        
        printf("Ingrese su nombre");
        scanf(" %29[^\n]",vector[i].nombre_apellido.nombre);
        while (getchar() != '\n');
        
        printf("Ingrese su apellido");
        vector[i].nombre_apellido.apellido[0] = '\0';
        scanf("%29[^\n]",vector[i].nombre_apellido.apellido);
        while (getchar() != '\n');
        
        //si no se puso nada en apellido, separarlo del nombre
        int j,k,l;
        if(strlen(vector[i].nombre_apellido.apellido) == 0){
            for(j=0; vector[i].nombre_apellido.nombre[j] != '\0' ;j++){
                if(vector[i].nombre_apellido.nombre[j] == ' '){
                    //el apellido va a ser desde el index j hasta size-1
                    l=0;
                    int largo_nombre=strlen(vector[i].nombre_apellido.nombre);
                    for(k=j+1;k<largo_nombre;k++){
                        vector[i].nombre_apellido.apellido[l] = vector[i].nombre_apellido.nombre[k];
                        l++;
                    }
                    
                    //agregar '\0'
                    vector[i].nombre_apellido.apellido[l]='\0';
                    
                    //dejar bien nombre 
                    vector[i].nombre_apellido.nombre[j] ='\0'; //cortar hasta el nombre
                    break;
                }
            }
        }
    }
    
    //estandarizar nombre y apellido con for y cambiar 1era letra y demás
    
    //for para todo el vector
    for(int i=0;i<N;i++){
        //for nombre y otro apellido
        for(int j=0;vector[i].nombre_apellido.nombre[j] != '\0';j++){
            if(j == 0){
                vector[i].nombre_apellido.nombre[j]=toupper(vector[i].nombre_apellido.nombre[j]);
            }
            else vector[i].nombre_apellido.nombre[j]=tolower(vector[i].nombre_apellido.nombre[j]);
        }
        for(int j=0;vector[i].nombre_apellido.apellido[j] != '\0';j++){
            if(j == 0){
                vector[i].nombre_apellido.apellido[j]=toupper(vector[i].nombre_apellido.apellido[j]);
            }
            else vector[i].nombre_apellido.apellido[j]=tolower(vector[i].nombre_apellido.apellido[j]);
        }
        printf("nombre %s apellido %s stand\n",vector[i].nombre_apellido.nombre,vector[i].nombre_apellido.apellido);
    }

    return 0;
}
