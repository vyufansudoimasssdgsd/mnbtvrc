#include <stdio.h>
#include <stdlib.h>

/**/

int main()
{
    FILE *archivo = fopen("boleta.txt","wt");//Abre un archivo boleta.txt en modo escritura.
    if(archivo == NULL) return EXIT_FAILURE;
    
    char nombre[20];
    int precio;
    int cantidad;
    
    for(int i=0;i<3;i++){
        //Pide al usuario por teclado 3 productos (nombre, precio y cantidad).
        printf("ingrese el nombre del producto %i ",i+1);
        scanf(" %19[^\n]",nombre);
        
        printf("ingrese el precio del producto %i ",i+1);
        scanf(" %i",&precio);
        
        printf("ingrese la cantidad del producto %i ",i+1);
        scanf(" %i",&cantidad);
        
        //Usa fprintf para escribir cada producto en el archivo con el formato: Nombre Precio Cantidad\n.
        
        fprintf(archivo,"%.19s %i %i\n",nombre,precio,cantidad);
    }
    //Cierra el archivo.
    fclose(archivo);
    
    //Vuelve a abrir el archivo, pero en modo lectura. Usa un bucle while con fscanf para leer Nombre, Precio y Cantidad en variables temporales.
    
    archivo = fopen("boleta.txt","rt");
    if(archivo == NULL) return EXIT_FAILURE;
    
    int total_pagar=0;
    
    while( fscanf(archivo,"%s %i %i",nombre,&precio,&cantidad) == 3){
        //Calcula el total a pagar (Precio * Cantidad) y muéstralo por pantalla.
        
        total_pagar+=(precio*cantidad);
    }
    
    printf("EL totoal a pagar es de %i\n",total_pagar);
    
    return 0;
}
