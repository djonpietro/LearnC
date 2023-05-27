DESCRIÇÃO DAS FUNÇÕES PARA MANIPULAÇÃO DE LISTAS ENCADEADAS


void list_init(List *list)
    módulo para iniciar a lista encadeada, inicializando seu ponteiros com null
    e atribuindo 0 ao seu tamanho.

void list_insert_next(List *list, Item *item, const void *data) 
    módulo para inserir um elemento na lista. Deve ser passado um ponteiro para o registro da lista (List *list),
    um ponteiro para o item anterior ao que será alocado (Item *item), e um ponteiro para
    o registro de dados do elemento a ser adicionado. Se o parâmetro item for null, então
    a inserção será na cabeça. O ponteiro quanto a alocação de data e o seu gerenciamento de memória, seja dinâmica ou estática, está por conta
    da implementação feita pelo usuário da função.

void list_rem_next(List *list, Item *item)
    módulo para remover um elemento da lista encadeada. Nessa primeira versão, considera-se
    que todas as alocações foram feitas usando-se malloc, de forma que para liberar o endereço
    de memória reservado será usada a função free. Deve ser passado um ponteiro para o registro
    da lista, um ponteiro para o elemento anterior ao que vai ser removido. Se o parâmetro item for null
    então a remoção é na cabeça

void list_destroy(List *list)
    módulo para destruir toda a lista encadeada. Considera-se aqui, por ora, que todos os
    elementos da lista e os seus dados foram alocados usando-se malloc, de forma que para
    liberar os endereços reservados para esses dados seja usado free.


