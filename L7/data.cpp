#include <stdio.h>
#include <iostream>
#include "data.h"

int mesnyankin::createBinaryFile(const int arg, char *arguments[])
{
    if (arg < 3) {
        std::cout << "Not enough parameters!\nPress any key";
        system("pause");
        return 1;
    }

    FILE *ft = fopen(arguments[2], "rt");
    if (ft == NULL) {
        std::cout << "Error: can't open file with data!\n" << arguments[2];
        std::cout << "Press any key";
        system("pause");
        return 1;
    }

    FILE *fb = fopen(arguments[1], "wb+");
    if (fb == NULL) {
        fclose(ft);
        std::cout << "Error: can't create binary file\n" << arguments[1];
        std::cout << "Press any key";
        system("pause");
        return 1;
    }

    Mountain mntn;
    int kol = 0, nw = 1;
    while (nw) {
        fscanf(ft,"%30s", mntn.Name);
        if (strcmp(mntn.Name, "**") == 0 || feof(ft)) {
            break;
        }

        fscanf(ft,"%d", &mntn.longtitude);
        fscanf(ft,"%d", &mntn.latitude);
        fscanf(ft,"%d", &mntn.altitude);
        nw = fwrite(&mntn, sizeof(Mountain), 1, fb);
        kol++;
    }
    if (nw != 1) {
        std::cout << "Error: write error";
    }

    fclose(ft);
    fclose(fb);

    std::cout << "Created binary file with " << kol << "record per " << sizeof(Mountain) <<  "bytes\n";
    system("pause");
    return 0;
}

int mesnyankin::findRecord(const int arg, char *arguments[])
{
    if (arg < 2) {
        std::cout << "Not enough parameters\nPress any key";
        system("pause");
        return 1;
    }

    FILE *fb = fopen(arguments[1], "rb");

    if (fb == NULL) {
        std::cout << "Error: couldn't open binary file: ", arguments[1];
        system("pause");
        return 1;
    }

    Mountain mntn;
    int kol = 0, nr = 1;
    while (nr) {
        nr = fread(&mntn, sizeof(Mountain), 1, fb);
        if (nr > 0)
            if ((mntn.latitude > 0) && (mntn.longtitude > 3000)) {
                std::cout << "Found record: " << mntn.Name << " | LO:"  << mntn.longtitude << " | LA / AL: " << mntn.latitude << " / " << mntn.altitude << "\n";
                kol++;
            }
    }

    if (kol == 0)
        std::cout << "No data found!\n";
    else
        std::cout << "Found: " << kol;

    fclose(fb);
    system("pause");
    return 0;
}

int mesnyankin::correctFile(const int arg, char *arguments[])
{
    if (arg < 2) {
        std::cout << "Not enough parameters!\nPress any key";
        system("pause");
        return 1;
    }

    FILE *fb = fopen(arguments[1], "rb+");
    if (fb == NULL) {
        std::cout << "Error: couldn't open binary file: ", arguments[1];
        system("pause");
        return 1;
    }

    Mountain mntn;
    int kol=0, nr=1, nw=1, flag;
    nr = fread(&mntn, sizeof(Mountain), 1, fb);
    while (nr == 1 && nw == 1) {
        std::cout << "Found data: " << mntn.Name << " | LO:"  << mntn.longtitude << " | LA / AL: " << mntn.latitude << " / " << mntn.altitude << "\n";

        flag=0;
        if (mntn.latitude < -90) {
            mntn.latitude = -90;
            flag=1;
        }

        if (mntn.latitude > 90) {
            mntn.latitude = 90;
            flag=1;
        }

        if (mntn.altitude < -180) {
            mntn.altitude = -180;
            flag=1;
        }

        if (mntn.altitude > 180) {
            mntn.altitude = 180;
            flag=1;
        }

        if (mntn.longtitude < 0) {
            mntn.altitude = abs(mntn.altitude);
            flag=1;
        }

        if (flag) {
            kol++;
            fseek(fb, 0 - sizeof(mntn), SEEK_CUR);
            nw = fwrite(&mntn, sizeof(mntn), 1, fb);
            fseek(fb, 0, SEEK_CUR);

            std::cout << "Corrected: " << mntn.Name << " | LO:"  << mntn.longtitude << " | LA / AL: " << mntn.latitude << " / " << mntn.altitude << "\n";
        }
        nr = fread(&mntn, sizeof(mntn), 1, fb);
    }
    if (kol == 0) {
        std::cout << "No corrections\n";
    }
    else
        std::cout << "Corrected: " << kol << "\n";

    fclose(fb);

    system("pause");
    return 0;
}
