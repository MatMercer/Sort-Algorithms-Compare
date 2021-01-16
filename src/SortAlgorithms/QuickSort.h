#ifndef SORT_COMPARE_QUICKSORT_H
#define SORT_COMPARE_QUICKSORT_H


#include "SortAlgorithm.h"

class QuickSort : public SortAlgorithm {
private:
    void quickSort(int array[], int left, int right) const;
public:
    QuickSort() : SortAlgorithm("Quick") {}

    void sort(int array[], int n) const;
};


#endif //SORT_COMPARE_QUICKSORT_H
