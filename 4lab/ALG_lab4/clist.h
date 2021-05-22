#ifndef _CLIST_H_
#define _CLIST_H_

#include <stdlib.h>
#include <stdbool.h>

typedef int elemtype;       // Тип элемента списка

struct elem {
    elemtype* value;        // Значение переменной
    struct elem* next;      // Ссылка на следующий элемент списка
    struct elem* prev;      // Ссылка на предыдущий элемент списка
};

struct myList {
    struct elem* head;      // Первый элемент списка
    struct elem* tail;      // Последний элемент списка
    int size;            // Количество элементов в списке
};

typedef struct elem cNode;
typedef struct myList cList;

cList* createList(void);                                  // створення списку
void deleteList(cList* list);                             // видалення списку
bool isEmptyList(cList* list);                            // перевірка на пустоту 
int pushFront(cList* list, elemtype* data);               //елемент спочатку 
int popFront(cList* list, elemtype* data);                //видалення першого елемента
int pushBack(cList* list, elemtype* data);                // елемент в кінці
int popBack(cList* list, elemtype* data);                 // видалення елементу в кінці
cNode* getNode(cList* list, int index);                   // отримання елементу
void printList(cList* list, void (*fun)(elemtype*));      // вивід списку
int insertNode(cList* list, size_t index, elemtype* data);// додавання елементу по індексу
int deleteNode(cList* list, size_t index);                // видалення по індексу

#endif  //_CLIST_H_
