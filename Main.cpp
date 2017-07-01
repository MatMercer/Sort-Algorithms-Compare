#include <iostream>
#include <zconf.h>
#include <chrono>
#include "Algorithms/SortAlgorithm.h"
#include "Algorithms/RadixSort.h"
#include "Algorithms/ArrayUtils.h"
#include "Algorithms/InsertionSort.h"

using namespace std;
using namespace std::chrono;

/* CSV program output */
void csvOutput(char csvSep, string algName, string dataType, long nanoseconds, int N, int minVal, int maxVal) {
    cout << algName << csvSep << dataType << csvSep << nanoseconds << csvSep << N << csvSep << minVal << csvSep
         << maxVal << endl;
}

void
csvOutput(char csvSep, string algName, string dataType, string nanoseconds, string N, string minVal, string maxVal) {
    cout << algName << csvSep << dataType << csvSep << nanoseconds << csvSep << N << csvSep << minVal << csvSep
         << maxVal << endl;
}

/* Returns a long nanoseconds value based in the time expend by an sort algorithm */
long measureAlgTime(SortAlgorithm *alg, int *array, int N) {
    /* Calculates the time before and after the sort */
    auto t1 = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    alg->sort(array, N);
    auto t2 = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

    /* Return the nanoseconds */
    return t2 - t1;
}

int main(int argc, char **argv) {
    /* Algorithms for testing */
    SortAlgorithm *algorithms[] = {
            new RadixSort(),
            new InsertionSort()
    };

    /* Algorithms size */
    int algSize = sizeof(algorithms) / sizeof(*algorithms);

    /* Get arguments from command line */
    if (argc < 4) {
        cerr
                << "This program outputs an CSV with sorted algorithms "
                << endl
                << "nanoseconds time based in an N max size array that "
                << endl
                << "increments from 1 to [MAX SIZE]."
                << endl
                << "The values are randomly generated and sorted in both "
                << endl
                << "crescent and decrescent ways."
                << endl
                << "The random numbers have a range, please specify it "
                << endl
                << "with command line arguments."
                << endl;

        cerr << endl << "USAGE: sortalgs [MAX SIZE] [MIN. VALUES] [MAX. VALUES] > file.csv" << endl;

        cerr << endl << "The current sort algorithms avaible are: " << endl;
        for (int i = 0; i < algSize; i += 1) {
            cerr << algorithms[i]->getName() << " Sort." << endl;
        }

        return 1;
    }
    int maxN = abs(atoi(argv[1]));
    int minVal = abs(atoi(argv[2]));
    int maxVal = abs(atoi(argv[3]));

    if (minVal > maxVal) {
        cerr << "Error: maxVal must be greater than minVal" << endl;
        return 2;
    }

    /* CSV separator */
    char csvSep = ',';


    /* random seed, XOR different sources */
    srand(static_cast<unsigned int>(getpid()) ^
          static_cast<unsigned int>(pthread_self()) ^
          static_cast<unsigned int >(time(NULL)));


    /* Some program info */
    cerr << "Testing " << algSize << " algorithms with an array of ints from 1 to " << maxN << " of size." << endl;
    cerr << "The range of the numbers is [" << minVal << ", " << maxVal << "]" << endl;

    /* CSV header */
    csvOutput(csvSep, "Algorithm Name", "Data Type", "Nano Seconds", "N", "Min. Value", "Max. Value");

    /* Main loop that tests the algorithms */
    for (int algId = 0; algId < algSize; algId += 1) {
        /* Current test info */
        cerr << endl << "Testing " << algorithms[algId]->getName() << " sort algorithm." << endl;

        cerr << "With random numbers array..." << endl;
        for (int N = 1; N <= maxN; N += 1) {
            //cerr << "N=" << N << endl;

            /* Allocate the array */
            int *array = ArrayUtils::genRandNumArray(N, minVal, maxVal);

            //ArrayUtils::printArray(array, N);

            /* Time measurement */
            long time = measureAlgTime(algorithms[algId], array, N);

            /* CSV output */
            csvOutput(csvSep, algorithms[algId]->getName(), "Random Array", time, N, minVal, maxVal);

            //ArrayUtils::printArray(array, N);

            /* Deletes the old array */
            delete[] array;
        }

        cerr << "With crescent sorted numbers array..." << endl;
        for (int N = 1; N <= maxN; N += 1) {
            /* Allocate the array */
            int *array = ArrayUtils::genRandCresSortedNumArray(N, minVal, maxVal);
            //ArrayUtils::printArray(array, N);

            /* Time measurement */
            long time = measureAlgTime(algorithms[algId], array, N);

            /* CSV output */
            csvOutput(csvSep, algorithms[algId]->getName(), "Random Crescent Sorted Array", time, N, minVal, maxVal);

            /* Deletes the old array */
            delete[] array;
        }

        cerr << "With crescent sorted numbers array..." << endl;
        for (int N = 1; N <= maxN; N += 1) {
            /* Allocate the array */
            int *array = ArrayUtils::genRandDecSortedNumArray(N, minVal, maxVal);
            //ArrayUtils::printArray(array, N);

            /* Time measurement */
            long time = measureAlgTime(algorithms[algId], array, N);

            /* CSV output */
            csvOutput(csvSep, algorithms[algId]->getName(), "Random Decrescent Sorted Array", time, N, minVal, maxVal);

            /* Deletes the old array */
            delete[] array;
        }
    }


    /* Delete algorithms array */
    for (int i = 0; i < algSize; i++) {
        delete algorithms[i];
    }

    return 0;
}

