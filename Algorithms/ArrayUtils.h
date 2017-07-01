#ifndef SORT_COMPARE_ARRAYUTILS_H
#define SORT_COMPARE_ARRAYUTILS_H

class ArrayUtils {
public:
    static int *genRandNumArray(int size, int minVal, int maxVal);

    static int *genRandCresSortedNumArray(int n, int minVal, int maxVal);

    static void printArray(int *array, int n);

    static void quickSort(int array[], int left, int right);

    static int *genRandDecSortedNumArray(int n, int minVal, int maxVal);

    static void reverseArray(int array[], int n);
};

#endif //SORT_COMPARE_ARRAYUTILS_H
