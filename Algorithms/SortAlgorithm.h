#ifndef SORT_COMPARE_SORTALGORITHM_H
#define SORT_COMPARE_SORTALGORITHM_H

#include <iostream>

using namespace std;

class SortAlgorithm {
private:
    string name;
public:
    SortAlgorithm(string name);

    string getName();

    virtual void sort(int *array, int n) const = 0;

    virtual ~SortAlgorithm() {}
};

#endif //SORT_COMPARE_SORTALGORITHM_H
