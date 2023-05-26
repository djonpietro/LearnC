#include <stdio.h>
#include <stdlib.h>

typedef struct _JOAGADOR{
    char time[40];
    char nome[20];
    int ranking;
    int idade;
    struct _JOGADOR *next;
} JOGADOR;

void inserir(JOGADOR **head, JOGADOR *elem);
int remover(JOGADOR **head, JOGADOR *elem);
void display(JOGADOR **head);

int main(void)
{
    JOGADOR *head, *j1, *j2;
    int register i;

    head = NULL;
    j1 = (JOGADOR *) malloc(sizeof(JOGADOR));
    j2 = (JOGADOR *) malloc(sizeof(JOGADOR));

    printf("Escreva o nome do jogador: ");
    gets(j1->nome);
    printf("Escreva o time do jogador: ");
    gets(j1->time);
    printf("Escreva a idade do jogador: ");
    scanf("%d", &(j1->idade));
    printf("Escreva o ranking do jogador: ");
    scanf("%d", &(j1->ranking));

    inserir(&head, j1);

    display(&head);

    setbuf(stdin, NULL);
    putchar('\n');

    printf("Escreva o nome do jogador: ");
    gets(j2->nome);
    printf("Escreva o time do jogador: ");
    gets(j2->time);
    printf("Escreva a idade do jogador: ");
    scanf("%d", &(j2->idade));
    printf("Escreva o ranking do jogador: ");
    scanf("%d", &(j2->ranking));
    inserir(&head, j2);

    display(&head);

    printf("Removendo j2\n");
    remover(&head, j2);
    display(&head);

    free(j1);
    return 0;
}

void inserir(JOGADOR **head, JOGADOR *elem)
{
    JOGADOR *p1, *p2;
    p1 = NULL;
    p2 = *head;

    if (!(*head)){
        *head = elem;
        elem->next = NULL;
        return;
    }

    while (1){

        /*inserção na cabeça*/
        if (p2 == *head && elem->ranking < p2->ranking){
            elem->next = p2;
            *head = elem;
            return;
        }

        /*inrseção no fim*/
        if (p2->next==NULL && elem->ranking > p2->ranking){
            elem->next = NULL;
            p2->next = elem;
            return;
        }

        /*inserção no meio*/
        if (elem->ranking < p2->ranking){
            elem->next = p2;
            p1->next = elem;
            return;
        }
        p1 = p2;
        p2 = p2->next;
    }
}

int remover(JOGADOR **head, JOGADOR *elem){
    JOGADOR *p1, *p2;

    p1 = NULL;
    p2 = *head;

    while(p2){
        if (elem==*head){
            *head = elem->next;
            free(elem);
            return 0;
        }

        if (elem==p2){
            p1->next = elem->next;
            free(elem);
            return 0;
        }
        p1 = p2;
        p2 = p2->next;
    }
    return -1;
}

void display(JOGADOR **head){
    JOGADOR *p = *head;

    while(p){
        putchar('\n');
        printf("Nome: %s\n", p->nome);
        printf("Time: %s\n", p->time);
        printf("Idade: %d\n", p->idade);
        printf("Ranking: %d\n", p->ranking);
        putchar('\n');
        p = p->next;
    }
}