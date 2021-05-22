#include<stdio.h>
#include<windows.h>

union data {
    float num;
    struct {
        unsigned char b0 : 1;
        unsigned char b1 : 1;
        unsigned char b2 : 1;
        unsigned char b3 : 1;
        unsigned char b4 : 1;
        unsigned char b5 : 1;
        unsigned char b6 : 1;
        unsigned char b7 : 1;
        unsigned char b8 : 1;
        unsigned char b9 : 1;
        unsigned char b10 : 1;
        unsigned char b11 : 1;
        unsigned char b12 : 1;
        unsigned char b13 : 1;
        unsigned char b14 : 1;
        unsigned char b15 : 1;
        unsigned char b16 : 1;
        unsigned char b17 : 1;
        unsigned char b18 : 1;
        unsigned char b19 : 1;
        unsigned char b20 : 1;
        unsigned char b21 : 1;
        unsigned char b22 : 1;
        unsigned char b23 : 1;
        unsigned char b24 : 1;
        unsigned char b25 : 1;
        unsigned char b26 : 1;
        unsigned char b27 : 1;
        unsigned char b28 : 1;
        unsigned char b29 : 1;
        unsigned char b30 : 1;
        unsigned char b31 : 1;
    } bits;

    struct {
        unsigned char byte0;
        unsigned char byte1;
        unsigned char byte2;
        unsigned char byte3;
    } bytes;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    data number;
    printf("Введіть число: "); scanf_s("%f", &number.num);
    printf("\nВведене число типу float в десятковій системі: number = %f\n", number.num);
    printf("\nВведене число в двійковій системі: number = %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d\n", number.bits.b31, number.bits.b30, number.bits.b29, number.bits.b28, number.bits.b27, number.bits.b26, number.bits.b25, number.bits.b24, number.bits.b23, number.bits.b22, number.bits.b21, number.bits.b20, number.bits.b19, number.bits.b18, number.bits.b17, number.bits.b16, number.bits.b15, number.bits.b14, number.bits.b13, number.bits.b12, number.bits.b11, number.bits.b10, number.bits.b9, number.bits.b8, number.bits.b7, number.bits.b6, number.bits.b5, number.bits.b4, number.bits.b3, number.bits.b2, number.bits.b1, number.bits.b0);
    printf("\nВведене число в шістнадцятковій системі: number = 0x%x%x%x%x\n", number.bytes.byte3, number.bytes.byte2, number.bytes.byte1, number.bytes.byte0);
    if (number.bits.b31 == 0)
        printf("\nЗнак числа: +.\n");
    else
        printf("\nЗнак числа: -.\n");
    printf("\nМантиса: %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d\n", number.bits.b22, number.bits.b21, number.bits.b20, number.bits.b19, number.bits.b18, number.bits.b17, number.bits.b16, number.bits.b15, number.bits.b14, number.bits.b13, number.bits.b12, number.bits.b11, number.bits.b10, number.bits.b9, number.bits.b8, number.bits.b7, number.bits.b6, number.bits.b5, number.bits.b4, number.bits.b3, number.bits.b2, number.bits.b1, number.bits.b0);
    printf("\nСтупінь числа: %d%d%d%d %d%d%d%d\n", number.bits.b30, number.bits.b29, number.bits.b28, number.bits.b27, number.bits.b26, number.bits.b25, number.bits.b24, number.bits.b23);
    printf("\nОбсяг пам'яті, яку займає змінна %d біта\n", sizeof(number));

    return 0;
}
