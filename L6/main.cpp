#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main(int argc, const char *argv[]) {
    //setlocale(LC_ALL, "Rus");
    int **A = nullptr;
    float *masres = nullptr;
    int n, P, E;
    FILE *inp, *outp;

    inp = fopen("C:/zakaz/i.txt", "r");
    outp = fopen("C:/zakaz/o.txt", "w+");

    printf("Size n: ");
    scanf("%d", &n);

    printf("Р: ");
    scanf("%d", &P);

    printf("Е: ");
    scanf("%d", &E);

    fprintf(outp, "Входные данные:\n n = %dn P = %dP E = %dE \n", n, P, E);

    A = GetMemMatrix(n);

    fprintf(outp, "Массив А:\n", n);

    InputMatrix(inp, A, n);
    OutputMatrix(outp, A, n);

    FindMatrix(A, n, P, E);

    if (FindMatrix (A, n, P, E))
    {
        masres = GetMemMas( n);
        fprintf(outp, "Среднее арифметическое для каждой строки матрицы А:\n" );
        masres = MiddleOfElem (A, masres, n);
        OutputMas(outp, masres, n);
    }
    else
    {
        fprintf(outp, "В матрице А есть элементы абсолютная величина которых отличается от  Р меньше чем на Е.\n" );
    }

    FreeMatrix(A, n);
    FreeMas(masres, n);

    fclose(inp);
    fclose(outp);
}
