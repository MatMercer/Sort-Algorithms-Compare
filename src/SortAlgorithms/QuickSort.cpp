//
// Created by mat on 7/2/17.
//

#include "QuickSort.h"

void QuickSort::sort(int *array, int n) const {
    this->quickSort(array, 0, n - 1);
}

/* http://www.algolist.net/Algorithms/Sorting/Quicksort */
void QuickSort::quickSort(int *array, int left, int right) const {
    int i = left, j = right;
    int tmp;
    int pivot = array[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j) {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSort(array, left, j);
    if (i < right)
        quickSort(array, i, right);
}

