#include "data.h"
#include <iostream>

int main(int argc, char * argv[]) {
    int handler = mesnyankin::createBinaryFile(argc, argv);

    if (handler == 1) {
        std::cout << "Error (createBinaryFile)";
        system("pause");
        return 1;
    }

    handler = mesnyankin::findRecord(argc, argv);

    if (handler == 1) {
        std::cout << "Error (createBinaryFile)";
        system("pause");
        return 1;
    }

    handler = mesnyankin::correctFile(argc, argv);

    if (handler == 1) {
        std::cout << "Error (createBinaryFile)";
        system("pause");
        return 1;
    }
    return 0;
}