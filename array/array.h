#ifndef ARRAY_H
#define ARRAY_H

typedef struct Array{
    void **v;
    int size;
    int n_elem;
    void (*destroy)(void *data);
} Array;

Array * array_init(void (*destroy)(void *data));
int array_search(Array * a, void * key, int (*compare) (void*a,void*b));
void array_insert(Array * a, void * data, int pos);
void array_append(Array * a, void * data);
void array_remove(Array * a, int pos);
void array_destroy(Array * a);

#endif //ARRAY_H
