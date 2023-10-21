#ifndef LISTS_H
#define LISTS_H

typedef struct ListElem {
    void *data;
    struct ListElem *next;
} ListElem;

typedef struct List{
    ListElem *head;
    ListElem *tail;
    unsigned size;
    void (*destroy)(void *data);
} List;

List* list_init(void (*destroy) (void *pt));

void list_insert_next(List *l, ListElem *previous, void *data);

int list_remove_next(List *l, ListElem *previous);

void list_destroy(List *l);

ListElem* list_sequential_search(List *l, void* key, int compare(void* a, void*b));

#endif //LISTS_H
