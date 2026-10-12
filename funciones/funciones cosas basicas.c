#include <stdio.h>

int llenar_notas (float notas[])
{
    int n;
    do {
        printf("Cantidad de alumnos (1-100): ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);

    for (int i = 0; i < n; i++) {
        do {
            printf("Nota alumno %d (1.0 - 7.0): ", i + 1);
            scanf("%f", &notas[i]);
        } while (notas[i] < 1.0 || notas[i] > 7.0);
    }
    
    return n;
    
}

float sacar_promedio(float notas[], int n)
{
    float suma=0;
    for (int i = 0; i < n; i++) {
        suma += notas[i];
    }
    float promedio = suma / n;
    return promedio;
}

float sacar_maximo(float notas[], int n)
{
    
    float maxima = notas[0];
    for (int i = 1; i < n; i++) {
        if (notas[i] > maxima) maxima = notas[i];
    }
    return maxima;
}

float sacar_minima(float notas[], int n)
{
    float minima = notas[0];
    for (int i = 1; i < n; i++) {
        if (notas[i] < minima) minima = notas[i];
    }
    return minima;
}

int calcular_aprobados(float notas[], int n)
{
    int aprobados=0;
    for (int i = 0; i < n; i++) {
        if (notas[i] >= 4.0) aprobados++;
    }
    return aprobados;
}

int calcular_reprobados(float notas[], int n)
{
    int reprobados=0;
    for (int i = 0; i < n; i++) {
        if (notas[i] < 4.0) reprobados++;
    }
    return reprobados;
}

int main() {
    int n;
    float notas[100];
    float promedio, maxima, minima;
    int aprobados, reprobados;

    n=llenar_notas(notas);
    
    promedio=sacar_promedio(notas,n);

    maxima = sacar_maximo(notas,n);
    
    minima = sacar_minima(notas,n);

    aprobados=calcular_aprobados(notas, n);
    
    reprobados=calcular_reprobados(notas, n);
    
    printf("\n--- Resultados ---\n");
    printf("Promedio: %.2f\n", promedio);
    printf("Nota maxima: %.1f\n", maxima);
    printf("Nota minima: %.1f\n", minima);
    printf("Aprobados: %d\n", aprobados);
    printf("Reprobados: %d\n", reprobados);

    return 0;
}