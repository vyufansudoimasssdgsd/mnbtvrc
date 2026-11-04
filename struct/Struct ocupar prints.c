#include <stdio.h>

typedef struct
{
    char titulo[31];
    int paginas;
    float precio;
} tipoLibro;

int main()
{
    tipoLibro xlr8 = {"Las Cronicas de nada",121,12990.0};
    
    printf("El libro que tenemos es %s , tiene %i paginas y cuesta %.2f", xlr8.titulo , xlr8.paginas, xlr8.precio);
    
    
    
    return 0;
}
