#pragma once
#include"class.h"
#include <fstream>

enum MenuForInput { console = 1, file, random, quit };
enum SavingMenu { savetofile = 1, backToInput };
enum WitchOneSave { original = 1, sorted, backToSaving };
enum OverwriteOrNot { overwrite = 1, create };

/// <summary>
/// Вывод горизонтальной линии для отделения разделов интерфейса.
/// </summary>
void Borders();

/// <summary>
///Вывод текстовой задачи.
/// </summary>
void Task();

/// <summary>
/// Вывод меню выбора метода ввода данных.
/// </summary>
void MenuForInput();

/// <summary>
/// Вывод меню сохранения результатов.
/// </summary>
void SavingMenu();

/// <summary>
/// Вывод меню выбора сохранения массива.
/// </summary>
void WitchOneSave();

/// <summary>
/// Функция для ввода элементов массива с клавиатуры.
/// </summary>
/// <param name="arr">Ссылка на вектор, в который будут сохранены введенные элементы.</param>
/// <param name="sizeOfArr">Ссылка на переменную, содержащую размер массива.</param>
void ConcoleInput(vector<int>& arr, int& sizeOfArr);

/// <summary>
/// Функция для заполнения массива случайными значениями.
/// </summary>
/// <param name="arr">Ссылка на вектор, который будет заполнен.</param>
/// <param name="sizeOfArr">Ссылка на переменную, содержащую размер массива.</param>
void RandomInput(vector<int>& arr, int& sizeOfArr);

/// <summary>
/// Функция для чтения массива из файла.
/// </summary>
/// <param name="arr">Ссылка на вектор, в который будут сохранены элементы массива.</param>
/// <param name="name">Имя файла для чтения данных.</param>
/// <returns>Возвращает true, если файл успешно прочитан, иначе false.</returns>
bool FileInput(vector<int>& arr, string name);

/// <summary>
/// Функция для вывода элементов массива в консоль.
/// </summary>
/// <param name="arr">Ссылка на вектор, содержащий элементы массива.</param>
void PrintArr(vector<int>& arr);

/// <summary>
/// Функция для сохранения исходного массива в файл.
/// </summary>
/// <param name="arr">Ссылка на вектор, содержащий исходный массив.</param>
void SaveOriginalArr(vector<int>& arr);

/// <summary>
/// Функция для сохранения отсортированного массива в файл.
/// </summary>
/// <param name="arr">Ссылка на вектор, содержащий исходный массив.</param>
void SaveSortedArr(vector<int>& arr);

