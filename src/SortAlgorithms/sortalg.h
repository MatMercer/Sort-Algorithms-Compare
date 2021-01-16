#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <algorithm>

template<typename SortType>
struct sortalg {
    template<class RandomAccessIterator>
    static void sort(RandomAccessIterator start, RandomAccessIterator end);
};

class Bubble;

template<>
template<class RandomAccessIterator>
void sortalg<Bubble>::sort(RandomAccessIterator start, RandomAccessIterator);

template<>
template<class RandomAccessIterator>
void sortalg<Bubble>::sort(RandomAccessIterator start, RandomAccessIterator end) {
    int j = 1;
    for (auto current = start; current < end; current++, j++) {
        for(auto bubble = start; bubble < end - j; bubble++) {
            auto next = bubble + 1;
            if (*bubble > *next) {
                std::swap(*bubble, *next);
            }
        }
    }
}

#endif
