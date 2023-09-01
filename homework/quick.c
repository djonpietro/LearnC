#include <stdio.h>
#include <stdlib.h>
#include "../sort/sort.h"

int* overflow(int* v, int tam);

int main(void){
    int *v, value, i = 0, tam = 10, n_elem;

    if ((v = (int *) malloc(sizeof(int)*10)) == NULL) {
        printf("Error in memory allocation\n");
        exit(1);
    }
    printf("Enter the values\n");
    while (!feof(stdin)) {
        scanf("%d\n", &value);
        if (i == tam) {
            v = overflow(v, tam);
            tam *= 2;
        }
        v[i] = value;
        i++;
    }

    quicksort(v, 0, i-1);
    n_elem = i;

    for (i = 0; i < n_elem; i++)
        printf("%d ", v[i]);
    putchar('\n');

    free(v);
    return 0;
}

int* overflow(int* v, int tam) {
    int new_tam = tam * 2;
    int* temp;
    register int i;

    if (!(temp = (int*) malloc(sizeof(int)*new_tam))){
        printf("Error in temp allocation\n");
        exit(1);
    }

    for (i = 0; i < tam; i++)
        temp[i] = v[i];

    free(v);
    return temp;
}
