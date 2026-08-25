#include <stdio.h>

int main()
{
    int index,n_1,n_2,result;
    
    do
    {
        scanf("%i",&index);
        
        if (index != 4)
        {
            if (index == 1)
            {
                printf("Ingrese 2 numeros para sumar\n");
                scanf("%i",&n_1);
                scanf("%i",&n_2);
                result = n_1 + n_2;
                printf("Resultado 1 = %i\n",result);
            }
            else if (index ==2)
            {
                printf("Ingrese 2 numeros para restar\n");
                scanf("%i",&n_1);
                scanf("%i",&n_2);
                result = n_1 - n_2;
                printf("Resultado 2 = %i\n",result);
            }
            else if (index == 3)
            {
                printf("Ingrese 2 numeros para multiplicar\n");
                scanf("%i",&n_1);
                scanf("%i",&n_2);
                result = n_1 * n_2;
                printf("Resultado 3 = %i\n",result);
            }
            else if (index != 4)
            {
                printf("Opcion invalida\n");
            }
        }
        
    }
    while (index != 4);
    printf("FIN DE LA EJECUCIÓN");
    
    
    
}