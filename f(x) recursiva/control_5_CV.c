/**
 * ICD 1342
 * @brief Control 5: Recursividad
 * @date  2026-09-23
 *
 */

#include <stdio.h>
#include <math.h>  /* Necesaria por la funcion fabsf(), que calcula el valor absoluto para datos de tipo flotante */

#define NUM_PARTIDOS 10
#define VENTANA      3
#define UMBRAL       2.5f

//pasar recursiva
// distancia vector, i, ventana K
//float suma = sumar(data, i, ventana);

/*float sumar(float data[], int inicio, int ventana) {
    float resultado = 0.0;
    for (int i = 0; i < ventana; i++) {
        resultado += data[inicio + i];
    }
    return resultado;
}
*/

//Ocupar == nombres e == K para que no hayam problemas 

float sumar(float data[], int inicio, int ventana, int i ){ //AGREGUE I como ventana + i
	//base ir recorriendo vector e ir + 
	//limite inicio == ventana
	
	if(inicio == i ) return data[i]; 
	
	return 0,0 + data[i] + sumar(data, inicio, ventana, i -1);
	
	
}


//calcular_media_movil(distancia, media_movil, NUM_PARTIDOS, VENTANA);


/*

void calcular_media_movil(float data[], float media_movil[], int total_partidos, int ventana) 
{
    /* ventana total para la cual se puede calcular la media móvil */
    
    // al final solamente estoy ocupando 8 en todos los escenarios
    
    /*int ventana_total = total_partidos - ventana + 1;
    
    //aca lo de simepre, ocupar indice como K e ir sumando al ladito, en limite
    //al cargar toda la pila dividir y entregar
    
    for (int i = 0; i < ventana_total; i++) {
    	//Aca sumar desde i hasta i+ventana
        float suma = sumar(data, i, ventana, ventana + i ); //ARGEGAR I EN SUMAR
        media_movil[i] = suma / ventana;
    }
    
    //
}
    calcular_media_movil(distancia, media_movil,ventana_total,j );
*/

void calcular_media_movil(float data[], float media_movil[], int ventana_total, int i)
{
	float suma= sumar(data, i, VENTANA, VENTANA + i ) / VENTANA;
	media_movil[i] = sumar(data, i, VENTANA, VENTANA + i ) / VENTANA;
	if(i< ventana_total) return calcular_media_movil( data,  media_movil,  ventana_total, i+1);
	
}


//    detectar_anomalias  (distancia, media_movil, anomalias, NUM_PARTIDOS, VENTANA, UMBRAL);
//FALTO PASAR A ITERATIVO DETECTAR ANOMALIAS 
void detectar_anomalias(float data[], float media_movil[], int anomalias[], int total_partidos, int ventana, float umbral) 
{
	int i;
    for ( i = 0; i < (total_partidos - ventana + 1); i++) 
    {
        int   num_partido = i + ventana - 1;
        float diferencia  = fabsf(data[num_partido] - media_movil[i]);

        anomalias[num_partido] = 0; // carga de trabajo normal
        if (diferencia >= umbral) {
            anomalias[num_partido] = 1; // anomalia detectada
        } 
    }
    //poner 0 si no pasa nada,  1 si se detecta anomalia, es un vector que se va modificando
    //se modifica si en ese momento tuvo anomalia o no con la ventana de 3 dias
}


int main(void) 
{
    float distancia[NUM_PARTIDOS] = {
        10.5, 10.8, 10.2, 14.5, 10.1, 10.4, 10.0, 6.0, 10.3, 10.6  // aca datos 10 partidos
    };

    float media_movil[NUM_PARTIDOS] = {0};
    int   anomalias[NUM_PARTIDOS]   = {0};

	//distancia == VEctor
	
	int ventana_total = NUM_PARTIDOS - VENTANA + 1;
	int j;
	j=0;
    calcular_media_movil(distancia, media_movil,ventana_total, j);
    detectar_anomalias  (distancia, media_movil, anomalias, NUM_PARTIDOS, VENTANA, UMBRAL);

    // resultados
    printf("=====================================================\n");
    printf("### SOCCER ANALYTICS: Analisis de carga de trabajo   \n");
    printf("=====================================================\n\n");
    printf("Partido | Distancia (km) | Media (3 partidos) | Estado\n");
    printf("--------|----------------|--------------------|-------\n");
	int i;
	
    for ( i = 0; i <= NUM_PARTIDOS - VENTANA; i++) {
        int num_partido = i + VENTANA;
        
        printf("   %2d   |      %5.1f     |        %5.1f km    | %s\n", 
               num_partido, 
               distancia[num_partido - 1], 
               media_movil[i], 
               anomalias[num_partido - 1] ? "ALERTA: Revisar carga de trabajo" : "Normal");
    }

    return 0;
}
