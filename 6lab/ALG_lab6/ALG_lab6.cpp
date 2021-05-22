#include <iostream>
#include <stdio.h>
#include "windows.h"
#include "stdlib.h"
#include "time.h"
#include <ctime>
#include <cstdlib>
#include "math.h"
#define MAX_SIZE 50000
#include <chrono>
#include <random>
#define GETTIME std::chrono::steady_clock::now
#define CALCTIME std::chrono::duration_cast<std::chrono::nanoseconds>

int increment(long inc[], long size) {
    // inc[] массив, в который заносятся инкременты
    // size размерность этого массива
    int p1, p2, p3, s;

    p1 = p2 = p3 = 1;
    s = -1;
    do {// заполняем массив элементов по формуле Роберта Седжвика
        if (++s % 2) {
            inc[s] = 8 * p1 - 6 * p2 + 1;
        }
        else {
            inc[s] = 9 * p1 - 9 * p3 + 1;
            p2 *= 2;
            p3 *= 2;
        }
        p1 *= 2;
        // заполняем массив, пока текущая инкремента хотя бы в 3 раза меньше количества элементов в массиве
    } while (3 * inc[s] < size);

    return s > 0 ? --s : 0;// возвращаем количество элементов в массиве
}

template<class T>
void shellSort(T a[], long size) {
    // inc инкремент, расстояние между элементами сравнения
    // i и j стандартные переменные цикла
    // seq[40] массив, в котором хранятся инкременты
    long inc, i, j, seq[40];
    int s;//количество элементов в массиве seq[40]

    // вычисление последовательности приращений
    s = increment(seq, size);
    while (s >= 0) {
        //извлекаем из массива очередную инкременту
        inc = seq[s--];
        // сортировка вставками с инкрементами inc
        for (i = inc; i < size; i++) {
            T temp = a[i];
            // сдвигаем элементы до тех пор, пока не дойдем до конца или не упорядочим в нужном порядке
            for (j = i - inc; (j >= 0) && (a[j] > temp); j -= inc)
                a[j + inc] = a[j];
            // после всех сдвигов ставим на место j+inc элемент, который находился на i месте
            a[j + inc] = temp;
        }
    }
}




int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    auto begin = GETTIME();

    
    srand(time(0));

    double array[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        array[i] = (double)(rand()) / RAND_MAX * (300 - 0) + 0;
    }
    shellSort(array, MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++)
    {
        printf(" %.2lf ", array[i]);
    }
    auto end = GETTIME();
    auto elapsed_ns = CALCTIME(end - begin);
    printf("\nThe time: %lld ns\n", elapsed_ns.count());

}

