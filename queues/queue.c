#include <stdlib.h>
#include "../linked_lists/list.h"
#include "queue.h"

void enqueue(Queue *queue, void *data)
{
    list_insert_next(queue, queue->tail, data);
}

void dequeue(Queue *queue)
{
    list_remove_next(queue, NULL);
}
