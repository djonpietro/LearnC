//
// Created by joao on 23/09/23.
//
#include "queue.h"
#include <stdlib.h>

void enqueue(Queue *queue, void * data){
    list_insert_next(queue, queue->tail, data);
}

void * dequeue(Queue *queue){
    void * data;
    data = (void*) queue->head->next->data;
    list_remove_next(queue, queue->head);
    if (queue->destroy == NULL)
        return data;
    return NULL;
}