#include <stdio.h>
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
    CIRCUNFERENCIA C1, C2;
    float distancia;

    printf("Digite o raio da circunferencia 1: ");
    scanf("%f", &C1.raio);
    printf("Digite a localização do centro\n");
    printf("X: ");
    scanf("%f", &C1.centro.x);
    printf("Y: ");
    scanf("%f", &C1.centro.y);

    putchar('\n');

    printf("Digite o raio da circunferencia 2: ");
    scanf("%f", &C2.raio);
    printf("Digite a localização do centro\n");
    printf("X: ");
    scanf("%f", &C2.centro.x);
    printf("Y: ");
    scanf("%f", &C2.centro.y);

    distancia = sqrt(pow((C1.centro.y - C2.centro.y), 2) + pow((C1.centro.x - C2.centro.x), 2));

    if (distancia < C1.raio + C2.raio){
        if (distancia + C1.raio <= C2.raio || distancia + C2.raio <= C1.raio){
            if (C1.raio == C2.raio && distancia == 0)
                printf("As circunferências são iguais\n");
            else if (C1.raio > C2.raio)
                printf("A circunferência C2 é interna a C1\n");
            else
                printf("A circunferência C1 é interna a C2\n");
        }
        else
            printf("As circunferências são secantes.\n");
    }
    
    if (distancia == C1.raio + C2.raio)
        printf("As circunferências são tangentes\n");

    if(distancia > C1.raio + C2.raio)
        printf("As cirncunferências são externas\n");
    
    return 0;
}