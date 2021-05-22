#include <iostream>
#include "Windows.h"
#include "stdio.h"
#include "math.h"
#define N 30000
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    unsigned int x0, a = 16807, c = 0, k = 30000;
    int arr[N], arr1[250];
    float x = 1;
    int m = (pow(2, 31) - 1);
    printf("Введіть початкове значеня x:");
    scanf_s("%d", &x0);
    for (int i = 0; i < k; i++)
    {
        x0 = (x0 * a + c) % m;
        x = ((float)x0 / m * 200);
        arr[i] = x;
        printf(" %d", arr[i]);
    }
    printf("\n");
    printf("\nЧастота інтервалів появи випадкових величин:\n");
    int f = 0, g = 0;
    float arr2[200];
    for (int h = 0; h < 200; h++)
    {
        for (int i = 0; i < k; i++)
        {
            if (arr[i] == h)
                f++;
        }
        printf("  (%d) | %d\n", h, f);
        arr1[h] = f;
        f = 0;
    }
    printf("\n");
    printf("Статистична ймовірність появи випадкових величин:\n");
    for (int h = 0; h < 200; h++)
    {
        for (int i = 0; i < k; i++)
        {
            if (arr[i] == h)
                g++;
        }
        printf("  %d | %lf\n", h, (float)g / 30000);
        arr2[h] = (float)g / 30000;
        g = 0;
    }
    double  Expvalue = 0;
    for (int i = 0; i < 200; i++)
    {
        Expvalue += arr[i] * arr2[i];
    }
    printf("\n");
    printf("Математичне сподівання появи випадкових величин: %lf\n", Expvalue);
    double variance = 0;
    for (int i = 0; i < k; i++)
    {
        variance += pow(arr[i] - Expvalue, 2) * arr[i];
    }
    printf("Дисперсія випадкових велечин: %lf\n", variance);
    double deviation = 0;
    deviation = sqrt(variance);
    printf("Середньоквадратичне відхілення випадкової велечини: %lf\n", deviation);
}
