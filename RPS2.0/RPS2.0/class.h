#pragma once
#include <iostream>
#include <vector>
#include <string>


// Использование стандартного пространства имен для удобства
using namespace std;

// Определение конкретного класса QuickSort
class QuickSort {
public:
    // деструктор для правильной очистки
    ~QuickSort() {};

    /// <summary>
    /// Возвращает имя метода сортировки.
    /// </summary>
    /// <returns>Имя метода сортировки.</returns>
    string NameOfSort();

    /// <summary>
    /// Обменивает местами два элемента массива.
    /// </summary>
    /// <param name="arr">Массив.</param>
    /// <param name="first">Индекс первого элемента.</param>
    /// <param name="second">Индекс второго элемента.</param>
    void Permutations(vector<int>& arr, int first, int second);

    /// <summary>
    /// Сравнивает два числа.
    /// </summary>
    /// <param name="a">Первое число.</param>
    /// <param name="b">Второе число.</param>
    /// <returns>Возвращает true, если a > b, иначе false.</returns>
    bool Compare(int a, int b);

    /// <summary>
    /// Реализует алгоритм быстрой сортировки (Quick Sort).
    /// </summary>
    /// <param name="arr">Массив, который требуется отсортировать.</param>
    /// <param name="left">Индекс начала подмассива.</param>
    /// <param name="right">Индекс конца подмассива.</param>
    void Qsort(vector<int>& arr, int left, int right);

    /// <summary>
    /// Сортирует переданный массив с использованием алгоритма Quick Sort.
    /// </summary>
    /// <param name="arr">Массив, который требуется отсортировать.</param>
    void Sort(vector<int>& arr);
};
