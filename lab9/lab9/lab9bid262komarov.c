#define _CRT_SECURE_NO_DEPRECATE
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, ".UTF8");
    int choice;
    char repeat;

    // Главный цикл do-while для повторения программы
    do {
        printf("\n=========================================\n");
        printf("ЛАБОРАТОРНАЯ РАБОТА 9 (Вариант 10)\n");
        printf("=========================================\n");
        printf("1. Задание 1.1-1.2: Таблица Пифагора (полная и треугольная)\n");
        printf("2. Задание 1.3: Печать чисел по варианту 10\n");
        printf("3. Задание 2: Анализ числа (рядом расположенные одинаковые цифры)\n");
        printf("4. Задание 3: Рисование геометрической фигуры по варианту 10\n");
        printf("0. Выход\n");
        printf("Выберите задание (0-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода!\n");
            while (getchar() != '\n'); // Очистка буфера при ошибке
            continue;
        }

        switch (choice) {
        case 1: {
            printf("\n--- Полная таблица Пифагора ---\n");
            for (int i = 1; i <= 9; i++) {
                for (int j = 1; j <= 9; j++) {
                    printf("%4d", i * j);
                }
                printf("\n");
            }

            printf("\n--- Левый нижний треугольник таблицы Пифагора ---\n");
            for (int i = 1; i <= 9; i++) {
                for (int j = 1; j <= i; j++) {
                    printf("%4d", i * j);
                }
                printf("\n");
            }
            break;
        }

        case 2: {
            printf("\n--- Задание 1.3: Цифровой треугольник (Вариант 10) ---\n");
            int rows = 9;
            for (int i = 1; i <= rows; i++) {
                for (int j = 1; j <= i; j++) {
                    printf("%d ", i);
                }
                printf("\n");
            }
            break;
        }

        case 3: {
            int number; 
            printf("\n--- Задание 2: Поиск одинаковых цифр рядом ---\n");
            printf("Введите число: ");
            if (scanf("%d", &number) != 1) {
                printf("Некорректное число!\n");
                break;
            }

            // Работаем с абсолютным значением
            if (number < 0) {
                number = -number;
            }
            int temp = number;
            int prev_digit = -1;
            int current_digit;
            int identical_pairs_count = 0;

            printf("Анализ числа %d:\n", number);

            if (temp < 10) {
                printf("Число одноразрядное, соседних цифр нет.\n");
            }
            else {
                /*
                   Разложение числа на цифры (справа налево).
                   Сравниваем текущую цифру со следующей за ней (prev_digit).
                */
                while (temp > 0) {
                    current_digit = temp % 10;

                    if (prev_digit != -1) {
                        if (current_digit == prev_digit) {
                            printf("Найдена пара одинаковых соседних цифр: %d и %d\n", current_digit, prev_digit);
                            identical_pairs_count++;
                        }
                    }

                    prev_digit = current_digit;
                    temp /= 10;
                }
                printf("Всего рядом расположенных одинаковых цифр (пар): %d\n", identical_pairs_count);
            }
            break;
        }


              //DZ
        case 4: {
            int size;
            char symbol;
            printf("\n--- Задание 3: Рисование геометрической фигуры ---\n");
            printf("Введите символ для рисования: ");
            scanf(" %c", &symbol);
            printf("Введите размер фигуры (минимум 3): ");
            if (scanf("%d", &size) != 1 || size < 3) {
                printf("Некорректный размер!\n");
                break;
            }

            printf("\nРезультат:\n");
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    // Контур квадрата + главная и побочная диагонали
                    if (i == 0 || i == size - 1 || j == 0 || j == size - 1 || i == j || i + j == size - 1) {
                        printf("%c ", symbol);
                    }
                    else {
                        printf("  ");
                    }
                }
                printf("\n");
            }
            break;
        }

        case 0:
            printf("Выход из программы.\n");
            exit(0);

        default:
            printf("Неверный пункт меню!\n");
        }

        // Очистка буфера ввода перед опросом
        while (getchar() != '\n');

        printf("\nПродолжить работу с программой? (Да - 1, Нет - любое число): ");
        scanf("%d", &repeat);

    } while (repeat == 1);

    printf("Программа завершена.\n");
    return 0;
}