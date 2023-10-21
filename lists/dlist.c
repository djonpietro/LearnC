//
// Created by joao on 26/09/23.
//

#include <stdlib.h>
#include "dlist.h"

Dlist * init_dlist(void (*destroy)(void*data)) {
    Dlist *dlist = (Dlist *) malloc(sizeof(Dlist));

    if (!dlist)
        exit(1);

    dlist->size = 0;
    dlist->destroy = destroy;
    DlistElem * head = (DlistElem *) malloc(sizeof(DlistElem));

    if (head == NULL)
        exit(1);

    head->next = head->prev = head;
    dlist->head = head;
    return dlist;
}

void dlist_insert_next(Dlist * dlist, DlistElem *prev, void *data) {
    DlistElem * new = (DlistElem*) malloc(sizeof(DlistElem));

    if (new == NULL) exit(1);

    new->data = data;

    new->next = prev->next;
    new->next->prev = new;
    new->prev = prev;

    dlist->size++;
}

int dlist_remove_next(Dlist * dlist, DlistElem *prev) {
    DlistElem * old;
    void * data;

    if (prev->next == dlist->head)
        return -1;

    old = prev->next;
    prev->next = old->next;
    old->next->prev = prev;
    data = old->data;

    if (dlist->destroy)
        dlist->destroy (data);
    free(old);
    dlist->size--;
    return 1;
}

void dlist_destroy(Dlist * dlist) {
    register int i;

    for (i = 0; i < dlist->size; i++)
        dlist_remove_next(dlist, dlist->head);
    free(dlist->head);
    free(dlist);
}

void * dlist_sequential_search(Dlist * dlist, void * key, int (*compare)(void*a, void*b)){
    DlistElem * pt = dlist->head->next;
    while (pt != dlist->head){
        if (!compare(pt->data, key))
            break;
        else
            pt = pt->next;
    }
    return pt;
}