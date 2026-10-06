#include <stdio.h>

#define N 9

int main()
{
    int n;
    scanf("%i",&n);
    
    int numero[N];
    int i;
    for(i=N-1;i>=0;i--){
        numero[i]=n%10;
        n=n/10;
    }
    
    for(i=0;i<N-1;i++){
        if(i%2!=0) numero[i]=numero[i]*2;
    }
    
    for(i=0;i<N-1;i++){
        if(numero[i] >= 10) numero[i]=numero[i]%9;
    }
    
    int acumulador;
    acumulador=0;
    for(i=0;i<N-1;i++){
        acumulador+=numero[i];
    }
    
    int resultado_formula = 10-(acumulador % 10);
    
    if(resultado_formula == numero[N-1]) printf("OK");
    else printf("FAIL");
    
    return 0;
}
