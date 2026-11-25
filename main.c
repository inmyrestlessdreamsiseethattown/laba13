#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define N 10

int main()
{
    setlocale(LC_ALL, "RUS");
    float A[N], B[N];
    float k;
    int i, v;

    printf("Введите элементы массива:\n");

    for (i = 0; i < N; i++)
    {
        printf("A[%d] = ", i + 1);
        scanf("%f", &A[i]);
        B[i] = A[i];
    }

    printf("\nВыберите вариант:\n");
    printf("1 - Удвоить каждый элемент\n");
    printf("2 - Увеличить каждый второй элемент на 1\n");
    printf("3 - Обнулить отрицательные элементы\n");
    printf("4 - Возвести элементы в квадрат\n");
    printf("5 - Уменьшить элементы в 10 раз\n");
    printf("6 - Изменить знак элементов\n");
    printf("7 - Уменьшить элементы на константу\n");
    printf("8 - Отбросить дробную часть\n");
    printf("9 - Заменить четные элементы на 1\n");
    printf("10 - Округлить в большую сторону\n");
    printf("11 - Прибавить последний элемент\n");
    printf("12 - Заменить нули порядковыми номерами\n");

    printf("\nВведите номер варианта: ");
    scanf("%d", &v);

    switch (v)
    {
    case 1:
        for (i = 0; i < N; i++)
            B[i] = A[i] * 2;
        break;

    case 2:
        for (i = 1; i < N; i = i + 2)
            B[i] = A[i] + 1;
        break;

    case 3:
        for (i = 0; i < N; i++)
            if (A[i] < 0)
                B[i] = 0;
        break;

    case 4:
        for (i = 0; i < N; i++)
            B[i] = A[i] * A[i];
        break;

    case 5:
        for (i = 0; i < N; i++)
            B[i] = A[i] / 10;
        break;

    case 6:
        for (i = 0; i < N; i++)
            B[i] = -A[i];
        break;

    case 7:
        printf("Введите константу: ");
        scanf("%f", &k);

        for (i = 0; i < N; i++)
            B[i] = A[i] - k;
        break;

    case 8:
        for (i = 0; i < N; i++)
            B[i] = (int)A[i];
        break;

    case 9:
        for (i = 0; i < N; i++)
            if (A[i] == (int)A[i] && (int)A[i] % 2 == 0)
                B[i] = 1;
        break;

    case 10:
        for (i = 0; i < N; i++)
        {
            B[i] = (int)A[i];

            if (A[i] > B[i])
                B[i] = B[i] + 1;
        }
        break;

    case 11:
        for (i = 0; i < N; i++)
            B[i] = A[i] + A[N - 1];
        break;

    case 12:
        for (i = 0; i < N; i++)
            if (A[i] == 0)
                B[i] = i + 1;
        break;

    default:
        printf("Ошибка! Такого варианта нет.\n");
        return 0;
    }

    printf("\nРезультаты:\n\n");

    printf("%-12s %-20s %-20s\n",
        "Индекс", "Исходное значение", "Новое значение");

    printf("------------------------------------------------------\n");

    for (i = 0; i < N; i++)
    {
        printf("%-12d %-20.2f %-20.2f\n",
            i + 1, A[i], B[i]);
    }

    printf("------------------------------------------------------\n");

    printf("\nПрограмма завершена.\n");

    return 0;
}
