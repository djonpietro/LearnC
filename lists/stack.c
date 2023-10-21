//
// Created by joao on 23/09/23.
//
#include "stack.h"
#include <stdlib.h>

void stack_push(Stack *stack, void *data){
    list_insert_next(stack, stack->head, data);
}

void * stack_pop(Stack *stack){
    void *data;
    data = (void*) stack->head->next->data;
    list_remove_next(stack, stack->head);
    if (stack->destroy == NULL)
        return data;
    return NULL;
}