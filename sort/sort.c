#include "sort.h"
#include <stdlib.h>
#include <time.h>

void swap(int* v, int a, int b){
    int temp;
    temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

void bubble_sort(int* v, int size){
    register int i, j;

    for (i = 0; i < size; i++)
        for (j = 0; j < size - (i + 1); j++)
            if (v[j] > v[j+1]) 
                swap(v, j, j+1);
}

void selection_sort(int* v, int size){
    register int i, j, lowest_index;

    for (i = 0; i < size; i++) {
        lowest_index = i;
        for (j = i + 1; j < size; j++)
            if (v[lowest_index] > v[j])
                lowest_index = j;
        
        swap(v, lowest_index, i);
    }
}

void insertion_sort(int* v, int size){
    register int i, j;

    for (i = 0; i < size; i++)
        for (j = i + 1; j > 0; j--)
            if (v[j] < v[j-1])
                swap(v, j, j-1);
}

int partition(int* v, int start, int end) {
    int ppivot = (start+end) / 2;
    register int i, j;

    swap(v, ppivot, start);
    ppivot = start;

    i = start+1; j = end;

    while (i < j) {
        while (v[i] < v[ppivot] && i < end) i++;
    
        while (v[j] >= v[ppivot] && j > ppivot) j--;

        if (i < j) swap(v, i, j);
    }

    swap(v, ppivot, j);
    return j;
}

void quicksort(int* v, int start, int end) {
    int pos;
    if (end - start > 0) {
        pos = partition(v, start, end);
        quicksort(v, start, pos-1);
        quicksort(v, pos + 1, end);
    }
}