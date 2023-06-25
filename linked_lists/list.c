#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void list_init(List *list, void (*destroy) (void *data))
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->destroy = destroy;
}

void list_insert_next(List *list, ListElem* previous_elem, void *data)
{
    ListElem *new_elem;

    new_elem = (ListElem *) malloc(sizeof(ListElem));
    if (!new_elem){
        printf("MEMORY ALOCATION ERROR");
        exit(1);
    }

    new_elem->data = (void *) data;
    
    /*insertion in list head*/
    if (!previous_elem){
        new_elem->next = list->head;
        list->head = new_elem;
    }
    /*insertion somewhere other than head*/
    else{
        new_elem->next = previous_elem->next;
        previous_elem->next = new_elem;
    } 

    if (!new_elem->next)
        list->tail = new_elem;
    list->size += 1;
}

int list_remove_next(List *list, ListElem *previous_elem)
{
    ListElem *old_elem;
    void *data;
    
    /*No remotion in empty list*/
    if (!(list->size))
        return 0;
    
    /*list head removal*/
    if (!previous_elem){    
        data = list->head->data;
        old_elem = list->head;
        list->head = list->head->next;
        
        /*Updates tail when there is less than two elements remaining*/
        if (!(list->head))
            list->tail = NULL;
        else if  (!(list->head->next))
            list->tail = list->head;        
    }
    /*removal somewhere other than head*/
    else{
        /*No removal after list tail*/
        if (!(previous_elem->next))
            return 0;
        
        data = previous_elem->next->data;
        old_elem = previous_elem->next;
        previous_elem->next = previous_elem->next->next;

        if(!(previous_elem->next))
            list->tail = previous_elem;
    }
    
    if (list->destroy)
        list->destroy (data);
    free(old_elem);
    list->size -= 1;
    return 1;
}

void list_destroy(List* list)
{
    register int i;
    
    for (i = list->size; i != 0; --i)
        list_remove_next(list, NULL);
}