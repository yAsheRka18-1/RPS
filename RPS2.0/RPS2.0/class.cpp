#include "class.h"

string QuickSort::NameOfSort() {
    return "Quick Sort\n";
}

void QuickSort::Permutations(vector<int>& arr, int first, int second) {
    swap(arr[first], arr[second]);
}

bool QuickSort::Compare(int a, int b) {
    return a > b;
}

void QuickSort::Qsort(vector<int>& arr, int left, int right) {
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

void QuickSort::Sort(vector<int>& arr) {
    Qsort(arr, 0, static_cast<int>(arr.size()) - 1);  //arr - ссылка на вектор для сортировки,
                                                      // 0 - индекс начала сортировки(индекс первого элемента в векторе),
                                                      //static_cast<int>(arr.size()) - 1 - индекс конца сортировки
}
