#pragma once
#include <vector>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Data;
using namespace Data::SqlClient;


// Определение конкретного класса QuickSort
ref class QuickSort {
public:
    // деструктор для правильной очистки
    ~QuickSort() {};

    /// <summary>
    /// Реализует алгоритм быстрой сортировки (Quick Sort).
    /// </summary>
    /// <param name="arr"></param>
    /// <returns></returns>
    std::vector<int> Qsort(std::vector<int> arr);
};
