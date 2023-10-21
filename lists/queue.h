//
// Created by joao on 23/09/23.
//
#include "list.h"
#ifndef QUEUE_H
#define QUEUE_H

typedef List Queue;

#define queue_init list_init
#define queue_destroy list_destroy

void enqueue(Queue *queue, void * data);\
void * dequeue(Queue *queue);

#endif //QUEUE_H
