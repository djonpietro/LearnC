//
// Created by joao on 08/10/23.
//
#include <stdlib.h>
#include "aqueue.h"

Aqueue * aqueue_init(int size) {
    Aqueue * queue = (Aqueue *) malloc(sizeof(Aqueue));
    if (queue == NULL)
        exit(1);
    queue->v = (void **) malloc(sizeof(void)*size);
    if (!queue->v)
        exit(1);
    queue->size = size;
    queue->n_elem = 0;
    queue->f = -1;
    queue->r = -1;
    return queue;
}

int enqueue(Aqueue *q, void *data) {
    int prov = (q->r + 1) % q->size;
    if (prov == q->f)
        return 0; //overflow
    q->r = prov;
    q->v[q->r] = data;
    if (q->f == -1)
        q->f = 0;
    q->n_elem++;
    return 1;
}

void * dequeue(Aqueue *q) {
    void * data;
    if (q->f == -1)
        return NULL; //underflow
    data = q->v[q->f];
    if (q->f == q->r)
        q->f = q->r = -1;
    else
        q->f = (q->f + 1) % q->size;
    q->n_elem--;
    return data;
}

void aqueue_destroy(Aqueue *q) {
    register int i;
    for (i = 0; i < q->n_elem; i++)
        dequeue(q);
    free(q->v);
    free(q);
}
