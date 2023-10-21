#include <stdlib.h>
#include "array.h"

void ** overflow(void ** v, int *size, int n_elem){
    register int i;

    int new_size = *size * 2;

    void **temp = (void **) malloc(sizeof(void)* new_size);
    if (!temp)
        exit(1);

    for (i = 0; i < n_elem; i++)
        temp[i] = v[i];

    *size = new_size;

    free(v);
    return temp;
}

Array * array_init(void (*destroy)(void *data)) {
    Array *a = (Array*) malloc(sizeof(Array));
    if (!a)
        exit(1);
    a->size = 10;
    a->n_elem = 0;
    a->v = (void **) malloc(sizeof(void)*10);
    if (!a->v)
        exit(1);
    a->destroy = destroy;
    return a;
}

int array_search(Array * a, void * key, int (*compare) (void*a,void*b)){
    void ** v = a->v;
    register int i;

    for (i = 0; i < a->n_elem; i++)
        if (!compare(key, v[i]))
            return i;
    return i; //i == a->n_elem
}

void array_insert(Array * a, void * data, int pos) {
    register int i;
    if (a->size == a->n_elem)
        a->v = overflow(a->v, &a->size, a->n_elem);
    for (i = pos; i < a->n_elem; i++)
        a->v[i+1] = a->v[i];
    a->v[pos] = data;
    a->n_elem++;
}

void array_append(Array * a, void * data) {
    if (a->size == a->n_elem)
        a->v = overflow(a->v, &a->size, a->n_elem);
    a->v[a->n_elem] = data;
    a->n_elem++;
}

void array_remove(Array * a, int pos){
    register int i;
    void * data;

    data= a->v[pos];

    if (a->destroy)
        a->destroy(data);
    if (pos != a->n_elem - 1)
        for (i = pos; i < a->n_elem; i++)
            a->v[i] = a->v[i+1];
    a->n_elem--;
}

void array_destroy(Array * a){
    register int i;
    for (i = 0; i < a->n_elem; i++)
        array_remove(a, a->n_elem - 1);
    free(a->v);
    free(a);
}