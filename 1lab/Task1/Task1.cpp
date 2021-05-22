#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

struct date
{
	unsigned short Rik : 5;
	unsigned short Mis : 4;
	unsigned short Tyzhd : 3;
	unsigned short Den : 5;
	unsigned short Godyn : 5;
	unsigned short Hvyl : 6;
	unsigned short Sec : 6;
};
int main()
{
	date a;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	a.Rik = 21;
	a.Mis = 6;
	a.Tyzhd = 4;
	a.Den = 31;
	a.Godyn = 21;
	a.Hvyl = 45;
	a.Sec = 56;
	printf("%d.%d.%d %d:%d:%d |%d|", a.Den, a.Mis, a.Rik, a.Godyn, a.Hvyl, a.Sec, a.Tyzhd);
	int k, g;
	k = sizeof(date);
	g = sizeof(tm);
	printf("\nsizeof(date) = %d", k);
	printf("\nsizeof(tm) = %d", g);

}
