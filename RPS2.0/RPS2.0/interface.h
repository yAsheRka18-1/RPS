#pragma once
#include <iostream>
#include <vector>
#include <string>

// ������������� ������������ ������������ ���� ��� ��������
using namespace std;


// � ��������� ���� ��������� ������������ ����� ISort � ���������� ����� QuickSort
// ����� QuickSort ��������� ��������� ISort � ��������� ����� Sort, ��������� �������� ������� ����������
// ����������� ������������� ������ ISort
class ISort {
public:
    // ����������� ���������� ��� ���������� �������
    virtual ~ISort() {};

    // ����� ����������� ������� ��� ���������� ������� ����� �����
    virtual void Sort(vector<int>& arr) = 0;

    // ����� ����������� ������� ��� ��������� �������� ��������� ����������
    virtual string NameOfSort() = 0;

    // ��������������� ������� ��� ������ ��������� � �������
    void Permutations(vector<int>& arr, int first, int second) {
        swap(arr[first], arr[second]);
    }

    // ��������������� ������� ��� ��������� ���� �����
    bool Compare(int a, int b) {
        return a > b;
    }
};

// ����������� ����������� ������ QuickSort, ������� ��������� ��������� ISort
class QuickSort : public ISort {
public:
    // ����������� ���������� ��� ���������� �������
    virtual ~QuickSort() {};

    // ���������� ����������� ������� ��� ��������� �������� ��������� ����������
    virtual string NameOfSort() override {
        return "Quick Sort\n";
    }

    // ����������� ��������������� ������� ��� ������� ����������
    void Qsort(vector<int>& arr, int left, int right) {
        int i = left;
        int j = right;
        // ����� �������� �������� � �������� �������� �������� �������
        int pivot = arr[(static_cast<vector<int, allocator<int>>::size_type>(left) + right) / 2];

        while (i <= j) {

            while (Compare(pivot, arr[i])) {
                i++;
            }

            while (Compare(arr[j], pivot)) {
                j--;
            }

            if (i <= j) {
                // ����� ��������� � ��������� ��������
                Permutations(arr, i, j);
                i++;
                j--;
            }
        }

        // ����������� ���������� �����������

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

