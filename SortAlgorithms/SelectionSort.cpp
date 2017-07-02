//
// Created by mat on 7/2/17.
//

#include "SelectionSort.h"

/* http://cforbeginners.com/ssort.html */
void SelectionSort::sort(int *array, int n) const {
    //pos_min is short for position of min
    int pos_min, temp;

    for (int i = 0; i < n - 1; i++) {
        pos_min = i;//set pos_min to the current index of array

        for (int j = i + 1; j < n; j++) {

            if (array[j] < array[pos_min])
                pos_min = j;
            //pos_min will keep track of the index that min is in, this is needed when a swap happens
        }

        //if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
        if (pos_min != i) {
            temp = array[i];
            array[i] = array[pos_min];
            array[pos_min] = temp;
        }
    }
}
