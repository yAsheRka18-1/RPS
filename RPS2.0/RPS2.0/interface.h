#pragma once
#include <iostream>
#include <vector>
#include <string>

// Использование стандартного пространства имен для удобства
using namespace std;


// В следующем коде определен интерфейсный класс ISort и конкретный класс QuickSort
// Класс QuickSort наследует интерфейс ISort и реализует метод Sort, используя алгоритм быстрой сортировки
// Определение интерфейсного класса ISort
class ISort {
public:
    // Виртуальный деструктор для правильной очистки
    virtual ~ISort() {};

    // Чисто виртуальная функция для сортировки вектора целых чисел
    virtual void Sort(vector<int>& arr) = 0;

    // Чисто виртуальная функция для получения названия алгоритма сортировки
    virtual string NameOfSort() = 0;

    // Вспомогательная функция для обмена элементов в векторе
    void Permutations(vector<int>& arr, int first, int second) {
        swap(arr[first], arr[second]);
    }

    // Вспомогательная функция для сравнения двух чисел
    bool Compare(int a, int b) {
        return a > b;
    }
};

// Определение конкретного класса QuickSort, который реализует интерфейс ISort
class QuickSort : public ISort {
public:
    // Виртуальный деструктор для правильной очистки
    virtual ~QuickSort() {};

    // Реализация виртуальной функции для получения названия алгоритма сортировки
    virtual string NameOfSort() override {
        return "Quick Sort\n";
    }

    // Рекурсивная вспомогательная функция для быстрой сортировки
    void Qsort(vector<int>& arr, int left, int right) {
        int i = left;
        int j = right;
        // Выбор опорного элемента в качестве среднего элемента массива
        int pivot = arr[(static_cast<vector<int, allocator<int>>::size_type>(left) + right) / 2];

        while (i <= j) {

            while (Compare(pivot, arr[i])) {
                i++;
            }

            while (Compare(arr[j], pivot)) {
                j--;
            }

            if (i <= j) {
                // Обмен элементов и изменение индексов
                Permutations(arr, i, j);
                i++;
                j--;
            }
        }

        // Рекурсивная сортировка подмассивов

        if (left < j) {
            Qsort(arr, left, j);
        }

        if (i < right) {
            Qsort(arr, i, right);
        }
    }

    virtual void Sort(vector<int>& arr) override {
        Qsort(arr, 0, static_cast<int>(arr.size()) - 1);
    }
};

