#include "matrix.h"

int ** GetMemMatrix(int n)
{
    int ** matrix = new int*[n];
    for(int i=0; i<n; i++) matrix[i] = new int[n];

    return matrix;
}

void InputMatrix(FILE *inp, int ** matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(inp, "%d", &matrix[i][j]);
        }
        fscanf(inp, "\n");
    }
}

void OutputMatrix(FILE *outp, int ** matrix, int n)
{
    fprintf(outp, "%s", "Matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(outp, "%4d", matrix[i][j]);
        }
        fprintf(outp, "\n");
    }
}

void FreeMatrix(int ** matrix, int n)
{
    for(int i=0;i<n;i++) delete [] matrix[i];
    delete [] matrix;
}

float * GetMemMas(int n)
{
    scanf("%d", n);
    float *mas = new float[n];
    return mas;
}

void OutputMas(FILE *outp, float *masres, int n)
{
    for (int i = 0; i < n; i++)
        fprintf(outp, "%d %c", masres[i], ' ');
}

void FreeMas(float* masres, int n)
{
    delete[] masres;
}

bool FindMatrix(int ** matrix, int n, int P, int E)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            if (abs(matrix[i][j] - P) < E) {
                break;
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}

float * MiddleOfElem (int ** matrix, float * masres, int n)
{
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            masres[i] += matrix[i][j];
            masres[i] /= n;
        }
    }
    return masres;
}
