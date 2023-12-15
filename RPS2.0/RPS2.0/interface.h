#pragma once
#include"class.h"
#include <fstream>

enum MenuForInput { console = 1, file, random, quit };
enum SavingMenu { savetofile = 1, backToInput };
enum WitchOneSave { original = 1, sorted, backToSaving };
enum OverwriteOrNot { overwrite = 1, create };

/// <summary>
/// ����� �������������� ����� ��� ��������� �������� ����������.
/// </summary>
void Borders();

/// <summary>
///����� ��������� ������.
/// </summary>
void Task();

/// <summary>
/// ����� ���� ������ ������ ����� ������.
/// </summary>
void MenuForInput();

/// <summary>
/// ����� ���� ���������� �����������.
/// </summary>
void SavingMenu();

/// <summary>
/// ����� ���� ������ ���������� �������.
/// </summary>
void WitchOneSave();

/// <summary>
/// ������� ��� ����� ��������� ������� � ����������.
/// </summary>
/// <param name="arr">������ �� ������, � ������� ����� ��������� ��������� ��������.</param>
/// <param name="sizeOfArr">������ �� ����������, ���������� ������ �������.</param>
void ConcoleInput(vector<int>& arr, int& sizeOfArr);

/// <summary>
/// ������� ��� ���������� ������� ���������� ����������.
/// </summary>
/// <param name="arr">������ �� ������, ������� ����� ��������.</param>
/// <param name="sizeOfArr">������ �� ����������, ���������� ������ �������.</param>
void RandomInput(vector<int>& arr, int& sizeOfArr);

/// <summary>
/// ������� ��� ������ ������� �� �����.
/// </summary>
/// <param name="arr">������ �� ������, � ������� ����� ��������� �������� �������.</param>
/// <param name="name">��� ����� ��� ������ ������.</param>
/// <returns>���������� true, ���� ���� ������� ��������, ����� false.</returns>
bool FileInput(vector<int>& arr, string name);

/// <summary>
/// ������� ��� ������ ��������� ������� � �������.
/// </summary>
/// <param name="arr">������ �� ������, ���������� �������� �������.</param>
void PrintArr(vector<int>& arr);

/// <summary>
/// ������� ��� ���������� ��������� ������� � ����.
/// </summary>
/// <param name="arr">������ �� ������, ���������� �������� ������.</param>
void SaveOriginalArr(vector<int>& arr);

/// <summary>
/// ������� ��� ���������� ���������������� ������� � ����.
/// </summary>
/// <param name="arr">������ �� ������, ���������� �������� ������.</param>
void SaveSortedArr(vector<int>& arr);

