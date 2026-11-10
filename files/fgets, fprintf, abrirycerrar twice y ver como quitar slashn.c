#include <stdio.h>
#include <stdlib.h>

int main()
{
    // r=reading , w=writting, a=add
    //crear archivo, similar crear dinamico
    
    //w crea o sobreescribe archivos
    FILE *archivo = fopen("Aja.txt","wt");
    //verificar no NULL
    if(archivo == NULL){
        printf("ERROR no s epudo crear archivo \n");
        return EXIT_FAILURE;
    }
    
    //ingresar lineas que me pedia el problema
    fprintf(archivo,"La casa de juanita\n");
    fprintf(archivo,"es blanca y tiene\n");
    fprintf(archivo,"ventanas redondas\n");
    
    fclose(archivo);
    //cerrar y volver a abrir el archivo para que el cursor vuelva al inicio
    
    //abrir con rt, no es necesario volver a definir 
    archivo = fopen("Aja.txt","rt");
    if(archivo == NULL){
        printf("ERROR no s epudo crear archivo \n");
        return EXIT_FAILURE;
    }
    
    //leer cada linea hasta el final, va devolviendo el mismo puntero de cadena_lectura
    //pero si dice NULL es que se termino -> pillo EOF
    
    char cadena_lectura[80];
    while (fgets(cadena_lectura,80,archivo) != NULL){
        //OJO, que lo guarda con el \n incluido
        printf("lo que leyo fgets y le paso a cadena_lectura es %s",cadena_lectura);
    }
    
    fclose(archivo);
    /*para quitarle el \n si es necesario
    // Busca la posición del '\n' y lo reemplaza por el fin de string
    cadena_lectura[strcspn(cadena_lectura, "\n")] = '\0'; 
    
    // Ahora imprimimos (y tendremos que ponerle el \n nosotros si queremos)
    printf("Leido: %s\n", cadena_lectura);
    */
    
    /*txt -> Aja.txt
    La casa de juanita
    es blanca y tiene
    ventanas redondas
    */
    
    return 0;
}
