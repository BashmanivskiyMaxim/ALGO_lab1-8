#include "clist.h"

// Создание пустого списка
cList* createList(void) {
    cList* list = (cList*)malloc(sizeof(cList));
    if (list) {
        list->size = 0;
        list->head = list->tail = NULL;
    }
    return list;
}

// Удаление списка
void deleteList(cList* list) {
    cNode* head = list->head;
    cNode* next = NULL;
    while (head) {
        next = head->next;
        free(head);
        head = next;
    }
    free(list);
    list = NULL;
}

// Проверка списка на пустоту
bool isEmptyList(cList* list) {
    return ((list->head == NULL) || (list->tail == NULL));
}

// Добавление нового узла в начало списка
int pushFront(cList* list, elemtype* data) {
    cNode* node = (cNode*)malloc(sizeof(cNode));
    if (!node) {
        return(-1);
    }
    node->value = data;
    node->next = list->head;
    node->prev = NULL;

    if (!isEmptyList(list)) {
        list->head->prev = node;
    }
    else {
        list->tail = node;
    }
    list->head = node;

    list->size++;
    return(0);
}

// Извлечение узла из начала списка
int popFront(cList* list, elemtype* data) {
    cNode* node;

    if (isEmptyList(list)) {
        return(-2);
    }

    node = list->head;
    list->head = list->head->next;

    if (!isEmptyList(list)) {
        list->head->prev = NULL;
    }
    else {
        list->tail = NULL;
    }

    data = node->value;
    list->size--;
    free(node);

    return(0);
}

// Добавление нового узла в конец списка
int pushBack(cList* list, elemtype* data) {
    cNode* node = (cNode*)malloc(sizeof(cNode));
    if (!node) {
        return(-3);
    }

    node->value = data;
    node->next = NULL;
    node->prev = list->tail;
    if (!isEmptyList(list)) {
        list->tail->next = node;
    }
    else {
        list->head = node;
    }
    list->tail = node;

    list->size++;
    return(0);
}

// Извлечение узла из конца списка
int popBack(cList* list, elemtype* data) {
    cNode* node = NULL;

    if (isEmptyList(list)) {
        return(-4);
    }

    node = list->tail;
    list->tail = list->tail->prev;
    if (!isEmptyList(list)) {
        list->tail->next = NULL;
    }
    else {
        list->head = NULL;
    }

    data = node->value;
    list->size--;
    free(node);

    return(0);
}

// Чтение произвольного узла списка
cNode* getNode(cList* list, int index) 
{
    cNode* node = NULL;
    int i;

    if (index >= list->size) {
        return (NULL);
    }

    if (index < list->size / 2) {
        i = 0;
        node = list->head;
        while (node && i < index) {
            node = node->next;
            i++;
        }
    }
    else {
        i = list->size - 1;
        node = list->tail;
        while (node && i > index) {
            node = node->prev;
            i--;
        }
    }

    return node;
}

// Вывод списка в консоль
void printList(cList* list, void (*func)(elemtype*)) {
    cNode* node = list->head;

    if (isEmptyList(list)) {
        return;
    }

    while (node) {
        func(node->value);
        node = node->next;
    }
}
//Добавить узел
int insertNode(cList* list, size_t index, elemtype* data)
{
    if (index == 0) {
        pushFront(list, data);
        return(0);
    }
    cNode* node = getNode(list, index - 1); // елемент після якого потрібно вставити вузол
    cNode* insertNode = (cNode*)malloc(sizeof(cNode)); // виділення пам'яті під вузол
    if (!node) {
        return(-5);
    }
    if (!insertNode) {
        return(-6);
    }
    insertNode->value = data; // присвоюю значення через показник
    insertNode->prev = node;
    insertNode->next = node->next; //вставляю новий елемент
    if (node->next) {
        node->next->prev = insertNode;
    }
    node->next = insertNode;
    if (!node->prev) {
        list->head = node;
    }
    if (!node->next) {
        list->tail = node;
    }
    list->size++; //збільшую розмірність
    return(0);
}
// Видалення вузла за індексом з списку
int deleteNode(cList* list, size_t index) {
    cNode* node = getNode(list, index); // знаходжу елемент який потрібно видалити
    if (!node) {
        return(-7);
    }
    if (node->prev) {
        node->prev->next = node->next; // змінюю порядок елементів
    }
    if (node->next) {
        node->next->prev = node->prev;
    }
    if (!node->prev) {
        list->head = node->next;
    }
    if (!node->next) {
        list->tail = node->prev;
    }
    free(node); // звільняю пам'ять цього вузла
    list->size--;
    return(0);
}
