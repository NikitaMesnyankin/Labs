#ifndef LAB4_DATA_H
#define LAB4_DATA_H
#include "iostream"

namespace mesnyankin {
    int findSum(int *arr, int begin, int end);
    int * createArray(FILE *inp, int n);
    void outputArray(FILE *outp, int * a, int n);
    void destroyArray(int * a, int n);
}

#endif LAB4_DATA_H
