#ifndef SORT_COMPARE_BUBBLESORT_H
#define SORT_COMPARE_BUBBLESORT_H


#include "SortAlgorithm.h"

class BubbleSort : public SortAlgorithm {
public:
    BubbleSort() : SortAlgorithm("Bubble") {}

    void sort(int array[], int n) const;
};


#endif //SORT_COMPARE_BUBBLESORT_H
