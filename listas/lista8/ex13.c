#include <stdio.h>
#include <stdlib.h>

typedef struct _FRACAO{
    int numerador, denominador;
} FRACAO;

FRACAO adicao(FRACAO a, FRACAO b);
FRACAO substracao(FRACAO a, FRACAO b);
FRACAO multiplicao(FRACAO a, FRACAO b);
FRACAO divisao(FRACAO a, FRACAO b);

int main(void)
{
    FRACAO f1, f2, soma, diferenca, produto, razao;

    printf("Numerador I: ");
    scanf("%d", &f1.numerador);
    printf("Denominador I: ");
    scanf("%d", &f1.denominador);
    if (!f1.denominador){
        printf("Denominador não pode ser igual a zero.\n");
        exit(1);
    }

    printf("Numerador II: ");
    scanf("%d", &f2.numerador);
    printf("Denominador II: ");
    scanf("%d", &f2.denominador);
    if (!f2.denominador){
        printf("Denominador não pode ser igual a zero.\n");
        exit(1);
    }

    soma = adicao(f1, f2);
    diferenca = substracao(f1, f2);
    produto = multiplicao(f1, f2);
    razao = divisao(f1, f2);

    putchar('\n');
    printf("Soma: %d/%d\n", soma.numerador, soma.denominador);
    printf("Diferença: %d/%d\n", diferenca.numerador, diferenca.denominador);
    printf("Produto: %d/%d\n", produto.numerador, produto.denominador);
    printf("Razão: %d/%d\n", razao.numerador, razao.denominador);

    return 0;
}

FRACAO adicao(FRACAO a, FRACAO b)
{
    FRACAO soma;

    soma.numerador = a.numerador * b.denominador + b.numerador * a.denominador;
    soma.denominador = a.denominador * b.denominador;

    return soma;
}

FRACAO substracao(FRACAO a, FRACAO b)
{
    FRACAO diferenca;

    diferenca.numerador = a.numerador * b.denominador - b.numerador * a.denominador;
    diferenca.denominador = a.denominador * b.denominador;

    return diferenca;
}

FRACAO multiplicao(FRACAO a, FRACAO b)
{
    FRACAO produto;

    produto.numerador = a.numerador * b.numerador;
    produto.denominador = a.denominador * b.denominador;

    return produto;
}

FRACAO divisao(FRACAO a, FRACAO b)
{
    FRACAO razao;

    razao.numerador = a.numerador * b.denominador;
    razao.denominador = a.denominador * b.numerador;

    return razao;
}
