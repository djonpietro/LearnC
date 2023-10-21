#include "list.h"

#include <stdio.h>
#include <stdlib.h>

List* list_init(void (*destroy) (void* pt)){
    List *l = (List*) malloc(sizeof(List));
    if (l == NULL)
        exit(1);

    ListElem *head = (ListElem*) malloc(sizeof(ListElem));

    l->head = head =  l->tail = head;
    l->size = 0;
    l->destroy = destroy;
    return l;
}

ListElem* list_sequential_search(List *l, void* key, int compare(void* a, void*b)){
    ListElem *pt = l->head;

    while (pt->next != NULL)
        if (!compare(pt->next->data, key))
            return pt;
    return pt;
}

void list_insert_next(List *l, ListElem *previous, void* data) {
    ListElem *new_elem = (ListElem *) malloc(sizeof(ListElem));
    if (new_elem == NULL)
        exit(1);
    new_elem->data = data;

    new_elem->next = previous->next;
    previous->next = new_elem;

    if (new_elem->next == NULL)
        l->tail = new_elem;

    l->size++;
}

int list_remove_next(List *l, ListElem *previous){
    void *data;
    ListElem *old;

    if (previous->next == NULL)
        return -1;

    old = previous->next;
    data = old->data;
    previous->next = old->next;

    if (previous->next == NULL)
        l->tail = previous;

    if (l->destroy)
        l->destroy(data);

    free(old);
    l->size--;
    return 1;
}

void list_destroy(List *l){
    register int i;
    for (i = 0; i < l->size; i++)
        list_remove_next(l, l->head);
    free(l->head);
    free(l);
}