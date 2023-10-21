//
// Created by joao on 23/09/23.
//
#include "list.h"

#ifndef STACK_H
#define STACK_H

typedef List Stack;

#define stack_init list_init
#define stack_destroy list_destroy

void stack_push(Stack *stack, void *data);
void * stack_pop(Stack *stack);

#endif //STACK_H
