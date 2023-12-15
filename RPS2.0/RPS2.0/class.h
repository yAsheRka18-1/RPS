#pragma once
#include <iostream>
#include <vector>
#include <string>


// ������������� ������������ ������������ ���� ��� ��������
using namespace std;

// ����������� ����������� ������ QuickSort
class QuickSort {
public:
    // ���������� ��� ���������� �������
    ~QuickSort() {};

    /// <summary>
    /// ���������� ��� ������ ����������.
    /// </summary>
    /// <returns>��� ������ ����������.</returns>
    string NameOfSort();

    /// <summary>
    /// ���������� ������� ��� �������� �������.
    /// </summary>
    /// <param name="arr">������.</param>
    /// <param name="first">������ ������� ��������.</param>
    /// <param name="second">������ ������� ��������.</param>
    void Permutations(vector<int>& arr, int first, int second);

    /// <summary>
    /// ���������� ��� �����.
    /// </summary>
    /// <param name="a">������ �����.</param>
    /// <param name="b">������ �����.</param>
    /// <returns>���������� true, ���� a > b, ����� false.</returns>
    bool Compare(int a, int b);

    /// <summary>
    /// ��������� �������� ������� ���������� (Quick Sort).
    /// </summary>
    /// <param name="arr">������, ������� ��������� �������������.</param>
    /// <param name="left">������ ������ ����������.</param>
    /// <param name="right">������ ����� ����������.</param>
    void Qsort(vector<int>& arr, int left, int right);

    /// <summary>
    /// ��������� ���������� ������ � �������������� ��������� Quick Sort.
    /// </summary>
    /// <param name="arr">������, ������� ��������� �������������.</param>
    void Sort(vector<int>& arr);
};
