#include <stdio.h>
#include <stdlib.h>

void bublle_sort(int array[], int size)
{
    register int i, j;
    int temp;

    for (i = 0; i < size - 1; ++i)
        for (j = 0; j < size - 1 - i; j++)
            if (array[j] > array[j+1]){
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
}

void selection_sort(int a[], int size)
{
    register int i, j;
    int temp, lowest_value_index;

    for (i = 0; i < size - 1; ++i){
        lowest_value_index = i;

        for (j = i + 1; j < size; ++j)
            if (a[j] < a[lowest_value_index])
                lowest_value_index = j;

        temp = a[i];
        a[i] = a[lowest_value_index];
        a[lowest_value_index] = temp;  
    }
}

void insertion_sort(int a[], int size)
{
    register int i, j;
    int temp;

    for (i = 0; i < size - 1; ++i)
        for(j = i + 1; j > 0; --j)
            if (a[j] < a[j-1]){
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
}

void merge(int a[], int left_array[], int right_array[], int size_left, int size_right)
{
    register int i = 0, j = 0, k = 0;

    while (i < size_left && j < size_right){
        if (left_array[i] < right_array[j]){
            a[k] = left_array[i];
            ++i;
            ++k;
        }
        else{
            a[k] = right_array[j];
            ++j;
            ++k;
        }
    }

    while (i < size_left){
        a[k] = left_array[i];
        ++i;
        ++k;
    }

    while (j < size_right){
        a[k] = right_array[j];
        ++j;
        ++k;
    }
}

void merge_sort(int a[], int size)
{
    if (size > 1){
        register int i;

        int middle = size/2;
        
        int size_left = middle;
        int size_right = size - middle;

        int left_array[size_left], right_array[size_right];

        for (i = 0; i < size_left; ++i)
            left_array[i] = a[i];
        
        for (i = middle; i < size; ++i)
            right_array[i - middle] = a[i];

        merge_sort(left_array, size_left);
        merge_sort(right_array, size_right);

        merge(a, left_array, right_array, size_left, size_right);
    }
}

int main(void)
{
    int array[] = {12, 12, 12, 2, 5};
    register int i;

    merge_sort(array, 5);

    for (i = 0; i < 5; ++i)
        printf("%d ", array[i]);
    putchar('\n');    

    return 0;
}