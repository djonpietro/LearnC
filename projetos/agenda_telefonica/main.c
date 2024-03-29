#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../linked_lists/list.h"

#define TAM_NOME 80
#define TAM_TELNUM 10

typedef struct _Data{
    int dia, mes, ano;
} Data;

typedef struct _Contato{
    char nome[TAM_NOME];
    char telefone[TAM_TELNUM];
    Data niver;
} Contato;

ListElem* pesquisar_contato_anterior(List* lista, char* nome);

List* iniciar(void);

void terminar(List* lista);

void inserirContato(List* lista), removerContato(List* lista);

void infoContato(List* lista), listarContatos(List* lista);

void aniversariantes(List* lista), contato_por_letra_inicial(List* lista);

void lerString(char* str);

Contato* alocaContato(Contato* contato);

int main(void)
{
    List *lista;
    int op = 0;
    char nome_buscado[TAM_NOME];

    lista = iniciar();

    printf("--------------Agenda Telefônica----------\n");

    while (op != 7){
        printf("[1] - Inserir Contato\n[2] - Remover Contato\n[3] - Buscar um Contato\n");
        printf("[4] - Listar todos os contatos\n[5] - Listar contatos por inicial\n[6] - Listar aniversariantes\n");
        printf("[7] - Encerrar\n\n");

        printf("Digite uma opção: ");
        scanf("%d", &op);
        setbuf(stdin, NULL);
        putchar('\n');

        switch (op){
            case 1:
                inserirContato(lista);
                break;
            
            case 2:
                removerContato(lista);
                break;

            case 3:
                infoContato(lista);
                break;

            case 4:
                listarContatos(lista);
                break;

            /*case 5:
                contato_por_letra_inicial(lista);
                break;

            case 6:
                aniversariantes(lista);
                break;*/

            case 7:
                terminar(lista);
                break; 
        }
        putchar('\n');
    }
    list_destroy(lista);
    free(lista);
    return 0;
}

List* iniciar(void)
{
    List *lista;
    FILE *contatos_aqv;
    Contato contato_do_arquivo;

    /*---------------------Inicialização da lista -------------------------*/

    lista = (List*) malloc(sizeof(List));
    if (!lista){
        printf("Erro de alocação para a lista de contatos\n");
        exit(1);
    }

    list_init(lista, free);

    /*---------Inserção dos registro oriundos do arquivo de disco--------*/
    if(!(contatos_aqv = fopen("contatos.txt", "a+"))){
        printf("Erro na abertura do arquivo de contatos para leitura\n");
        exit(1);
    }

    /*Para cada chamada de fsacnf, o programa deve fazer 5 atribuições.
    Cada linha do arquivo, possui 5 valores separados por vírgula, e o conjunto
    desses valores compõe um registro de Contato*/
    while (fscanf(contatos_aqv, "%[^,],%[^,],%d,%d,%d\n",
            contato_do_arquivo.nome,
            contato_do_arquivo.telefone,
            &contato_do_arquivo.niver.dia,
            &contato_do_arquivo.niver.mes,
            &contato_do_arquivo.niver.ano) == 5) 
    {
        list_insert_next(lista, NULL, alocaContato(&contato_do_arquivo));        
    }

    return lista;
}

void terminar(List* lista)
{
    FILE *contatos_aqv;
    ListElem *pt_walker;
    Contato* registro_gravado;

    if (!(contatos_aqv = fopen("contatos.txt", "w"))){
        printf("Erro na abertura do arquivo de contatos para gravação\n");
        exit(1);
    }

    pt_walker = lista->head;
    
    /*---------Salvando os registros no arquivo texto de disco----------*/
    while (pt_walker){
        registro_gravado = (Contato*) pt_walker->data;
        fprintf(contatos_aqv, "%s,%s,%d,%d,%d\n", 
        registro_gravado->nome,
        registro_gravado->telefone,
        registro_gravado->niver.dia,
        registro_gravado->niver.mes,
        registro_gravado->niver.ano);
        
        pt_walker = pt_walker->next;
    }

    fclose(contatos_aqv);
    list_destroy(lista);
}

Contato* alocaContato(Contato* contato)
{
    Contato *pt_contato_alocado;

    pt_contato_alocado = (Contato*) malloc(sizeof(Contato));
    if(!pt_contato_alocado){
        printf("Erro de alocação para novo registro de dados\n");
        exit(1);
    }

    /*---Preenchimento dos campos da estrutura alocada por pt_contato_alocado---*/
    strncpy(pt_contato_alocado->nome, contato->nome, TAM_NOME);
    strncpy(pt_contato_alocado->telefone, contato->telefone, TAM_TELNUM );
    pt_contato_alocado->niver.dia = contato->niver.dia;
    pt_contato_alocado->niver.mes = contato->niver.mes;
    pt_contato_alocado->niver.ano = contato->niver.ano;

    return pt_contato_alocado;
}

