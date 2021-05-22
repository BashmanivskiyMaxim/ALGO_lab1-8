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

struct List {
    int info;
    List* pred, * next;
};

// Вставка елемента в двузв'язний список після останнього елемента
List* InsertElementInList(List* last, List* p)
{
    if (last && p)
    {
        p->pred = last;
        p->next = last->next;
        last->next = p;
        p->next->pred = p;
        return p; // Повертається адреса елемента
    }
    else
        return NULL;
}
//Створення списку та запис елементів
void CreateList(List*& head, List*& tail)
{
    head = new List;
    tail = new List;
    head->next = tail;
    tail->pred = head;
    int k;
    List* last = head;
    for (int count = 0; count < 40000; ++count)
    {
        k = rand();
        List* p = new List;
        p->info = k;
        last = InsertElementInList(last, p);       
    }
    return;
}

void PrintList(List* head, List* tail) // вивід списку
{
    List* p = head->next;
    while (p != tail)
    {
        cout << "\t" << p->info;
        p = p->next;
    }
    cout << endl;
    return;
}


void SortListVYB(List*& head, List*& tail) 
{
   
    List* last = tail;
    
    tail->next = head;
    head->pred = tail;
    while (head->next != tail) // поки залишились елементи шукаємо мінімальний та видаляємо
    {                   
        List* min = head->next, * p = head->next;
        while (p != tail)
        {
            if (p->info < min->info)
                min = p;
            p = p->next;
        }
        
        min->next->pred = min->pred; //видалення min елемента із списку
        min->pred->next = min->next;

        last = InsertElementInList(last, min); // додаємо найдений елемент
    }
    swap(head, tail);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    auto begin = GETTIME();
    
    auto end = GETTIME();
    srand(time(NULL));

    List* head, * tail = NULL;
    CreateList(head, tail);
    cout << "\nСписок\n" << endl;
    PrintList(head, tail);
    cout << "\nВідсортований список\n" << endl;
    SortListVYB(head, tail);
    PrintList(head, tail);
    

    auto elapsed_ns = CALCTIME(end - begin);
    printf("The time: %lld ns\n", elapsed_ns.count());
}

