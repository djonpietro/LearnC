#ifndef LIST_H
#define LIST_H

typedef struct _Item{
    void *data;
    struct _Item *next;
} Item;

typedef struct _List{
    Item *head;
    Item *tail;
    int size;
} List;

void list_init(List *list);
void list_insert_next(List *list, Item *previous_item, const void *data);
int list_rem_next(List *list, Item *previous_item);
void list_destroy(List *list);

#endif