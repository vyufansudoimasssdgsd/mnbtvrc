#include <stdio.h>
#include <math.h>

int main ()


{
    //definir 

    double x1;    // ocupa %f
    double x2;
    double y1;
    double y2;
    double distancia;
    
    int elogios;
    int corona; //1 si 0 no
    int tramposo; 
    
    corona = 0;
    tramposo =0;

    //entrada

    scanf("%lf",&x1);
    scanf("%lf",&y1);
    scanf("%lf",&x2);
    scanf("%lf",&y2);

    //procesar

    distancia = pow( (((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1))) , (1.0/2.0) );

    if (x1>x2 && y1>y2)
    {
        tramposo = 1;
    }

    if (!(tramposo))
    {
        if (distancia == 0)
            {
                elogios=500;
                corona =1;
            }
        else if (distancia <= 9)
            {
                elogios=500;
            }
        else if (distancia <=29)
            {
                elogios=400;
            }
        else if (distancia <=39)
            {
                elogios=300;
            }
        else if (distancia <=49)
            {
                elogios=200;
            }
        else if (distancia >= 50)
            {
                elogios=100;
            }
    }
    else if (tramposo)
    {
        printf("Eres un hacker, NO puedes estar mas alla de la meta.");
    }
    
    distancia=trunc(distancia);
    
    if (!tramposo)
    {
        if (!corona)
        {
            printf("No has llegado a la meta, te faltaron %.0f metro(s), tu premio es %i elogios",distancia,elogios);
        }
        else if (corona)
        {
            printf("Ganaste! Tu premio es la corona dorada y 500 elogios");
        }
    }
    return 0;
    
    //salida



}
