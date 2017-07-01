#ifndef SORT_COMPARE_RADIXSORT_H
#define SORT_COMPARE_RADIXSORT_H

#include <array>
#include "SortAlgorithm.h"

class RadixSort : public SortAlgorithm {
private:
    static int getMax(int *array, int n);

    static void countSort(int *array, int n, int exp);

public:
    RadixSort() : SortAlgorithm("Radix") {}

    void sort(int *array, int n) const;
};


#endif //SORT_COMPARE_RADIXSORT_H
