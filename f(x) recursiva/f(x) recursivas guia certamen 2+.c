#include <stdio.h>

#define N 10

int suma_consumo(int consumo[],int n)
{
    //caso base ir sumando el numero con return 
    //caso limite, n==0
    
    if(n==0) return 0;
    
    else if(n>0) return consumo[n-1] + suma_consumo(consumo,n-1);
    
}

int maximo_consumo(int consumo[], int n)
{
    //caso base, el 1er "maximo"
    if(n==1) return consumo[0];
    
    int max_resto = maximo_consumo(consumo,n-1);
    
    if(consumo[n-1] > max_resto) return consumo[n-1];
    return max_resto;
    
    
}

int contar_sobre_umbral(int consumo[], int n, float umbral)
{
    if(n==0) return 0;
    
    if(consumo[n]>umbral) return 1 + contar_sobre_umbral(consumo,n-1,umbral);
    else return contar_sobre_umbral(consumo,n-1,umbral);
}

int suma_digitos(int numero)
{
    if(numero<10)return numero;
    
    return numero%10 + suma_digitos(numero/10);
    
    
}


int main()
{
    int consumo[N]={1,2,3,4,5,6,7,8,9,10};
    
    printf("suma total de consumo = %i \n",suma_consumo(consumo,N));
    
    printf("sobre umbral en consumo = %i\n",contar_sobre_umbral(consumo,N,5));
    
    printf("suma 3623 = %i \n",suma_digitos(3623));
    
    
    return 0;
}
