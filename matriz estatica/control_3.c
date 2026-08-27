#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{ 
	int p_regionales[12];
	int i;
	float p_regional,dat1,dat2,dat3,max,max_mes,promedio_12_meses,max_indice;
	
	
	max_indice=-1;
	max=-1;
	max_mes=-1;
	p_regional=100;
	printf("### Lectura de datos\n");
	for (i=1 ; i<=2 ; i++)
	{
		printf("Mes %i (angers, nantes, rennes):",i);
		scanf("%f",&dat1);
		scanf("%f",&dat2);
		scanf("%f",&dat3);
		p_regional=(dat1+dat2+dat3)/3;
		p_regionales[i]=p_regional;
				
		if (dat1 > max)
		{
			max=dat1;
			max_mes=i;
			max_indice=0;
		}
		if (dat2 > max)
		{
			max=dat2;
			max_mes=i;
			max_indice=1;
		}
		if (dat3 > max)
		{
			max=dat3;
			max_mes=i;
			max_indice=2;
		}
	}
	
	
	
	//prints
	printf("### Promedios mensuales regionales\n");
	for (i=1 ; i<=2 ; i++)
	{
		printf("Mes %i: %.2f mm\n",i,p_regionales[i]);
		promedio_12_meses+=p_regionales[i];
	}
	
	promedio_12_meses=promedio_12_meses/2;
	
	printf("### Analisis climatologico\n");
	
	if (max_indice == 0)
	{
		printf("### Máximo registrado: %.2f mm (Angers mes %i)\n",max,max_mes);
	}
	else if (max_indice == 1)
	{
		printf("### Máximo registrado: %.2f mm (Rennes mes %i)\n",max,max_mes);
	}
	else if (max_indice == 2)
	{
		printf("### Máximo registrado: %.2f mm (Nantes mes %i)\n",max,max_mes);
	}
	
	printf("Promedio regional: %.2f mm\n",promedio_12_meses);
	
	if (promedio_12_meses < 50)
	{
		printf("Clima seco");
	}
	else if (promedio_12_meses >=50 && promedio_12_meses<= 65)
	{
		printf("Clima moderado");
	}
	else
	{
		printf("Clima lluvioso");
	}
	
	
	
}
