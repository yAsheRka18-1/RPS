#pragma once
#include "getinfo.h"
#include <string>
#include <iostream>
#include <limits>

using namespace std;

/// <summary>
/// Функция для получения целочисленного ввода от пользователя с валидацией.
/// </summary>
/// <param name="message">Сообщение, которое будет отображено пользователю для запроса ввода.</param>
/// <returns>Введенное целое число.</returns>
int GetInt(string message);

/// <summary>
/// Функция для получения числового значения от пользователя с валидацией на целочисленность.
/// </summary>
/// <param name="message">Сообщение, которое будет отображено пользователю для запроса ввода.</param>
/// <returns>Введенное целое число.</returns>
int GetValue(string message);
