#include <stdio.h>

int main()

{
    //definir variables
    float m1;
    float m2;
    float m3;
    float m4;
    float np;
    float ne;
    float nf;
    
    // 0=falso 1 =verdadero


    // entrada datos

    scanf("%f", &m1);
    scanf("%f", &m2);
    scanf("%f", &m3);
    scanf("%f", &m4);

    //procesar

    np=(m1*0.15)+(m2*0.2)+(m3*0.3)+(m4*0.35);

    if ((np >= 5.5) && (m1>=4.0) && (m2>= 4.0) && (m3>=4.0) && (m4>=4.0))
        {
            nf=np;
            printf("Eximido : %.2f",nf);
        }

    else
        {
            if (np <= 3.0)
            {
                nf=np;
                printf("Reprobado : %.2f", nf);
            }
            else
            {
                scanf("%f", &ne);
                nf = (np*0.6) + (ne*0.4);
                if (nf >=4.0)
                    {
                        printf("Aprobado : %.2f ", nf);
                    }
                else
                    {
                        printf("Reprobado : %.2f ",nf);
                    }
            }

        }

    //salida






}