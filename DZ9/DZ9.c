#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
 
int main()
{
    char simv;
    int a, b, c;
    int prodolzhit;
    double x0, h, t, levo, pravo;
    int strok, i, j, sdvig, nachalo, konec;
 
    setlocale(LC_ALL, "Rus");
 
    do
    {
        printf("Введите символ из которого будет строиться фигура:\n");
        scanf(" %c", &simv);
        printf("Введите сторону a:\n");
        scanf("%d", &a);
        printf("Введите сторону b:\n");
        scanf("%d", &b);
        printf("Введите сторону c:\n");
        scanf("%d", &c);
 
        if (a < b + c && a > abs(b - c))
        {
            printf("Треугольник:\n\n");
 
            x0 = (c * c + a * a - b * b) / (2.0 * a);
            h = sqrt(c * c - x0 * x0);
            strok = (int)(h + 0.5);
            if (strok < 1)
                strok = 1;
            sdvig = 0;
            if (x0 < 0)
                sdvig = (int)floor(-x0 + 0.5);
 
            for (i = 0; i <= strok; i++)
            {
                t = (double)i / strok;
                levo = x0 * (1 - t);
                pravo = x0 + t * (a - x0);
                nachalo = (int)floor(levo + 0.5) + sdvig;
                konec = (int)floor(pravo + 0.5) + sdvig;
                if (konec <= nachalo)
                    konec = nachalo + 1;
 
                for (j = 0; j < nachalo; j++)
                    putchar(' ');
                for (j = nachalo; j < konec; j++)
                    putchar(simv);
                printf("\n");
            }
        }
        else
            printf("Треугольник с такими сторонами не существует!\n");
 
        prodolzhit = 0;
        printf("\nПродолжить ? (Да - введите любое число, Нет - введите 0)\n");
        scanf("%d", &prodolzhit);
    } while (prodolzhit != 0);
 
    return 0;
}
