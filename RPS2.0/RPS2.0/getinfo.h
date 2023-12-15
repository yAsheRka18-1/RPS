#pragma once
#include "getinfo.h"
#include <string>
#include <iostream>
#include <limits>

using namespace std;

/// <summary>
/// ������� ��� ��������� �������������� ����� �� ������������ � ����������.
/// </summary>
/// <param name="message">���������, ������� ����� ���������� ������������ ��� ������� �����.</param>
/// <returns>��������� ����� �����.</returns>
int GetInt(string message);

/// <summary>
/// ������� ��� ��������� ��������� �������� �� ������������ � ���������� �� ���������������.
/// </summary>
/// <param name="message">���������, ������� ����� ���������� ������������ ��� ������� �����.</param>
/// <returns>��������� ����� �����.</returns>
int GetValue(string message);
