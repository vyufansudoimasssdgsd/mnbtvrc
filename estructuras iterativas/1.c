#include <stdio.h>

int main()
{
    int a,b, a_sin,b_sin, cociente, suma_normal, suma_sin,suma_quitando; 
    float i;
    
    //debo sacar los 0 en los calculos y resultados, ¿como?, nose, pero es lo "facil"
    
    
    
    b_sin=0;
    a_sin=0;
    suma_quitando=0;
    i=0.1;
    
    scanf("%i",&a);
    scanf("%i",&b);
    
    suma_normal=a+b;
    
    while (a>0)
    {
        if (a%10!=0 && a!=0)
        {
            cociente=a%10;
            a=a/10;
            i=i*10;
            a_sin+=cociente*i;
        }
        else if (a%10==0 && a!=0)
        {
            a=a/10;
        }
    }
    
    i=0.1;
    cociente=0;
    
    while (b>0)
    {
        if (b%10!=0 && b!=0)
        {
            cociente=b%10;
            b=b/10;
            i=i*10;
            b_sin+=cociente*i;
        }
        else if (b%10==0 && b!=0)
        {
            b=b/10;
        }
    }
    
    i=0.1;
    cociente=0;
    
    while (suma_normal>0)
    {
        if (suma_normal%10!=0 && suma_normal!=0)
        {
            cociente=suma_normal%10;
            suma_normal=suma_normal/10;
            i=i*10;
            suma_quitando+=cociente*i;
        }
        else if (suma_normal%10==0 && suma_normal!=0)
        {
            suma_normal=suma_normal/10;
        }
    }
    
    suma_sin=a_sin+ b_sin;
    
    
    if (suma_quitando == suma_sin)
    {
        printf("SI");
    }
    else
    {
        printf("NO");
    }
    
}
