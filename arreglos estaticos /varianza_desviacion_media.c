#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define size 100

int main()
{
	int n,edad,i;
	float s_edad,media,s_des,des_est;
	int vect[size];
    
    //recuerda inicializar sumatorias
    s_edad=0;
    s_des=0;
    
	printf("numero ?\n");
	scanf("%i",&n);

	for (i=0 ; i<n ; i++)
	{
        printf("edad ?\n");
		scanf("%i",&edad);
		vect[i]=edad;
		s_edad+=edad;
		printf("edad es = %i\n",edad);
	}
    
    media=s_edad/n;
    printf("media es %f\n",media);
    
    for (i=0 ; i< n ; i++)
    {
        s_des+=((vect[i]-media)*(vect[i]-media));
        printf("suma de desviacion %f\n",s_des);
    }
    des_est=s_des/n;
    des_est=sqrt(des_est);
    
    printf("______RESULTADOS_____\n");
    printf("La media es de %f\n",media);
    printf("la desviacion estandar es %f\n",des_est);
    return 0;
}
