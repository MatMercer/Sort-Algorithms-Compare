#ifndef SORT_COMPARE_INSERTIONSORT_H
#define SORT_COMPARE_INSERTIONSORT_H


#include "SortAlgorithm.h"

class InsertionSort : public SortAlgorithm {
public:
    InsertionSort() : SortAlgorithm("Insertion") {}

    void sort(int *array, int n) const;
};


#endif //SORT_COMPARE_INSERTIONSORT_H
