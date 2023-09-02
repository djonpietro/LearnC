#include "sort.h"
#include <stdlib.h>
#include <time.h>

void swap(int* v, int a, int b){
    int temp;
    temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

void bubble_sort(int* v, int start, int end){
    register int i, j;

    for (i = start; i < end+1; i++)
        for (j = start; j < end+1 - (i + 1); j++)
            if (v[j] > v[j+1]) 
                swap(v, j, j+1);
}

void selection_sort(int* v, int start, int end){
    register int i, j, lowest_index;

    for (i = start; i < end+1; i++) {
        lowest_index = i;
        for (j = i + 1; j < end+1; j++)
            if (v[lowest_index] > v[j])
                lowest_index = j;
        
        swap(v, lowest_index, i);
    }
}

void insertion_sort(int* v, int start, int end){
    register int i, j;

    for (i = start; i < end+1; i++)
        for (j = i + 1; j > 0; j--)
            if (v[j] < v[j-1])
                swap(v, j, j-1);
}

int partition(int* v, int start, int end) {
    srand(time(NULL));
    int ppivot = (rand() % (end - start + 1)) + start;
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

void merge(int*v, int start, int* left_array, int* right_array, int left_size, int right_size) {
    register int i = 0, j = 0, k = start;

    while (i < left_size && j < right_size) {
        if (left_array[i] < right_array[j]) {
            v[k] = left_array[i];
            i++;
            k++;
        }

        else {
            v[k] = right_array[j];
            j++;
            k++;
        }
    }

    while (i < left_size) {
        v[k] = left_array[i];
        i++;
        k++;
    }

    while (j < right_size) {
        v[k] = right_array[j];
        j++;
        k++;
    }
}

void merge_sort(int* v, int start, int end) {
    register int i, j, k = start;
    int middle = (end+start) / 2,
        left_size = middle-start+1,
        right_size = end-middle;

    int right_array[right_size],
        left_array[left_size];

    if (end - start > 0) {
        for (i = 0; i < left_size; i++){
            left_array[i] = v[k];
            k++;
        }

        for (j = 0; j < right_size; j++) {
            right_array[j] = v[k];
            k++;
        }

        merge_sort(left_array, 0, left_size-1);
        merge_sort(right_array, 0, right_size-1);
        merge(v, start, left_array, right_array, left_size, right_size);
    }
}