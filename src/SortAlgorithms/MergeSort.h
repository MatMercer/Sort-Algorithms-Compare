//
// Created by mat on 7/2/17.
//

#ifndef SORT_COMPARE_MERGESORT_H
#define SORT_COMPARE_MERGESORT_H


#include "SortAlgorithm.h"

class MergeSort : public SortAlgorithm {
private:
    void merge(int array[], int l, int m, int r) const;

    void mergeSort(int array[], int l, int r) const;
public:
    MergeSort() : SortAlgorithm("Merge") {}

    void sort(int array[], int n) const;
};


#endif //SORT_COMPARE_MERGESORT_H
