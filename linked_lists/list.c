#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void list_init(List *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void list_insert_next(List *list, Item *previous_item, const void *data)
{
    Item *newItem;

    newItem = (Item *) malloc(sizeof(Item));
    if(!newItem){
        printf("Fail in memory allocation");
        exit(1);
    }

    newItem->data = data;

    /*Insertion in list head*/
    if (!previous_item){
        newItem->next = list->head;
        list->head = newItem;
    }

    /*Insertion somewhere else*/
    else{
        newItem->next = previous_item->next;
        previous_item->next = newItem;
        /*If newItem is last element, so adjust the list tail*/
        if (!(newItem->next))
            list->tail = newItem;
    }
    list->size += 1;
}

int list_rem_next(List *list, Item *previous_item)
{
    Item *old_item;

    /*No remotion in empty list*/
    if (!(list->size)){
        return -1;
    }

    /*Remotion in list head*/
    if (!previous_item){
        old_item = list->head;
        list->head = list->head->next;

        if (!(list->head))
            list->tail = list->head;
    }
    /*remotion of other item*/
    else{
        if (!(previous_item->next))
            return -1;
        
        old_item = previous_item->next;
        previous_item->next = previous_item->next->next;

        /*if removed item was previously the list tail, so list tail is updated*/
        if (!(previous_item->next))
            list->tail = previous_item;
    }

    free(old_item);
    list->size -= 1;
    return 0;
}

void list_destroy(List *list)
{
    register int i;

    for (i=0; i < list->size; i++)
        list_rem_next(list, NULL);
}