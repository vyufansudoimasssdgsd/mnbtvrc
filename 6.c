#include <stdio.h>

int main()
{
    //define
    int gr;
    int zona;
    int cociente;
    int precio_gr;
    int por_cada_3_4;
    int base_adicional_4;
    int cf;

    base_adicional_4=0;
    por_cada_3_4=0;
    cociente=0;
    
    scanf("%i", &gr);
    scanf("%i", &zona);

    //definir variables por cada zona para formula general

    if (zona == 1)
    {
        precio_gr=2;
    }

    else if (zona == 2)
    {
        precio_gr=3;
    }

    else if (zona == 3)
    {
        precio_gr=5;
        por_cada_3_4=50;
        cociente=(gr-500)/500; // la division entera es con /, y como trabajo int se aproxima aautomaticamente
    }

    else if (zona == 4)
    {
        precio_gr=6;
        por_cada_3_4=60;
        cociente=(gr-500)/400;
        base_adicional_4=1000;
    }

    //calculo con formula general 

    if (gr > 500)
    {
        cf= ((por_cada_3_4)*(cociente)) + (precio_gr*(gr-500)) + base_adicional_4 + 700;
    }

    else
    {
        cf= 700 + base_adicional_4;
    }

    //salida de datos y prints

    printf("Monto a pagar por encomienda a zona %i es $%i", zona, cf);

}