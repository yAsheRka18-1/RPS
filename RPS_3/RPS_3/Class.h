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


// ����������� ����������� ������ QuickSort
ref class QuickSort {
public:
    // ���������� ��� ���������� �������
    ~QuickSort() {};

    /// <summary>
    /// ��������� �������� ������� ���������� (Quick Sort).
    /// </summary>
    /// <param name="arr"></param>
    /// <returns></returns>
    std::vector<int> Qsort(std::vector<int> arr);
};
