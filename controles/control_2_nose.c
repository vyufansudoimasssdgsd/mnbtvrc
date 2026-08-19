#include <stdio.h>

int main()
{
	int i,exit,n,o_detectados,c_libres,e_filtro;
	
	do
	{
		exit=1;
		o_detectados=0;
		c_libres=0;
		e_filtro=0;
		
		printf("### Sistema de Procesamiento de Sensores para IA\n");
		
		for (i =1 ; i<=10 ; i++)
		{
			scanf("%i\n",&n);
			printf("lectura %i: %i",i,n);
			
			if (n<0 || n>=500)
			{
				printf("     ADVERTENCIA: ¡Error de sensor! Lectura fuera de rango. \n");
				e_filtro+=1;
			}
			else if (n<20)
			{
				printf("     ¡ALERTA: Obstáculo detectado!\n");
				o_detectados+=1;
			}
			else
			{
				printf("     Camino libre.\n");
				c_libres+=1;
			}
			
		}
		printf("...\n");
		printf(" \n");
		printf("### Resumen\n");
		printf("Caminos libres detectados: %i\n",c_libres);
		printf("Obstáculos detectados: %i\n",o_detectados);
		printf("Errores de sensor filtrados: %i\n",e_filtro);
		printf(" \n");
		printf("¿Desea ejecutar otra simulación? (1 = Sí, 0 = No):\n");
		scanf("%i",&exit);
	}	
	while (exit == 1);
	printf("Sistema de IA out.");
	
	
	return 0;
}