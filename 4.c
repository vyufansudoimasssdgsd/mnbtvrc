#include <stdio.h>

int main()
{
    //definir variables
    float kg;
    float m;
    float imc;
    
    // entrada
    
    scanf("%f", &kg);
    scanf("%f", &m);
    
    //procesar
    
    imc =  (kg)/(m*m);
    printf("imc = %.2f \n", imc);
    
    
    if (imc <= 17)
    {
        printf("Infrapeso");
    }
    
    else if ((imc > 17) && (imc <=18))
    {
        printf("Bajo Peso");
    }
    
    else if ((imc >18) && (imc <= 25))
    {
        printf("Peso Normal");
    }
    
    else if ((imc > 25) && (imc <=30))
    {
        printf("Sobrepeso");
    }
    
    else if ((imc > 30) && (imc <= 40))
    {
        printf("Obesidad");
    }
    
    else
    {
        printf("Obesidad Mórbida");
    }


    return 0;
}
