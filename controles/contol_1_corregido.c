#include <stdio.h>

int main ()
{
	//definir
	
	int membresia;
	
	float monto;
	
	int destino;
	
	int express;
	
	float descuento;
	
	int tarifa_base;
	
	int tarifa_express;
	
	int comision_estandar;
	
	float costo_f;
	
	float costo_envio;
	
	//entrada
	
	scanf(" %i", &membresia);
	scanf(" %f", &monto);
	scanf(" %i", &destino);
	scanf(" %i", &express);
	
	
	//definir porcentajes
	
	descuento=1; // en el caso de que no se aplique ninguno, para que no se haga 0 
	
	if (membresia == 1 && monto > 300)
	{
		descuento = 0.95;
	}
	
	if (membresia == 2 && monto <= 200)
	{
		descuento = 0.95;
	}
		
	if (membresia == 2 && monto > 200)
	{
		descuento = 0.9;
	}
	
	if (membresia == 3 && monto <= 200)
	{
		descuento = 0.85;
	}
		
	if (membresia == 3 && monto > 200)
	{
		descuento = 0.8;
	}
	
	//Tarifa base
	
	if (destino == 0) //nacional
	{
		tarifa_base = 10;
	}

	if (destino == 1) //internacional
	{
		tarifa_base= 30;
	}
	
	//recargos
	
	if (express==1)
	{
		tarifa_express=15;
	}
	
	if (membresia == 3 && monto >150)
	{
		tarifa_base=0;
	}
	
	if (membresia == 1 && monto < 100)
	{
		comision_estandar=10;
	}
	
	//calculo
	
	costo_envio=tarifa_base + tarifa_express + comision_estandar;
	
	costo_f=monto*descuento;
	
	printf("Precio final: %.2f \n",costo_f);
	printf("Costo del envio: %.2f",costo_envio);	
	
}








