#include <stdio.h>

int encontrar_subcadena_mayor(int cadena_sushi[], int n, int es_reves)
{
    //https://codeforces.com/problemset/problem/1138/A
    // izq-der == 0, der_izq == 1
    //ir desde izq a der la lista, ver la primera aparicion de 2
    int i,contador_1,contador_2,flag_1,flag_2,max;
    contador_1=0;
    contador_2=0;
    flag_1=0;
    flag_2=0;
    max=0;
    for(i=0;i<n;i++){
        //al pillarlo, empezar con la v-cantidad de 2 seguidos
        //si pillo el 1er 2
        
        int idx;
        if (es_reves) {
            idx = n-1-i;
        } 
        else {
            idx = i;
        }
        
        if(cadena_sushi[idx] == 2 && contador_2==0 && flag_2==0){
            contador_2++;
            flag_2=1; //empieza a ser true
        }
        
        //voy contatenando
        else if(flag_2){
            //se añade al concatenado
            if(cadena_sushi[idx] == 2){
                contador_2++;
            }
            //se para la cadena
            else if (cadena_sushi[idx] == 1){
                flag_2=0;
                contador_1++; //empieza a contar el 1
                flag_1=1;
            }
        }
        //si se terminaron los 2, empezar a contar los 1 seguidos b-cantidad
        
        else if(flag_1){//empieza a concatenar el 1
            
            if(cadena_sushi[idx]==1){
                contador_1++;
                
            }
            //para la cadena de 1
            
            if(cadena_sushi[idx] == 2){
                flag_1=0; //Resetean los flag
                flag_2=1;
                //al acabar los 1 ver si son b=v
                //sino, dar el más chico, para asi tener el 2do más grande
                //lo del 2do más grande tampoco se me ocurrio
                
                int m;
                if (contador_1 < contador_2) {
                    m = contador_1;
                }
                else {
                    m = contador_2;
                }
                if (max < m) {
                    max = m;
                }
                
                //resetean para sgte busqueda
                contador_1=0;
                contador_2=1; //como ya partio con el 2, poner ese 
               
            }
            
        }
    }
    
    //si es que nunca te topas con un 2 al final antes del return 
    //yo no hice esto, no se me ocurrio que si termina solo en 1 o 2, pasa eso
    if (flag_1) {
        int m;
        if (contador_1 < contador_2) {
            m = contador_1;
        }
        else {
            m = contador_2;
        }
        
        if (max < m) {
            max = m;
        }
    }
    
    return max; //Y RECUERDEN NIÑOS, PONGAN RETURN EN SUS F(X)
    
    
    
}

int main()
{
    int n,i,valor;
    printf("ingres la cantidad de piezas ");
    scanf("%i",&n);
    //que tan largo es el vector
    
    int cadena_sushi[n];
    
    for(i=0;i<n;i++){ //ingresan datos
        
        printf("ingresa la pieza %i ",i+1);
        scanf("%i",&valor); // puede ser 1 o 2
        cadena_sushi[i]=valor;
        
    }
    
    int max_1=encontrar_subcadena_mayor(cadena_sushi, n, 1);
    int max_2=encontrar_subcadena_mayor(cadena_sushi, n, 0);
    
    if(max_2>max_1)max_1=max_2;
    
    //si son ==, mostrar como maximo el b*2
    //ocupar max_1
    
    printf("La mayor subcadena de sushi es de largo %i",max_1*2);
    

    return 0;
}

