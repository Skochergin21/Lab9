#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

#define ROW 9
#define COL 9

int main()
{
    int row, col;
    int i, j;
    long long chislo, kopiya;
    int poslednyaya, cifra, skolko;
    char otvet;

    setlocale(LC_ALL, "Rus");

    printf("=== Задание 1 ===\n");
    printf("Таблица Пифагора:\n");
    for (row = 1; row <= ROW; ++row)
    {
        for (col = 1; col <= COL; col++)
            printf("%5d", col * row);
        printf("\n");
    }

    printf("\nЛевый нижний треугольник таблицы Пифагора:\n");
    for (row = 1; row <= ROW; ++row)
    {
        for (col = 1; col <= row; col++)
            printf("%5d", col * row);
        printf("\n");
    }

    printf("\nПолная таблица сложения:\n");
    for (j = 1; j <= 9; j++)
    {
        for (i = 1; i <= 9; i++)
            printf("%d + %d = %-2d   ", i, j, i + j);
        printf("\n");
    }

    printf("\n=== Задание 2 ===\n");
    do
    {
        printf("Введите число: ");
        scanf("%lld", &chislo);
        if (chislo < 0)
            chislo = -chislo;

        kopiya = chislo;
        poslednyaya = chislo % 10;
        skolko = 0;

        printf("Цифры числа с конца: ");
        do
        {
            cifra = kopiya % 10;
            printf("%d ", cifra);
            if (cifra == poslednyaya)
                skolko++;
            kopiya = kopiya / 10;
        } while (kopiya > 0);

        printf("\nПоследняя цифра %d, количество ее повторений в числе: %d\n", poslednyaya, skolko);

        printf("Продолжить? (Да - y, нет - n): ");
        scanf(" %c", &otvet);
    } while (otvet != 'n');

    return 0;
}
