INTERFACE PARA LISTAS ENCADEADAS

typedef struct _ListElem{
    void *data;
    struct _ListElem *next;
}

typedef struct _List{
    Item *head;
    Item *tail;
    int size;
} List;

void list_init(List *list, void (*destroy)(void *data)) - inicializa os campos head e tail com NULL e size com 0. o segundo parâmetro define a função que cuidará da remoção dos registros de dados apontados pelo campo *data de cada elemento da lista quando a lista for destruida, de modo que, se esse parâmetro for dado como NULL, então nenhuma função de liberação de memória é utilizada. A motivação para isso é que existem muitas funções para alocar e liberar espaços na memória, variando a implementação de cada lista.

void list_insert_next(List *list, ListElem *previous_elem, void *data) - essa função insere um elemento na lista encadeada após o elemento apontado por *previous_elem. Caso esse último seja passado como NULL, então a inserção ocorrerá na cabeça. A função também copia o endereço apontado por *data ao campo *data do item que será adicionado. Alocação e gerenciamento de data fica por conta do usuário.

int list_remove_next(List *list, ListElem *previous_elem) - essa função remove o item que sucessede aquele apontado por *previou_elem. Se esse último for NULL, então a remoção ocorrerá na cabeça. O registro de dados do item é liberado pela função destroy especificada na inicialização da lista. A função retorna 0 caso a remoção não ocorra, o que acontece quando a lista está vazia ou *previou_elem é o tail da lista. Se a remoção for bem sucedida, a funçõ retorna diferente de 0.

void list_destroy(List *list) - destrói a lista encadeada, liberando todos os espaços alocados para os seus itens, empregando a função list_remove_next de modo iterativo para destruir a lista do início até fim. Os registros de dados apontados pelo campo *data de ca elemento é liberado pela função especificada em destroy.