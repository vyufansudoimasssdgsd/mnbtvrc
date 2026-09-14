#include <stdio.h>

int sumar(int a,int b)
{
    if (b==0){
        printf("%i %i \n",a,b);
        printf("FIN");
        return a;
    }
    else{
        printf("%i %i \n",a,b);
        sumar((a+1),(b-1)); //no es necesario poner return para que sea recursiva
    }
    
}

int main()
{
    int a,b;
    a=6;
    b=4;
    
    sumar(a,b);

    return 0;
}
