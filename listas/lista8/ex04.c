#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _PONTO{
    float x, y;
} PONTO;

typedef struct _CIRCUNFERENCIA{
    float raio;
    PONTO centro;
} CIRCUNFERENCIA;

int main(void)
{
    CIRCUNFERENCIA C1;
    PONTO p;
    float distancia;

    printf("Digite o raio da circunferencia: ");
    scanf("%f", &C1.raio);
    printf("Digite a localização do centro\n");
    printf("X: ");
    scanf("%f", &C1.centro.x);
    printf("Y: ");
    scanf("%f", &C1.centro.y);

    printf("Digite as coordanadas do ponto\n");
    printf("X: ");
    scanf("%f", &p.x);
    printf("Y: ");
    scanf("%f", &p.y);

    distancia = sqrt(pow((C1.centro.y - p.y), 2) + pow((C1.centro.x - p.x), 2));

    if (distancia <= C1.raio) 
        printf("O ponto P(%.2f, %.2f) está dentro da circunferencia.\n", p.x, p.y);
    else
        printf("O ponto P(%.2f, %.2f) não está dentro da circunferência.\n", p.x, p.y);
    return 0;
}