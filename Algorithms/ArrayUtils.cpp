#include <cstdlib>
#include <iostream>
#include "ArrayUtils.h"

using namespace std;

int *ArrayUtils::genRandNumArray(int size, int minVal, int maxVal) {
    int *array = new int[size];

    for (int i = 0; i < size; i++) {
        array[i] = rand() % maxVal + minVal;
    }

    return array;
}

int *ArrayUtils::genRandCresSortedNumArray(int n, int minVal, int maxVal) {
    int *array = ArrayUtils::genRandNumArray(n, minVal, maxVal);

    ArrayUtils::quickSort(array, 0, n - 1);

    return array;
}

int *ArrayUtils::genRandDecSortedNumArray(int n, int minVal, int maxVal) {
    int *array = ArrayUtils::genRandNumArray(n, minVal, maxVal);

    ArrayUtils::quickSort(array, 0, n - 1);

    /* Reverse it */
    ArrayUtils::reverseArray(array, n);

    return array;
}


void ArrayUtils::printArray(int *array, int n) {
    cout << "[";

    for (int i = 0; i < n; i += 1) {
        if (i + 1 != n) {
            cout << array[i] << ", ";
        } else {
            cout << array[i];
        }
    }

    cout << "]" << endl;
}

/* http://www.algolist.net/Algorithms/Sorting/Quicksort */
void ArrayUtils::quickSort(int *array, int left, int right) {
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

/* https://stackoverflow.com/questions/19712903/reverse-contents-in-array */
void ArrayUtils::reverseArray(int *array, int n) {
    int temp;
    for (int i = 0; i < n / 2; ++i) {
        temp = array[i];
        array[i] = array[n - i - 1];
        array[n - i - 1] = temp;
    }
}
