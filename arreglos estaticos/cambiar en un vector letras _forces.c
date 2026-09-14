#include <stdio.h>

int main()
{
    //https://codeforces.com/problemset/problem/1873/D
    int t,i,j;
    long n,k,contador_negros,multiplo_k,acumulador_k;
    
    printf("cuantos casos vereoms hoy? ");
    scanf("%i",&t);
    
    for(i=0;i<t;i++){
        
        printf("cuantas hojas son? ");
        scanf("%ld",&n);
        
        char s[n+1];
        
        printf("Y cuantos podemos cambiar a la vez? ");
        scanf("%ld",&k);
        
        printf("Y cual va a ser el patron de esta vez? ");
        scanf(" %s",s); // %s es para strings, 
        

        
        //1 pasar de string a vector, xD , ya es un vector en si 
        
        contador_negros=0;
        multiplo_k=0;
        acumulador_k=0;
        printf("---------------------------------\n");
        for(j=0;j<n;j++){  //2 hacer un for que avance de izq a der 
        
            //3 si en el for se detecta una negra contador de cuantos hay seguidos
            if(s[j] == 'B'){
                contador_negros+=1;
            }
            else if(s[j] == 'W' && contador_negros !=0){
                //4 si se detecta todos seguidos, segun el k "cambiarlos" (calcular)
                
                while(contador_negros - (k*multiplo_k) >= 0){
                    multiplo_k+=1;
                    acumulador_k+=1;
                }
                //5 si ya se paso el paso 4, saltar con i todos los innecesarios y seguir buscando (i+ k*veces ocupados de k);
                i+=multiplo_k;
                multiplo_k=0;
                contador_negros=0;
            }
            else if(s[j] == 'W' && contador_negros == 0){
            }
            
            
        }
        
        printf("Las veces que fue necesario como minimo ocupar k son de %ld\n", acumulador_k);
        printf("---------------------------------\n");
        
    }
    
    
    return 0;
}
