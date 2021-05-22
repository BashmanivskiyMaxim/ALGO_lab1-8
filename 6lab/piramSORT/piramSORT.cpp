#include <iostream>
#include <stdio.h>
#include "windows.h"
#include "stdlib.h"
#include "time.h"
#include <ctime>
#include <cstdlib>
#include "math.h"
#define MAX_SIZE 10000
#include <chrono>
#include <random>
#define GETTIME std::chrono::steady_clock::now
#define CALCTIME std::chrono::duration_cast<std::chrono::nanoseconds>
#define left_child(node) ( (node) * 2 + 1 ) // Лівий потомок
#define right_child(node) ( (node) * 2 + 2 ) // Правий потомок

void swap(int* array, int i, int j) // Функція для зміни порядку елементів , використовується в сортуванні
{
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

void heap_it(int* array, int length, int root) //Сортування кучі 
{
    int leftChild = left_child(root);
    int rightChild = right_child(root);
    int biggest = root;

    if (leftChild < length && array[root] < array[leftChild]) // Переміщення елементів вверх по кучі
        biggest = leftChild;
    if (rightChild < length && array[biggest] < array[rightChild]) // Переміщення елементів вверх по кучі
        biggest = rightChild;
    if (biggest != root) // якщо найбільший елемент не у верху кучі , переміщуємо у верх , знову виконуємо heap_it тільки вже з найбільшим елементом у верху.
    {
        swap(array, biggest, root);
        heap_it(array, length, biggest);
    }
}

void make_heap(int* array, int length) //Створення кучі
{
    int i = length / 2;

    for (; i >= 0; --i)
        heap_it(array, length, i);
}

void heap_sort(int* array, int count) //Загальний алгоритм сортування 
{
    int last;

    make_heap(array, count);
    for (last = count - 1; last > 0; --last) 
    {
        swap(array, 0, last);
        heap_it(array, last, 0);
    }
}

#define COUNT (1000)


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    auto begin = GETTIME();

    
    srand(time(0));
    int i;
    int array[COUNT];
    for (int f = 0; f < COUNT; f++)
    {
        array[f] = 0 + rand() % (100 + 1); // [0 ; 100]

    }
    
    printf("unSorted:\n");
    for (i = 0; i < COUNT; ++i)
        printf("%d ", array[i]);

    heap_sort(array, COUNT); //Сортування
    printf("\nSorted:\n");

    for (i = 0; i < COUNT; ++i)
        printf("%d ", array[i]);
    printf("\n");

    

    auto end = GETTIME();



    auto elapsed_ns = CALCTIME(end - begin);
    printf("The time: %lld ns\n", elapsed_ns.count());

}

