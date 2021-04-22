#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>

int** GetMemMatrix( int n);
void InputMatrix(FILE *inp, int  **matrix, int n);
void OutputMatrix(FILE *outp, int  **matrix, int n);
bool FindMatrix(int **matrix, int n, int P, int E);
float * MiddleOfElem (int **Matrix, float *masres, int n);
void FreeMatrix(int **matrix, int n);

float * GetMemMas(int n);
void OutputMas (FILE *outp, float *masres, int n);
void FreeMas(float * masres, int n);
