#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _BANDA{
    char nome[50];
    char genero[20];
    int num_membros;
    int ranking;
    struct _BANDA *next;
} BANDA;

typedef struct _LISTA_BANDA{
    BANDA *head;
    int tam;
} LISTA_BANDA;

void init(LISTA_BANDA *lista)
{
    lista->head = NULL;
    lista->tam = 0;
}

void inserir(LISTA_BANDA *lista, BANDA *elem)
{
    BANDA **torso, *novo;

    torso = &lista->head;
    novo = (BANDA *) malloc(sizeof(BANDA));

    strncpy(novo->nome, elem->nome, 50);
    strncpy(novo->genero, elem->genero, 20);
    novo->num_membros = elem->num_membros;
    novo->ranking = elem->ranking;

    while (1)
    {
        if ((!*torso))
        {
            novo->next = *torso;
            *torso = novo;
            return;
        }

        else if (novo->ranking < (*torso)->ranking)
        {
            novo->next = *torso;
            *torso = novo;
            return;
        }

        torso = &((*torso)->next);
    }
}

void display(LISTA_BANDA *lista)
{
    BANDA *banda;

    banda = lista->head;

    while (banda)
    {
        printf("Nome: %s\n", banda->nome);
        printf("Genero: %s\n", banda->genero);
        printf("Numero de integrantes: %d\n", banda->num_membros);
        printf("Ranking: %d\n\n", banda->ranking);

        banda = banda->next;
    }
}

int main(void)
{
    LISTA_BANDA *lista;
    BANDA nova_banda;
    int op = -1;

    lista = (LISTA_BANDA *) malloc(sizeof(LISTA_BANDA));

    init(lista);

    while (op){
        printf("Digite uma opcao: ");
        scanf("%d", &op);
        setbuf(stdin, NULL);
        switch (op)
        {
            case 1:
                printf("Nome da Banda: ");
                scanf("%[^\n]", nova_banda.nome);
                setbuf(stdin, NULL);

                printf("Genero: ");
                scanf("%[^\n]", nova_banda.genero);
                setbuf(stdin, NULL);

                printf("Numero de integrantes: ");
                scanf("%d", &nova_banda.num_membros);
                setbuf(stdin, NULL);

                printf("Ranking: ");
                scanf("%d", &nova_banda.ranking);
                setbuf(stdin, NULL);

                inserir(lista, &nova_banda);
                putchar('\n');
                break;
            case 2: 
                display(lista);
                break;
        }
    }
    free(lista);
    return 0;
}