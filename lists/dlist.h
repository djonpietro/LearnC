//
// Created by joao on 26/09/23.
//

#ifndef DLIST_H
#define DLIST_H

typedef struct DlistElem {
    void *data;
    struct DlistElem *next;
    struct DlistElem *prev;
} DlistElem;

typedef struct Dlist {
    DlistElem *head;
    int size;
    void (*destroy)(void *data);
} Dlist;

Dlist * init_dlist(void (*destroy)(void*data));
void dlist_destroy(Dlist * dlist);
void dlist_insert_next(Dlist * dlist, DlistElem *prev, void *data);
int dlist_remove_next(Dlist * dlist, DlistElem *prev);
void * dlist_sequential_search(Dlist * dlist, void * key, int (*compare)(void*a, void*b));
#endif //DLIST_H
