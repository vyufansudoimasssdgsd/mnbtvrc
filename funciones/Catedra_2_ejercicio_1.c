#include <stdio.h>

void calcular_montos_billetes(int tipo_billetes [] , int monto)
{	
	//la idea es que se acabe el maximo del monto en cada caso
	while(monto >=20000){
		tipo_billetes[4]+=1;
		monto+=-20000;
	}
	
	while(monto >=10000){
		tipo_billetes[3]+=1;
		monto+=-10000;
	}
	
	while(monto >=5000){
		tipo_billetes[2]+=1;
		monto-=5000;
	}
	
	while(monto >=2000){
		tipo_billetes[1]+=1;
		monto+=-2000;
	}
	
	while(monto >=1000){
		tipo_billetes[0]+=1;
		monto+=-1000;
	}
	
}


int main()
{
	//ingresar datos
	int monto_ingresado,i;
	int flag=0;
	scanf("%i",&monto_ingresado);
	
	int tipo_billetes[5];
	// 1, 2, 5, 10, 20 
	// 0 1 2 3 4 es el index
	
	calcular_montos_billetes(tipo_billetes,monto_ingresado);
	
	for(i=0;i<5;i++){ //flag es para revisar si hay error con el monto
		if(tipo_billetes[i] != 0)flag=1;
	}
	
	printf("INPUT              OUTPUT\n");
	printf("-------------------------\n");
	
	if(flag)printf("%i\n",monto_ingresado);
	else printf("%i        ERROR: cantidad invalida\n",monto_ingresado);
	if(tipo_billetes[4] != 0)printf("           20.000 (x%i)\n",tipo_billetes[4]);
	if(tipo_billetes[3] != 0)printf("           10.000 (x%i)\n",tipo_billetes[3]);
	if(tipo_billetes[2] != 0)printf("           5.000 (x%i)\n",tipo_billetes[2]); //REVISAR ERROR CON 5.000
	if(tipo_billetes[1] != 0)printf("           2.000 (x%i)\n",tipo_billetes[1]);
	if(tipo_billetes[0] != 0)printf("           1.000 (x%i)\n",tipo_billetes[0]);

	printf("-------------------------\n");
	
	return 0;
}



//1 sola f(x) aparte del mauin

//2 f(x), orden,busqueda

//bonus ruteo codigo, que se muestra ??
