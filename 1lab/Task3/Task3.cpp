#include <time.h>
#include <stdio.h>
#include <Windows.h>
#include <cstdlib>
#include <math.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    signed char res_asm;
    int Nom;
    printf("Оберіть номер завдання від а(1) до е(6): "); scanf_s("%d", &Nom);
    printf("\n");

    switch (Nom)
    {
    case 1:
    {
        printf("%d) 5 + 127\n", Nom);
        __asm
        {
            mov al, 5;
            mov bl, 127;
            add al, bl;
            mov cl, al;
            mov res_asm, cl;
        }
        printf("%d", res_asm);
        printf("\nПереповнення біту!");
        break;
    }
    case 2:
    {
        printf("%d) 2-3\n", Nom);
        __asm
        {
            mov al, 2;
            mov bl, 3;
            sub al, bl;
            mov cl, al;
            mov res_asm, cl;
        }
        printf("%d", res_asm);
        break;
    }
    case 3:
    {
        printf("%d) -120-34\n", Nom);
        __asm
        {
            mov al, -120;
            mov bl, 34;
            sub al, bl;
            mov cl, al;
            mov res_asm, cl;
        }
        printf("%d", res_asm);
        printf("\nПереповнення біту!");
        break;
    }
    case 4:
    {
        printf("%d) (unsigned char(0-255)) (- 5)\n", Nom);
        int x;
        int y = (-5);
        printf("Введіть x:");
        scanf_s("%d", &x);
        if (x > y)
        {
            printf("%d < %d", y, x);
        }
        else
            printf("%d > %d", y, x);
        break;
    }
    case 5:
    {
        printf("%d) 56 & 38\n", Nom);
        int x = 56, y = 38;
        if (x > y)
        {
            printf("%d > %d", x, y);
        }
        else
            printf("%d < %d", x, y);
        break;
    }
    case 6:
    {
        printf("%d) 56 | 38\n", Nom);
        int x = 56, y = 38;
        if (x > y)
        {
            printf("%d", x);
        }
        else
            printf("%d", y);
        break;
    }
    }
}
