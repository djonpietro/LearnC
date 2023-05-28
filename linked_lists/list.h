#ifndef LIST_H
#define LIST_H

typedef struct _ListElem{
    void *data;
    struct _ListElem *next;
} ListElem;

typedef struct _List{
    ListElem *head;
    ListElem *tail;
    void (*destroy)(void *data);
    int size;
} List;

void list_init(List *list, void (*destroy) (void *data));
void list_insert_next(List *list, ListElem* previous_elem, void *data);
int list_remove_next(List* list, ListElem* previous_elem);
void list_destroy(List* list);

#endif 