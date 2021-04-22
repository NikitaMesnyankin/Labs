#include <stdio.h>  // printf, scanf
#include <conio.h>  // getch
#include <math.h>   // fabs, pow, ceil\floor, log, log10, exp, sqrt
#include <stdlib.h>  // randomize, rand
#include <windows.h> // SetConsoleOutputCP(1251); SetConsoleCP(1251);

//---------------------------------------------------------------------------
const double xx[5] = {-0.98, -0.5, 0.1, 0.5, 0.95};

int main()
{
    int n,i,k,z;
    double e, sl, sum, f, *x; // четыре простого типа и один – дин.массив(указатель)
    SetConsoleOutputCP(1251);

    printf("Enter e = ? "); // приглашение – шрифт Lucida Console нужен
    scanf("%lf", &e);  // ввод числа с плавающей точкой двойной точности(%lf) e
    if (e<1e-13 || e>0.11) {
        printf("Uncorrect precision of e (0..0.1] \nPress any key");
        getch(); // ожидание нажатия клавиши
        return 0;  // выход из функции main
    }
    fflush(stdin);  // очищаем буфер (лишние символы после ввода e)

    printf("Enter n = ? "); // приглашение
    scanf("%d", &n);  // ввод десятичного(%d) n
    if (n<1 || n>20) {
        printf("Invalid n [1..20]! \nPress any key");
        getch(); // ожидание нажатия клавиши
        return 0;  // выход из функции main
    }
    fflush(stdin);

    x = new double [n];  // выделяем память для n элементов массива

    printf("Enter n = %d values of X in (-1,+1):\n", n); // приглашение
    for (i = 0; i < n; i++) {     // ввод x[0]...x[n-1]
        scanf("%lf", &x[i]);       // типа long float (%lf)

        if (fabs(x[i])>=1) {
            x[i]=xx[rand() % 5]; // одно из семи значений массива xx
            if (fabs(x[i])==1) {
                x[i]=x[i]*(rand()%100) /100;
                if (x[i]==0) x[i]=e; // для некоторых вариантов x=/=0
            }
            printf("Uncorrect value replaced for %15.10lf\n", x[i]);
        }
    }


    z = ceil(fabs(log(e)/log(10.0)))+1;

    printf("e = %*.*lf\n", z+2, z, e); // вывод e:(z+2):z
    printf("N |        X        |      Sum(X)     | K|       F(X)      |  |Sum(X)-F(X)|\n");
    for (i=1; i < 80; i++) printf("="); printf("\n");
    for (i = 0; i < n; i++) {

        // поиск суммы ряда
        sum = sl = x[i] / 6;  // sl=pow(x[i],2); sum=sl;  // первое слагаемое
        k=1;
        while ((fabs(sl)>=e) && (k!=500)){
            sl*=-pow(x[i],2)/(2*k)/(2*k+1);
            sum+=sl;
            k++;
        };

        f= (x[i]-sin(x[i])) / (pow(x[i], 2));

        printf("%2d|%17.*lf|%17.*lf|%2d|%17.*lf|%17.*lf\n",
               i+1, z, x[i],  z, sum,  k,    z, f,   z+2, fabs(sum-f));
    }

    delete [] x; //  освобождение памяти для одномерного дин.массива

    printf("Press any key... ");
    getch();
    return 0;
}
