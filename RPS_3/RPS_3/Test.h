#pragma once
#include "MainScreen.h"
#include <chrono>

ref class Test
{
public:
	static String^ timeForTest1;
	static String^ timeForTest2;
	static String^ timeForTest3;
	static String^ timeForArr100;
	static String^ timeForArr1000;
	static String^ timeForArr10000;
	/// <summary>
	/// ���� ��� �������� 100/1000/10000 ��������
	/// </summary>
	/// <returns></returns>
	bool Test1(int numberOfArr);
	/// <summary>
	/// ���� ��� �������� 1000 ��������
	/// </summary>
	/// <returns></returns>
	bool Test2();
	/// <summary>
	/// ���� ��� �������� ���� �������� �� ��
	/// </summary>
	/// <returns></returns>
	bool Test3();
};

