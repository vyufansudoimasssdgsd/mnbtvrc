#include <stdio.h>


int crear_secuencia(long A[],long B[],int n)
{
    // hacer un if de si es impar o par el tamaño, para ver si simetrico o no 
    
    int sube,baja,i;
    sube=0;
    baja=n-1;
    
    if(n%2==0){ //simetrico
        // a medida que se la paso a otro vector, ocupar 2, uno sube y un baja
        for(i=0;i<n;i++){
            if(i%2==0){
                B[i]=A[sube];
                printf("%i ",B[i]);
                sube++;
            }
            else{
                B[i]=A[baja];
                printf("%i ",B[i]);
                baja--;
            }
        }
        printf("\n");
    }
    
    else{// si es asimetrico izq > der, simetrico == 
        // a medida que se la paso a otro vector, ocupar 2, uno sube y un baja
        for(i=0;i<n;i++){
            if(i==n-1){
            }
            else if(i%2==0){
                B[i]=A[sube];
                printf("%i ",B[i]);
                sube++;
            }
            else{
                B[i]=A[baja];
                printf("%i ",B[i]);
                baja--;
            }
        }
        printf("\n");
    }
}



int main(){
    
    //https://codeforces.com/problemset/problem/1462/A
    
    //sube por izq baja por der 
    // y eso te va a dar el vector ordenado como pedian
    // y hacer un prinf con f(x) hasta que se muestre entero
    
    
    int t,n,i;
    //primero que entre el dato con un scanf y printf
    printf("Cuantos casos veremos hoy?");
    scanf("%i",&t);
    
    while(t>0){
        
        printf("Ingrese el tamaño de la secuencia");
        scanf("%i",&n);
        
        long A[n];
        long B[n];
        
        //luego en base al tamaño, hacer el vector para pasarle al usuario
        for(i=0;i<n;i++){
            printf("ingrese la secuencia a utilizar");
            scanf("%ld",&A[i]); //recordar que es long
        }
        //llamar a una f(x) donde dentro de esta tomar el vector y crear otro vector referencial
        //para pasarselo y modificarlo allá
        crear_secuencia(A,B,n);
        
        
        
        t--;
    }
    
    
    
}