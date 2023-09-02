#ifndef SORT_H
#define SORT_H

void bubble_sort(int* v, int start, int end);

void selection_sort(int* v, int start, int end);

void insertion_sort(int* v, int start, int end);

void merge_sort(int* v, int start, int end);

void merge(int*v, int start, int* left_array, int* right_array, int left_size, int right_size);

void quicksort(int* v, int start, int end);

int partition(int* v, int start, int end);

void swap(int* v ,int a, int b);

#endif