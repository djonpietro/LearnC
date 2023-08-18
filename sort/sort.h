#ifndef SORT_H
#define SORT_H

void bubble_sort(int* v, int size);

void selection_sort(int* v, int size);

void insertion_sort(int* v, int size);

void merge_sort(int* v, int size);

void merge(int*v, int* left_array, int* right_array, int size_right, int size_left);

void quicksort(int* v, int start, int end);

int partition(int* v, int start, int end);

void swap(int* v ,int a, int b);

#endif