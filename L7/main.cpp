#include "data.h"
#include <iostream>

int main(int argc, char * argv[]) {

    if (mesnyankin::createBinaryFile(argc, argv) == 1) {
        std::cout << "Error (createBinaryFile)";
        system("pause");
        return -1;
    }

    if (mesnyankin::findRecord(argc, argv) == 1) {
        std::cout << "Error (createBinaryFile)";
        system("pause");
        return -1;
    }

    if (mesnyankin::correctFile(argc, argv) == 1) {
        std::cout << "Error (createBinaryFile)";
        system("pause");
        return -1;
    }
}