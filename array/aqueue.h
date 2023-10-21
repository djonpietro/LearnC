//
// Created by joao on 08/10/23.
//

#ifndef AQUEUE_H
#define AQUEUE_H

typedef struct Aqueue {
    void **v;
    int f;
    int r;
    int size;
    int n_elem;
} Aqueue;

Aqueue * aqueue_init(int size);
void aqueue_destroy(Aqueue *q);
int enqueue(Aqueue *q, void *data);
void * dequeue(Aqueue *q);

#endif //AQUEUE_H
