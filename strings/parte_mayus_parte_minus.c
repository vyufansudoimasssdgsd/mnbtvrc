#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    //definir el strg
    
    char *nombre_completo = (char *) malloc(sizeof(char) * 30);
    
    //entrada de nombre
    
    scanf(" %29[^\n]",nombre_completo);
    
    //hacer un loop hasta que detecte la 1era letra
    int flag_inicia_palabra=1;
    for(int i=0;nombre_completo[i] != '\0';i++){
        if( nombre_completo[i] == ' '){
            flag_inicia_palabra=1;
        }
        else{
            if(flag_inicia_palabra){
                nombre_completo[i]= toupper(nombre_completo[i]);
                flag_inicia_palabra=0;
            }
            else{
                nombre_completo[i] = tolower(nombre_completo[i]);
            }
        }
        
    }
    
    
    printf("%s",nombre_completo);
    
    free(nombre_completo);
    
    return 0;
}
