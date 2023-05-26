#include <stdio.h>
#include <stdlib.h>

typedef struct _Element{
    int value;
    struct _Element *next;
} Element;

typedef struct _List{
    Element *head;
    int tam;
} List;

void init(List *list)
{
    list->head = NULL;
    list->tam = 0;
}

void insert(List *list, Element *elem)
{
    Element *p1, *p2;

    p1 = NULL;
    p2 = list->head;

    if (!(list->head))
        elem->next = NULL;
        list->head = elem;
        return;

    while (1)
    {
        if (!(p2->next) && elem->value > p2->value){
            elem->next = NULL;
            p1->next = elem;
            return;
        }
        
        else if (elem->value < p2->value){
            elem->next = p2;
            p1->next = elem;
            return;
        }
        
        p1 = p2;
        p2 = p2->next;
    }
}

int delete(List *list, Element *rem)
{
    Element **p;

    p = &list->head;

    while (*p)
    {
        if (*p == rem) {
            *p = rem->next;
            free(rem);
            return 0; /*operation successful*/
        }
        p = &((*p)->next);
        return 1; /*operation made no remotion*/
    }
}

Element* search(List *list, int value)
{
    Element *p;

    p = list->head;
    while (p)
    {
        if (p->value == value)
            return p;
    }
    return NULL;
}

int main(void)
{
    
}