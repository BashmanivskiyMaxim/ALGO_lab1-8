#include <stdio.h>
#include <stdlib.h>
#include "clist.h"
#include "windows.h"
#define h 30
void printNode(elemtype* value) {
	printf("%d\n", *((int*)value));
}
int pushtoStack(int znach)
{
	int f;
	f = znach;
	return f;
}
int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	elemtype tmp;
	int g = 1;
	elemtype tmp1 = 0;
	elemtype tmp3;
	int tmp2;
	int menu;
	int mass[h];
	int mass1[h];
	int znach;
	int znach1;
	int j=0;
	int l = 0;

	cList* mylist = createList();
	do {
		printf("1.Додати елементи на початок списку\n2.Видалити елемент з кінця списку\n3.Додати елементи в кінець списку\n4.Видалити елемент спочатку\n5.Весь список\n6.Видалити список\n7.Створити список\n8.Додати елемент за індексом\n9.Видалити елемент за індексом\n10.Перевірка на пустоту списку\n0.Закрити програму\n");
		scanf_s("%d", &menu);
		switch (menu) 
		{
		case 1:printf("Введіть скільки значень ви хочете ввести:\n");
			scanf_s("%d", &g);
		
			for (int i = 0; i < g; i++)
			{
				printf("Введіть значення:\n");
				scanf_s("%d", &znach);
				mass[i] = znach;
				pushFront(mylist, &mass[i]);
			}
			break;
		case 2:popBack(mylist, &tmp);
			break;
		case 3:printf("Введіть скільки значень ви хочете ввести:\n");
			scanf_s("%d", &g);

			for (int i = 0; i < g; i++)
			{
				printf("Введіть значення:\n");
				scanf_s("%d", &znach1);
				mass1[i] = znach1;
				pushBack(mylist, &mass1[i]);
			}
			break;
		case 4:popFront(mylist, &tmp);
			break;
		case 5: 
			printList(mylist, printNode);
			break;
		case 6:deleteList(mylist); printf("Список видалено!\n");
			break;
		case 7: {cList* mylist = createList(); }
			break;
		case 8:printf("\nПісля якого елемента ви хочете ввести значення:");	scanf_s("%d", &j);
			   printf("\nВведіть значення:"); scanf_s("%d", &l);	insertNode(mylist, j, &l);
			break;
		case 9:printf("\nПісля якого елемента ви хочете видалити елемент:");scanf_s("%d", &j);
				deleteNode(mylist, j);
			break;
		case 10: if (isEmptyList(mylist) == true)
		{
			printf("\nСписок пустий!!!\n");
		}
		else printf("\nУ списку наявні елементи\n");			
			break;
		}
	} while (menu != 0);
	return 0;
}
