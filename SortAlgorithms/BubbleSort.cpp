//
// Created by mat on 7/2/17.
//

#include "BubbleSort.h"

/* http://www.cplusplus.com/forum/general/127295/ */
void BubbleSort::sort(int *array, int n) const {
    int swap;
    for (int i = 0; i < (n - 1); i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) /* For decreasing order use < */
            {
                swap = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap;
            }
        }
    }
}
