#include <stdlib.h>
#include <stdio.h>

int main()
{
	//Crear archivo, leer
	FILE *archivo = fopen("incidentes_ms.csv","rt");
	if(archivo == NULL) return EXIT_FAILURE;
	
	FILE *archivo_2 = fopen("criticos.csv","wt"); //DEL BONUS
	if(archivo_2 == NULL) return EXIT_FAILURE;
	
	float minutos_caidos_total=0;
	int contador_america=0;
	int contador_casos=0;
	
	int id_servidor;
	char codigo_region;
	int minutos_caidos;
	int nivel_criticidad;
	
	char coma;
	
	//caso 2 while fscanf ==1 y getc != EOF
	//ID_Servidor,Codigo_Region,Minutos_Caido,Nivel_Criticidad
	while( fscanf(archivo,"  %i %c %c %c %i %c %i",&id_servidor,&coma,&codigo_region,&coma,&minutos_caidos,&coma,&nivel_criticidad) == 7) {
		minutos_caidos_total+=minutos_caidos;
		contador_casos++;
		if(codigo_region == 'A') contador_america++;
		
		if(nivel_criticidad == 5){ //parte Bonus
			fprintf(archivo_2,"%i,%i\n",id_servidor,minutos_caidos); //agregar lo del Bonus
		}
	}
	
	printf("\nEl promedio de minutos caídos considerando todos los servidores del archivo es %.2f\n",minutos_caidos_total/contador_casos);
	printf("La cantidad total de servidores afectados en la región de América es de %i\n",contador_america);
	
	
	fclose(archivo);
	fclose(archivo_2);
	
	return 0;
	
}
