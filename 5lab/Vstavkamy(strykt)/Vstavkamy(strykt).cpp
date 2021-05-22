#include <iostream>
#include <iomanip>
#include <locale.h>
#include "windows.h"
#include <cstdlib>
#include <iostream>
#include <chrono>
#define GETTIME std::chrono::steady_clock::now
#define CALCTIME std::chrono::duration_cast<std::chrono::nanoseconds>

using namespace std;

struct List
{
    List() : Next(nullptr), Prev(nullptr) {}
    int info;
    List* Next, * Prev;
};

// Функция сортирует список методом вставки
void InsertionSort(List* head)
{

    List* curr = nullptr, * prev = nullptr;
    for (curr = head->Next; curr->Next; curr = curr->Next)
    {
        int tmp = curr->info;
        for (prev = curr->Prev; prev && prev->info > tmp; prev = prev->Prev)
        {
            prev->Next->info = prev->info;
        }
        prev->Next->info = tmp;
    }
}


// Функция вставляет элемент p после элемента last
// возвращает адрес на вставленный в список элемент
List* InsertElementIntoList(List* last, List* p)
{
    if (last != NULL || p != NULL)
    {
        p->Prev = last;
        p->Next = last->Next;
        last->Next = p;
        p->Next->Prev = p;
        return p;
    }
    else
        return NULL;
}

// Функция создает двусвязный список из n элементов
// через head и tail возвращает указатели головного и хвостового сторожей
void CreateRandomList(List*& head, List*& tail, int n)
{
    head = new List;
    tail = new List;

    head->Next = tail;
    tail->Prev = head;

    srand(time(NULL));

    List* last; // Последний вставленный элемент в список
    last = head;

    for (int i = 0; i < n; i++)
    {
        List* p = new List;
        p->info = rand();
        last = InsertElementIntoList(last, p);
    }
}

// Функция выводит список на экран
void PrintList(List* head, List* tail)
{
    List* p = head->Next;
    while (p != tail)
    {
        cout << "\t" << p->info;
        p = p->Next;
    }
    cout << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    auto begin = GETTIME();

    auto end = GETTIME();
    srand(time(NULL));

    List* head, * tail;
    CreateRandomList(head, tail, 10000);
    cout << "Исходный список: \n";
    PrintList(head, tail);

    InsertionSort(head);
    cout << "Отсортированный список: \n";
    PrintList(head, tail);

    auto elapsed_ns = CALCTIME(end - begin);
    printf("The time: %lld ns\n", elapsed_ns.count());
    return 0;
}