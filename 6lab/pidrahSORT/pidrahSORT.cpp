#include <iostream>
#include <time.h>

#define N 100000
using namespace std;

void CountingSort(short mass[], int n)
{
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < n; i++) { // Пошук максимального та мінімального елемента , для скорочення додвткового масиву
        if (mass[i] > max)
            max = mass[i];
        if (mass[i] < min)
            min = mass[i];
    }
    int* c = new int[max + 1 - min]; // Додатковий масив , потрібен для збереження кількості зустрічаємих елементів в масиві mass
    for (int i = 0; i < max + 1 - min; i++) {
        c[i] = 0; // заповнюємо 0 
    }
    for (int i = 0; i < n; i++) {
        c[mass[i] - min] = c[mass[i] - min] + 1;
    }
    int i = 0;
    for (int j = min; j < max + 1; j++) 
    {
        while (c[j - min] != 0) 
        {
            mass[i] = j;
            c[j - min]--;
            i++;
        }
    }
}

int main()
{
    srand(time(NULL));

    short mass[N];

    for (int i = 0; i < N; i++)
    {
        mass[i] = -200 + rand() % (10 - (-200) + 1);
        printf(" %d ", mass[i]);
    }

    printf("\n\n\n\n\n");
    CountingSort(mass, N);

    for (int i = 0; i < N; i++)
    {

        printf(" %d ", mass[i]);
    }

    return 0;
}