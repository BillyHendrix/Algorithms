#include <iostream>
#include <random>
#include <climits>
#include "array.h"

// функция для генерации случайного числа
int random_number(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);
    return distr(gen);
}

void task2(Array* arr)
{
    int max_sum = INT_MIN;
    // Calculate the initial sum of the first five elements
    int current_sum = array_get(arr, 0) + array_get(arr, 1) + array_get(arr, 2) + array_get(arr, 3) + array_get(arr, 4);
    size_t start_index = 0;

    for (size_t i = 0; i <= array_size(arr) - 5; ++i)
    {
        // Update the current sum by subtracting the first element of the previous sum and adding the next element in the array
        if (i != 0)
        {
            current_sum = current_sum - array_get(arr, i - 1) + array_get(arr, i + 4);
        }

        // If the current sum is greater than the max sum, update the max sum and start index
        if (current_sum > max_sum)
        {
            max_sum = current_sum;
            start_index = i;
        }
    }

    std::cout << "Five consecutive elements with the maximum sum: ";
    for (size_t i = start_index; i < start_index + 5; ++i)
    {
        std::cout << array_get(arr, i) << " ";
    }
    std::cout << std::endl;
}

void task1(Array* arr)
{
    // вывод исходного массива
    std::cout << "Исходный массив: ";
    for (size_t i = 0; i < array_size(arr); ++i)
    {
        std::cout << array_get(arr, i) << " ";
    }
    std::cout << std::endl;

    // ввод чисел k1 и k2
    size_t k1, k2;
    do {
        std::cout << "Введите индекс k1: ";
        std::cin >> k1;
        if(std::cin.fail() || k1 >= array_size(arr)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Неверный индекс. Попробуйте еще раз.\n";
        } else {
            break;
        }
    } while(true);

    do {
        std::cout << "Введите индекс k2: ";
        std::cin >> k2;
        if(std::cin.fail() || k2 >= array_size(arr)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Неверный индекс. Попробуйте еще раз.\n";
        } else {
            break;
        }
    } while(true);

    // вычитание элементов массива
    for (size_t i = 0; i < array_size(arr); ++i)
    {
        if (array_get(arr, i) > 0)
        {
            array_set(arr, i, array_get(arr, i) - array_get(arr, k1));
        }
        else
        {
            array_set(arr, i, array_get(arr, i) - array_get(arr, k2));
        }
    }

    // вывод измененного массива
    std::cout << "Измененный массив: ";
    for (size_t i = 0; i < array_size(arr); ++i)
    {
        std::cout << array_get(arr, i) << " ";
    }
    std::cout << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    // ввод размера массива
    size_t size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    // создание массива с заданным размером
    Array* arr = array_create(size);

    // заполнение массива случайными числами
    for (size_t i = 0; i < size; ++i)
    {
        array_set(arr, i, random_number(1, 100));
    }

    task1(arr);
    task2(arr);

    // освобождение памяти
    array_delete(arr);

    return 0;
}
