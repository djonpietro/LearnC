#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    int *p, *q;

    p = (int *) malloc(sizeof(int));

    printf("Address of p: %p \n", p);

    q = p;

    printf("New address of %p: \n", p);
    
    printf("Address of q: %p\n", q);

    free(p);

    
    return 0;
}
