#include <iostream>
#include <zconf.h>
#include <chrono>
#include <fstream>
#include <algorithm>
#include "SortAlgorithms/SortAlgorithm.h"
#include "SortAlgorithms/RadixSort.h"
#include "SortAlgorithms/ArrayUtils.h"
#include "SortAlgorithms/InsertionSort.h"
#include "SortAlgorithms/BubbleSort.h"
#include "SortAlgorithms/QuickSort.h"
#include "SortAlgorithms/SelectionSort.h"
#include "SortAlgorithms/MergeSort.h"

/* CSV files folder name */
#define CSV_FOLDER "sortalgs_csv/"

using namespace std;
using namespace std::chrono;

/* CSV program output */
void csvOutput(ofstream *file, char csvSep, string algName, string dataType, long nanoseconds, int N, int minVal, int maxVal) {
    *file << algName << csvSep << dataType << csvSep << nanoseconds << csvSep << N << csvSep << minVal << csvSep
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

/* Returns a csv file with the header already inserted */
void openAlgCSVFile(ofstream *file, char csvSep, string name, string dataType) {
    /* Lower case the names */
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    transform(dataType.begin(), dataType.end(), dataType.begin(), ::tolower);

    /* Generates the file name */
    string fileName = name + "." + dataType + ".csv";

    /* Remove spaces */
    replace(fileName.begin(), fileName.end(), ' ', '_');

    //cout << "Opening '" << fileName << "' file." << endl;

    file->open(CSV_FOLDER + fileName);
    
    /* CSV header */
    *file << "Algorithm Name" << csvSep << "Data Type" << csvSep << "Nano Seconds" << csvSep << "N" << csvSep
         << "Min. Value" << csvSep << "Max. Value" << endl;
}



int main(int argc, char **argv) {
    /* SortAlgorithms for testing */
    SortAlgorithm *algorithms[] = {
            new BubbleSort(),
            new InsertionSort(),
            new SelectionSort(),
            new QuickSort(),
            new MergeSort(),
            new RadixSort()
    };

    /* SortAlgorithms size */
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
    cout << "Testing " << algSize << " algorithms with an array of ints from 1 to " << maxN << " of size." << endl;
    cout << "The range of the numbers is [" << minVal << ", " << maxVal << "]" << endl;

    /* Creates the csv folder */
    char cCurrentPath[FILENAME_MAX];
    string currentPath = "";
    getcwd(cCurrentPath, sizeof(cCurrentPath));
    currentPath += cCurrentPath;
    string csvFolderName = currentPath + "/" + CSV_FOLDER;
    int dir_err = system(("mkdir " + csvFolderName + " 2> /dev/null").c_str());
    if (dir_err == -1) {
        cerr << "Failed to create '" << CSV_FOLDER << "' folder.";
        return 3;
    }

    /* Main loop that tests the algorithms */
    for (int algId = 0; algId < algSize; algId += 1) {
        /* Current sort algorithm */
        SortAlgorithm *curSortAlg = algorithms[algId];

        /* Current file to write */
        ofstream csvFile;

        /* Current data type */
        string curDataType;

        /* Current test info */
        cout << endl << "Testing " << curSortAlg->getName() << " sort algorithm." << endl;

        curDataType = "Random Array";
        openAlgCSVFile(&csvFile, csvSep, curSortAlg->getName(), curDataType);
        cout << "With random numbers array..." << endl;
        for (int N = 1; N <= maxN; N += 1) {
            //cerr << "N=" << N << endl;

            /* Allocate the array */
            int *array = ArrayUtils::genRandNumArray(N, minVal, maxVal);

            //ArrayUtils::printArray(array, N);

            /* Time measurement */
            long time = measureAlgTime(curSortAlg, array, N);

            /* CSV output */
            csvOutput(&csvFile, csvSep, curSortAlg->getName(), curDataType, time, N, minVal, maxVal);

            //ArrayUtils::printArray(array, N);

            /* Deletes the old array */
            delete[] array;
        }
        /* Closes the file */
        csvFile.close();

        curDataType = "Random Crescent Sorted Array";
        openAlgCSVFile(&csvFile, csvSep, curSortAlg->getName(), curDataType);
        cout << "With crescent sorted numbers array..." << endl;
        for (int N = 1; N <= maxN; N += 1) {
            /* Allocate the array */
            int *array = ArrayUtils::genRandCresSortedNumArray(N, minVal, maxVal);
            //ArrayUtils::printArray(array, N);

            /* Time measurement */
            long time = measureAlgTime(curSortAlg, array, N);

            /* CSV output */
            csvOutput(&csvFile, csvSep, curSortAlg->getName(), curDataType, time, N, minVal, maxVal);

            /* Deletes the old array */
            delete[] array;
        }
        /* Closes the file */
        csvFile.close();

        curDataType = "Random Decrescent Sorted Array";
        openAlgCSVFile(&csvFile, csvSep, curSortAlg->getName(), curDataType);
        cout << "With decrescent sorted numbers array..." << endl;
        for (int N = 1; N <= maxN; N += 1) {
            /* Allocate the array */
            int *array = ArrayUtils::genRandDecSortedNumArray(N, minVal, maxVal);
            //ArrayUtils::printArray(array, N);

            /* Time measurement */
            long time = measureAlgTime(curSortAlg, array, N);

            /* CSV output */
            csvOutput(&csvFile, csvSep, curSortAlg->getName(), curDataType, time, N, minVal, maxVal);

            /* Deletes the old array */
            delete[] array;
        }
        /* Closes the file */
        csvFile.close();
    }

    /* Delete algorithms array */
    for (int i = 0; i < algSize; i++) {
        delete algorithms[i];
    }

    return 0;
}


