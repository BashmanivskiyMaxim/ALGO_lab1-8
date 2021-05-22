#ifndef _CLIST_H_
#define _CLIST_H_

#include <stdlib.h>
#include <stdbool.h>

typedef int elemtype;       // ��� �������� ������

struct elem {
    elemtype* value;        // �������� ����������
    struct elem* next;      // ������ �� ��������� ������� ������
    struct elem* prev;      // ������ �� ���������� ������� ������
};

struct myList {
    struct elem* head;      // ������ ������� ������
    struct elem* tail;      // ��������� ������� ������
    int size;            // ���������� ��������� � ������
};

typedef struct elem cNode;
typedef struct myList cList;

cList* createList(void);                                  // ��������� ������
void deleteList(cList* list);                             // ��������� ������
bool isEmptyList(cList* list);                            // �������� �� ������� 
int pushFront(cList* list, elemtype* data);               //������� �������� 
int popFront(cList* list, elemtype* data);                //��������� ������� ��������
int pushBack(cList* list, elemtype* data);                // ������� � ����
int popBack(cList* list, elemtype* data);                 // ��������� �������� � ����
cNode* getNode(cList* list, int index);                   // ��������� ��������
void printList(cList* list, void (*fun)(elemtype*));      // ���� ������
int insertNode(cList* list, size_t index, elemtype* data);// ��������� �������� �� �������
int deleteNode(cList* list, size_t index);                // ��������� �� �������

#endif  //_CLIST_H_
