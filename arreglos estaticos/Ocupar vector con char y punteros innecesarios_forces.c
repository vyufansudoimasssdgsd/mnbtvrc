#include <stdio.h>

void calcular_minimo(char A[], int *n, int *k) //no cambia el valor de las cosas, punteros son innecesarios, pero bueno
{
    int i,j,l,flag,acumulador;
    
    l=0;
    acumulador=0;
    
    
    for(i=0;i<( *n/ *k);i++){
        
        flag=1;
        for(j=i;j<i+ *k;j++){ // si quito a l y ocupo como index mejor a i*k +j me lo quito de encima 
            
            if(A[l]== '0'){
                flag=0;
            }
            l+=1;
        }
        
        if (flag){
            acumulador+=1;
        }
    }
    printf("Es necesario construir minimo %i escuelas\n",acumulador);
    
}


int main()
{
    int t,k,n,i;
    
    //https://codeforces.com/problemset/problem/2259/A
    printf("Cuantos casos veremos hoy?");
    scanf("%i",&t);
    
    for(i=0;i<t;i++){
        printf("----------------------\n");
        printf("Cuantos campos hay?");
        scanf("%i",&n);
        
        printf("Cuantos campos tiene cada granja?");
        scanf("%i",&k);
        
        char A[n+1];
        
        printf("El string es...");
        scanf("%s", A);
        
        calcular_minimo(A,&n,&k);
        
        
    }


    return 0;
}
