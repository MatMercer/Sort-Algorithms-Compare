//
// Created by mat on 7/1/17.
//

#include "InsertionSort.h"

void InsertionSort::sort(int *array, int n) const {
    int j, temp;

    for (int i = 0; i < n; i++) {
        j = i;

        while (j > 0 && array[j] < array[j - 1]) {
            temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
            j--;
        }
    }
}