void inserirContato(List* lista){
    Contato novo_contato;
    ListElem* pt_walker;

    /*------------Preenchimento dos campos pelo usuário---------*/
    printf("Nome: ");
    lerString(novo_contato.nome);
    printf("Número de Telefone: ");
    lerString(novo_contato.telefone);
    printf("Data de aniversário [d/m/aaaa]: ");
    scanf("%d/%d/%d", &novo_contato.niver.dia, &novo_contato.niver.mes, &novo_contato.niver.ano);

    pt_walker = lista->head;
    
    /*inserção na lista vazia*/
    if (lista->head == NULL){
        list_insert_next(lista, NULL, alocaContato(&novo_contato));
        return;
    }

    /*inserção na cabeça da lista*/
    else if (strcmp(novo_contato.nome, ((Contato*) pt_walker->data)->nome) < 0){
        list_insert_next(lista, NULL, alocaContato(&novo_contato));
        return;
    }

    /*inserção no meio da lista*/
    while (pt_walker->next){
        if (strcmp(novo_contato.nome, ((Contato*) pt_walker->next->data)->nome) < 0){
            list_insert_next(lista, pt_walker, alocaContato(&novo_contato));
            return;
        }
    }

    /*inserção no final da lista da lista*/
    list_insert_next(lista, lista->tail, alocaContato(&novo_contato));
}

void lerString(char* str)
{
    scanf("%[^\n]", str);
    setbuf(stdin, NULL);
}

void removerContato(List* lista)
{
    char nome_a_ser_removido[TAM_NOME];
    ListElem* elemento_anterior_ao_removido;

    if (!lista->size){
        printf("A lista está vazia\n");
        return;
    }

    printf("Digite o nome do contato a ser removido: ");
    lerString(nome_a_ser_removido);

    elemento_anterior_ao_removido = pesquisar_contato_anterior(lista, nome_a_ser_removido);

    if (!list_remove_next(lista, elemento_anterior_ao_removido))
        printf("O nome não consta na lista\n");
    else
        printf("O nome foi removido com sucesso\n");
}

ListElem* pesquisar_contato_anterior(List* lista, char* nome)
{
    ListElem* pt_walker;
    
    pt_walker = lista->head;

    /*verifica se o elemento procurado é o head da lista*/
    if (!strcmp(nome, ((Contato*) pt_walker->data)->nome))
        return NULL;

    /*Verifica qual é o elemento que antecede ao procurado e quando
    o acha, retorna um ponteiro para ele*/
    while (pt_walker->next){
        if (!strcmp(nome, ((Contato*) pt_walker->next->data)->nome))
            return pt_walker;
        
        pt_walker = pt_walker->next;
    }
    
    /*Se o nome não existe na lista, então o tail da lista é retornado*/
    return lista->tail;
}

void infoContato(List* lista)
{
    char nome_buscado[TAM_NOME];
    ListElem* elemento_anterior_ao_buscado;
    Contato* registro;

    if (!lista->size){
        printf("A lista está vazia\n");
        return;
    }

    printf("Nome a ser buscado: ");
    lerString(nome_buscado);
    elemento_anterior_ao_buscado = pesquisar_contato_anterior(lista, nome_buscado);

    if (elemento_anterior_ao_buscado == lista->tail){
        printf("O nome não consta na lista\n");
        return;
    }

    if (elemento_anterior_ao_buscado == NULL)
        registro = (Contato *) lista->head->data;
    else
        registro = (Contato*) elemento_anterior_ao_buscado->next->data;

    printf("%s\n", registro->nome);
    printf("%s\n", registro->telefone);
    printf("Aniversário: %d/%d/%d\n", registro->niver.dia, registro->niver.mes, registro->niver.ano);
}

void listarContatos(List* lista){
    ListElem* pt_walker;
    Contato* registro;

    pt_walker = lista->head;
    while (pt_walker){
        registro = (Contato*) pt_walker->data;
        printf("%s\n", registro->nome);
        printf("%s\n", registro->telefone);
        printf("%d/%d/%d\n", registro->niver.dia, registro->niver.mes, registro->niver.ano);
        putchar('\n');
        pt_walker = pt_walker->next;
    }
}