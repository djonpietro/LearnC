#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include "../linked_lists/list.h"

/*Implements queues as linked lists*/
typedef List Queue;
typedef ListElem QueueElem;

#define queue_init list_init

void enqueue(Queue *queue, void *data);

void dequeue(Queue *queue);

#define queue_peek(queue) ((queue)->head == NULL ? NULL: (queue)->head->data)

#define queue_size(queue) ((queue)->size)

#define queue_destroy list_destroy

#endif

