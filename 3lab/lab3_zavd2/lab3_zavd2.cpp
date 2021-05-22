#include<stdio.h>
#include<windows.h>
#include <iostream>
#include <chrono>
#include <math.h>
#define GETTIME std::chrono::steady_clock:: now
#define CALCTIME std::chrono::duration_cast<std::chrono::nanoseconds>

int main()
{
	auto begin = GETTIME();	
	printf("Послідовність Фібоначчі : \n0\n1");
	unsigned long a1 = 0, a2 = 1, temp;
	for (int n = 2; n <= 60; n++)
	{
		temp = a2;
		a2 = a1 + a2;
		a1 = temp;
		printf(" \n%lu", a2);
	}


	auto end = GETTIME();
	auto elapsed_ns = CALCTIME(end - begin);
	printf("\nThe time: %lld ns\n", elapsed_ns.count());
}
