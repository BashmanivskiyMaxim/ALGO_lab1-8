#include <stdio.h>
#include <iostream>
#include "windows.h"
#include "stdlib.h"
#include "time.h"
#include <ctime>
#include <cstdlib>
#include "math.h"
#include <chrono>
#define MAX_SIZE 10000

#define GETTIME std::chrono::steady_clock::now
#define CALCTIME std::chrono::duration_cast<std::chrono::nanoseconds>

void InsertSort(int* array, int size)
{
    int c;
    for (int i = 1; i < size; i++) //Проходимо по масиву знаходячи мінімальний елемент , вставляємо його у відсортовану частину
    {
        c = array[i];
        for (int j = i - 1; j >= 0 && array[j] > c; j--)
        {
            array[j + 1] = array[j];
            array[j] = c;
        }
    }

}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    auto begin = GETTIME();
    auto end = GETTIME();
    srand(time(NULL));




    int array[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        array[i] = rand();
    }
    InsertSort(array, MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++)
    {
        printf("%d ", array[i]);
    }

    auto elapsed_ns = CALCTIME(end - begin);
    printf("The time: %lld ns\n", elapsed_ns.count());
    return 0;
}

