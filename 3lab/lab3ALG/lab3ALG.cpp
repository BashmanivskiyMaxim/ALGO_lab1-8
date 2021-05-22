#include<stdio.h>
#include<windows.h>
#include <iostream>
#include <chrono>
#include <math.h>
#define GETTIME std::chrono::steady_clock:: now
#define CALCTIME std::chrono::duration_cast<std::chrono::nanoseconds>

unsigned __int64 factorial(int count)
{
	unsigned __int64 vlfct = 1;
	for (int i = 1; i <= count; i++)
		vlfct = vlfct * i;
	return vlfct;
}
void func_1()
{
	int y = 0;
	for (int x = 0; x <= 50; x++)
	{		
			y = x;
			printf("\ny = %d , x = %d", y, x);		
	}
}
void func_2()
{
	float y = 0;
	for (int x = 0; x <= 50; x++)
	{
		y = log(x);
		printf("\ny = %f , x = %d", y, x);
	}
}
void func_3()
{
	float y = 0;
	for (int x = 0; x <= 50; x++)
	{
		y = x * log(x);
		printf("\ny = %f , x = %d", y, x);
	}
}
void func_4()
{
	int y = 0;
	for (int x = 0; x <= 50; x++)
	{
		y = pow(x,2);
		printf("\ny = %d , x = %d", y, x);
	}
}
void func_5()
{
	long long int y = 0;
	for (int x = 0; x <= 50; x++)
	{
		y = pow(2, x);
		printf("\ny = %lld , x = %d", y, x);
	}
}
void func_6()
{
	unsigned __int64 y = 0;
	for (int x = 0; x <= 50; x++)
	{
		y = factorial(x);
		printf("\ny = %llu , x = %d", y, x);
	}
}
int main() 
{   
	auto begin = GETTIME();
	func_6();
	auto end = GETTIME();
	auto elapsed_ns = CALCTIME(end - begin);
	printf("\nThe time: %lld ns\n", elapsed_ns.count());
}