#include "data.h"

int main(int argc, char *argv[]) {
    FILE *inp, *outp;
    int n, *arr = nullptr;
    inp = fopen(argv[1], "r");
    outp = fopen(argv[2], "w+");

    fscanf(inp, "%d", &n);
    arr = mesnyankin::createArray(inp, n);
    mesnyankin::outputArray(outp, arr, n);
    std::cout << mesnyankin::findSum(arr, 0, n - 1);
    mesnyankin::destroyArray(arr, n);
    fclose(inp);
    fclose(outp);
    return 0;
}
