#include "data.h"

int mesnyankin::findSum(int *arr, int begin, int end) {
    int amount = end - begin + 1;
    if (begin < 0) {
        std::cout << "Wrong N!..";
        return -1;
    }
    if (begin == end) {
        return arr[begin];
    } else {
        return findSum(arr, begin, begin + amount / 2 + amount % 2 - 1) + findSum(arr, begin + amount / 2 + amount % 2, end);
    }
}

int * mesnyankin::createArray(FILE *inp, int n)
{
    int * x = new int[n];
    for (auto i = 0; i < n; i++)
    {
        fscanf(inp, "%d", &x[i]);
    }
    return x;
}

void mesnyankin::outputArray(FILE *outp, int * a, int n)
{
    fprintf(outp, "%s", "Array: \n");
    for (auto i = 0; i < n; i++)
    {
        fprintf(outp, "%4d", a[i]);
    }
}

void mesnyankin::destroyArray(int * a, int n)
{
    delete [] a;
}
