#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

union num {
    struct n {
        unsigned short a0 : 1;
        unsigned short a1 : 1;
        unsigned short a2 : 1;
        unsigned short a3 : 1;
        unsigned short a4 : 1;
        unsigned short a5 : 1;
        unsigned short a6 : 1;
        unsigned short a7 : 1;
        unsigned short a8 : 1;
        unsigned short a9 : 1;
        unsigned short a10 : 1;
        unsigned short a11 : 1;
        unsigned short a12 : 1;
        unsigned short a13 : 1;
        unsigned short a14 : 1;
        unsigned short a15 : 1;
    }numer;
    signed short count;
}num1;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    puts("Введіть число: ");
    scanf_s("%hd", &num1);
    if (num1.count == 0)
    {
        printf("Значення заданого числа: ");
        printf("%d\n", num1.count);
        exit(0);
    }
    if (num1.numer.a15 == 0) puts("Знак числа +");
    else if (num1.numer.a15 == 1) puts("Знак числа -");
    printf("Значення заданого числа: ");
    printf("%d\n", num1.count);
}
