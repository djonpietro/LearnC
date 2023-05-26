#include <stdio.h>
#include <math.h>

typedef struct _PONTO{
    float x, y;
} PONTO;

int main(void){
    PONTO p1, p2;
    float distancia;

    printf("Digite as coordanadas do ponto 1\n");
    printf("X: ");
    scanf("%f", &p1.x);
    printf("Y: ");
    scanf("%f", &p1.y);

    printf("Digite as coordanadas do ponto 2\n");
    printf("X: ");
    scanf("%f", &p2.x);
    printf("Y: ");
    scanf("%f", &p2.y);

    distancia = sqrt(pow((p1.y - p2.y), 2) + pow((p1.x - p2.x), 2));

    printf("A distância entre p1(%.2f, %.2f) e p2(%.2f, %.2f) é %.2f\n", p1.x, p1.y, p2.x, p2.y, distancia);

    return 0;
}