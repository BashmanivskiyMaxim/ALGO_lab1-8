#include<stdio.h>
#include<windows.h>
#include <iostream>
#include <chrono>
#include <math.h>
#define GETTIME std::chrono::steady_clock:: now
#define CALCTIME std::chrono::duration_cast<std::chrono::nanoseconds>
#define MAX_SIZE 8000
void bubbleSort(double* array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = (size - 1); j > i; j--)
		{
			if (array[j - 1] < array[j])
			{
				double temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
			}
		}
	}
}


int main()
{
	auto begin = GETTIME();
	srand(time(0));
	double array[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
	{
		array[i] = rand() + (rand() % RAND_MAX) / 1000.0;
	}
	bubbleSort(array, MAX_SIZE);
	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("%f ", array[i]);
	}
	auto end = GETTIME();
	auto elapsed_ns = CALCTIME(end - begin);
	printf("\nThe time: %lld ns\n", elapsed_ns.count());
}