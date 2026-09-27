#include <stdio.h>
#include <stdlib.h>

//https://codeforces.com/problemset/problem/141/A

void juntar_nombres(char name_1[], char name_2[], char names_1_2[], int size_1, int size_2)
{
    int i,k; // k para los 2 for
    k=0;
    for(i=0;i<size_1;i++){
        names_1_2[k]=name_1[i];
        printf("%c",names_1_2[k]);
        k++;
    }
    for(i=0;i<=size_2;i++){ //para copiar el '\0'
        names_1_2[k]=name_2[i];
        printf("%c",names_1_2[k]);
        k++;
    }
    printf("\n");
}

int compararChar(const void *a, const void *b)
{
    char *ptrA =(char *)a;
    char *ptrB =(char *)b;
    
    if( *ptrA > *ptrB)
        return 1;
    else if (*ptrA < *ptrB)
        return -1;
    else
        return 0;
}

int comparar_palabras(char names_1_2[], char pile_letters[], int size_both, int size_3 )
{
    if(size_3 != size_both) return 0 ; //si no son del mismo tamaño, no pueden ser iguales
    //hacer for donde se comparen ambos y con if y no iif 
    int i;
    for(i=0;i<size_3;i++){
        if(names_1_2[i] != pile_letters[i])return 0;
    }
    return 1;
}

int main()
{
    int size_1,size_2,size_3;
    // ingresar los 2 strgs de nombres
    printf("----------------------------------\n");
    printf("INgrese el tamaño del str 1 ");
    scanf("%i",&size_1);
    
    char name_1[size_1+1]; // para el \0, pero solo en el vector
    
    printf("Ingrese el nombre 1 ");
    scanf("%s",name_1);
    
    printf("----------------------------------\n");
    printf("INgrese el tamaño del str 2 ");
    scanf("%i",&size_2);
    
    char name_2[size_2+1];
    
    printf("Ingrese el nombre 2 ");
    scanf("%s",name_2);
    printf("----------------------------------\n");
    
    printf("INgrese el tamaño del str 3 ");
    scanf("%i",&size_3);
    
    char pile_letters[size_3+1];
    
    // ingresar stg de pila de letras,tamaño antes y luego strg
    printf("Ingrese la pila de letras ");
    scanf("%s",pile_letters);
    printf("----------------------------------\n");
    
    // juntar 2 nombres en 1 solo strgs, eso f(x) void pasando 3 vectores
    char names_1_2[size_2+size_1+1];
    
    juntar_nombres(name_1,name_2,names_1_2,size_1,size_2);
    
    //ordenar pila y nombres con qsort modificado segun Chatgpt
    qsort(names_1_2,size_2+size_1,sizeof(char),compararChar);
    qsort(pile_letters,size_3,sizeof(char),compararChar);
    
    //comparar con un for si son exactamente iguales, ocupar una f(x) int con return 0/1
    
    int flag=comparar_palabras(names_1_2, pile_letters, size_1+size_2, size_3);
    
    if(flag) printf("YES");
    else printf("NO");
    
    return 0;
}
