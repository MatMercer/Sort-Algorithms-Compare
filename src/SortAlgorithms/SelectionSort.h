#ifndef SORT_COMPARE_SELECTIONSORT_H
#define SORT_COMPARE_SELECTIONSORT_H


#include "SortAlgorithm.h"

class SelectionSort : public SortAlgorithm {
public:
    SelectionSort() : SortAlgorithm("Selection") {}

    void sort(int array[], int n) const;
};


#endif //SORT_COMPARE_SELECTIONSORT_H
