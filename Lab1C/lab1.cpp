#include <iostream>
#include <cstdlib>
#include <ctime>
#include "array.h"
#include "array.cpp"
// ������� ��� ������ 1
void task1(Array* arr, int k1, int k2)
{
    // ���������� ��� �������� �������
    for (size_t i = 0; i < array_size(arr); ++i)
    {
        // ���� ������� �������������
        if (array_get(arr, i) > 0)
        {
            // ���� ������� ������ ����� k1, �� �������� ������� �� k2
            if (i == k1)
            {
                array_set(arr, i, array_get(arr, k2));
            }
            // ����� �������� ������� �� k1
            else
            {
                array_set(arr, i, array_get(arr, k1));
            }
        }
    }
}

// ������� ��� ������ 2
void task2(Array* arr)
{
    // �������������� ������������ ����� � ������ ������ ����������
    int maxSum = 0;
    int startIndex = 0;
    // ���������� ��� ���������� �������� 5
    for (size_t i = 0; i < array_size(arr) - 4; ++i)
    {
        int currentSum = 0;
        // ��������� ����� �������� ����������
        for (size_t j = i; j < i + 5; ++j)
        {
            currentSum += array_get(arr, j);
        }
        // ���� ������� ����� ������ ������������, �� ��������� ������������ ����� � ������ ������ ����������
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            startIndex = i;
        }
    }
    // ������� ���� �������� ��������� � ������������ ������
    std::cout << "���� �������� ��������� � ������������ ������: ";
    for (size_t i = startIndex; i < startIndex + 5; ++i)
    {
        std::cout << array_get(arr, i) << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // �������������� ��������� ��������� �����
    srand(time(0));
    int n;
    // ������ ������ �������
    std::cout << "������� ������ �������: ";
    std::cin >> n;
    // ������� ������
    Array* arr1 = array_create(n);
    // ��������� ������ ���������� �������
    for (size_t i = 0; i < n; ++i)
    {
        array_set(arr1, i, rand() % 100);
    }
    // ������ k1 � k2
    int k1, k2;
    std::cout << "������� k1 � k2: ";
    std::cin >> k1 >> k2;
    // ��������� ������ 1
    task1(arr1, k1, k2);
    // ������� ���������
    for (size_t i = 0; i < n; ++i)
    {
        std::cout << array_get(arr1, i) << " ";
    }
    std::cout << std::endl;
    // ������� ������
    array_delete(arr1);

    // ��������� ������� ��� ������� �������
    std::cout << "������� ������ �������: ";
    std::cin >> n;
    Array* arr2 = array_create(n);
    for (size_t i = 0; i < n; ++i)
    {
        array_set(arr2, i, rand() % 100);
    }
    task2(arr2);
    array_delete(arr2);

    return 0;
}
