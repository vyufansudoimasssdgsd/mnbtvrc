#include <stdio.h>
#include <stdlib.h>

//https://codeforces.com/problemset/problem/1592/A

int compararEnteros(const void *a, const void *b)
{
    long long *ptrA = (long long *)a; //recuerda cambiar a lo que
    long long *ptrB = (long long *)b; //es, no siempre es int
    if ( *ptrA > *ptrB)
        return 1;
    else
        return 0;
}
//recordar que es al reves, severla
long long cant_armas(long long Armas[], long long H,int n )
{
    long long max_1=Armas[n-1]; //n-1 es el ultimo porque jaja vectores
    long long max_2=Armas[n-2];
    // H = acumulador que ire restando
    
    long long cociente = H/(max_1+max_2);
    long long resto = H%(max_1+max_2);
    long long total = cociente*2; //si
    
    if(resto > 0 ) total++; //Division no exacta
    if(resto > max_1 ) total++; // division supera a max_1
    
    return total;
}

int main()
{
    //primero el loop de i casos
    int t,i,n,j;
    long long H,dano_arma;
    
    printf("Cuantos casos veremos hoy? ");
    scanf("%i",&t);
    
    for(i=0;i<t;i++){
        //luego n == cantidad vector
    
        printf("Cuantas armas tenemos? ");
        scanf("%i",&n);
        
        //y H == vida inicial enemigo
        printf("Y cuanta es la vida del enemigo? ");
        scanf("%lld",&H);
        
        long long Armas[n];
        
        //hacer un loop con scanf e ir guardando valores de daño de armas
        for(j=0;j<n;j++){
            
            printf("Daño arma %i = ",j+1);
            scanf("%lld",&dano_arma);
            Armas[j]=dano_arma;
            
        }
        
        //ordenar de - a + el vecto
        
        qsort(Armas, n, sizeof(long long), compararEnteros);
        
        //ir revisando de + a -, ocupando los 2 maximos ver cuantas veces
        //cabe en la vida
        
        long long total=cant_armas(Armas,H,n);
        
        printf("se necesitaron %lld usos en total", total);
    }
    
    
    
    
    return 0;
}
