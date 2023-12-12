#include "interface.h"
#include "getinfo.h"
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include<filesystem>

/// Вывод горизонтальной линии для отделения разделов интерфейса.
void Borders() {
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
}

/// Вывод текстовой задачи.
void Task() {
	cout << "Arrange array in ascending order.\n";
}

/// Вывод меню выбора метода ввода данных.
void MenuForInput() {
	cout
		<< "1. Console input" << endl
		<< "2. File input" << endl
		<< "3. Random input" << endl
		<< "4. Exit" << endl << endl;
}

/// Вывод меню сохранения результатов.
void SavingMenu() {
	cout << "1. Save results to a file" << endl
		<< "2. Return to a main menu" << endl << endl;
}

/// Вывод меню выбора сохранения массива.
void WitchOneSave() {
	cout << "1. Save original array" << endl
		<< "2. Save sorted array" << endl
		<< "3.Back to the previous menu" << endl << endl;
}

/// <summary>
/// Функция для вывода элементов массива в консоль.
/// </summary>
/// <param name="arr">Ссылка на вектор, содержащий элементы массива.</param>
void PrintArr(vector<int>& arr) {

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << setw(5);    //выводит текущий элемент массива с отступом в 5 символов
	}

	cout << "\n";
}

/// <summary>
/// Функция для ввода элементов массива с клавиатуры.
/// </summary>
/// <param name="arr">Ссылка на вектор, в который будут сохранены введенные элементы.</param>
/// <param name="sizeOfArr">Ссылка на переменную, содержащую размер массива.</param>
void ConcoleInput(vector<int>& arr, int& sizeOfArr) {

	// Присвоение вектору указанного размера и заполнение его нулями.
	arr.assign(sizeOfArr, 0);

	cout << "Input array values:\n";

	// Цикл для ввода каждого элемента массива.
	for (int i = 0; i < sizeOfArr; i++) {
		// Получение значения от пользователя с использованием функции GetValue.
		arr[i] = static_cast<int>(GetValue("Enter #" + to_string(i + 1) + " element of array: "));
	}

}

/// <summary>
/// Функция для чтения массива из файла.
/// </summary>
/// <param name="arr">Ссылка на вектор, в который будут сохранены элементы массива.</param>
/// <param name="name">Имя файла для чтения данных.</param>
/// <returns>Возвращает true, если файл успешно прочитан, иначе false.</returns>
bool FileInput(vector<int>& arr, string name) {
	// Открытие файла для чтения.
	ifstream fin;
	fin.open(name);

	// Проверка, успешно ли открыт файл.
	if (!fin.is_open()) {
		cout << "\nError. You cant open the file!\n" << endl;
		return false;
	}

	else {
		string str;
		int tmp = 0;

		// Считывание первой строки из файла.
		getline(fin, str);

		// Инициализация переменной для подсчета пробелов.
		int spaces = 0;

		// Цикл для анализа каждого символа в строке.
		for (int i = 0; i < str.length(); i++) {

			// Удаление пробелов в конце строки.
			while (str[str.length() - 1] == ' ') {
				str.erase(str.length() - 1, 1);
			}

			// Подсчет пробелов в строке.
			if (str[i] == ' ') {
				spaces++;
			}

		}

		// Определение размера массива как количество пробелов плюс один.
		int sizeOfArr = spaces + 1;

		// Инициализация вектора заданного размера и заполнение его нулями.
		arr.assign(sizeOfArr, 0);

		// Закрытие файла и повторное открытие для сброса указателя на начало файла.
		fin.close();
		fin.open(name);

		// Проверка на пустоту файла.
		if (str.empty()) {
			cout << "\nFail empty!\n\n";
			return false;
		}

		// Проверка, содержит ли файл только цифры и пробелы.
		while (getline(fin, str)) {

			for (int i = 0; i < str.length(); i++) {

				// Проверка, является ли текущий символ пробелом или знаком минуса.
				if (str[i] == 32 || str[i] == 45) {
					continue;   // Если да, переходим к следующей итерации цикла.
				}

				// Проверка, является ли текущий символ цифрой.
				else if (str[i] >= 48 && str[i] <= 57) {
					continue;
				}

				// Если текущий символ не пробел, не знак минуса и не цифра, выводится сообщение об ошибке.
				else {
					cout << "\nInvalid arguments used in file" << endl;
					cout << "Edit your file or choose another one!\n\n";
					return false;
				}

			}

		}

		fin.close();
		fin.open(name);

		// Заполнение вектора значениями из файла.
		for (int i = 0; i < sizeOfArr; i++) {
			fin >> tmp;
			arr[i] = tmp;
		}

		fin.close();
		return true;
	}
}

/// <summary>
/// Функция для заполнения массива случайными значениями.
/// </summary>
/// <param name="arr">Ссылка на вектор, который будет заполнен.</param>
/// <param name="sizeOfArr">Ссылка на переменную, содержащую размер массива.</param>
void RandomInput(vector<int>& arr, int& sizeOfArr) {
	arr.assign(sizeOfArr, 0);    // Присвоение вектору указанного размера.
	srand(static_cast<unsigned int>(time(NULL)));    // Инициализация генератора случайных чисел.
	int min = -100;
	int max = 100;

	// Заполнение вектора случайными значениями.
	for (int i = 0; i < sizeOfArr; i++) {
		arr[i] = min + rand() % (max - min + 1);
	}

}

/// <summary>
/// Функция для сортировки массива с использованием конкретного метода сортировки.
/// </summary>
/// <param name="sort">Указатель на объект, реализующий интерфейс ISort.</param>
/// <param name="arr">Ссылка на вектор, который будет отсортирован.</param>
/// <returns>Возвращает исходный массив.</returns>
vector<int> SortWithCertainMethod(shared_ptr<ISort> sort, vector<int>& arr) {
	cout << sort->NameOfSort();   // Вывод названия метода сортировки.
	vector<int> res = arr;   // Создание копии массива для сортировки.
	sort->Sort(res);   // Вызов метода сортировки.
	PrintArr(res);   // Вывод отсортированного массива.
	return arr;
}

/// <summary>
/// Функция для сохранения исходного массива в файл.
/// </summary>
/// <param name="arr">Ссылка на вектор, содержащий исходный массив.</param>
void SaveOriginalArr(vector<int>& arr) {
	// Переменные для работы с файлом и задания имени файла.
	ofstream fout;
	string name = " ";
	int setting = 1;

	// Цикл для ввода имени файла с проверкой на существование файла.
	while (setting) {
		cout << "Enter the name of the file: ";
		cin >> name;

		// Проверка на существование файла.
		if (filesystem::exists(name)) {
			cout << "\nFile already exists! Do you want to overwrite it or create a new one?" << endl << endl;
			cout << "1 - Overwrite" << endl;
			cout << "2 - Create a new one\n\n";
			int setting2 = 1;

			// Вложенный цикл для выбора действия (перезаписать или создать новый файл).
			while (setting2) {
				setting2 = static_cast<int>(GetInt("Choose an option: "));

				switch (setting2) {
				case OverwriteOrNot::overwrite:
					setting2 = 0;
					setting = 0;
					break;
				case OverwriteOrNot::create:
					setting2 = 0;
					break;
				default:
					cout << "Incorect option! Try enter again!" << endl;
					cin >> setting2;
					break;
				}

			}

		}

		else {
			setting = 0;
		}

	}

	// Открытие файла для записи.
	fout.open(name);

	// Проверка успешности открытия файла.
	if (!fout.is_open()) {
		cout << "\nError. You cant open the file!\n" << endl;
	}

	else {

		// Запись исходного массива в файл с отступом.
		for (int i = 0; i < arr.size(); i++) {
			fout << arr[i] << setw(5);
		}

	}

}

/// <summary>
/// Функция для сохранения отсортированного массива в файл.
/// </summary>
/// <param name="arr">Ссылка на вектор, содержащий исходный массив.</param>
void SaveSortedArr(vector<int>& arr) {
	// Создание копии массива и выбор алгоритма сортировки.
	vector<int> res = arr;
	QuickSort sort;
	sort.Sort(res);

	// Открытие файла для записи.
	ofstream fout;
	string name = " ";
	bool getNameOfFile = true;

	// Цикл для ввода имени файла с проверкой на существование файла.
	while (getNameOfFile) {
		cout << "Enter the name of the file: ";
		cin >> name;

		// Проверка на существование файла.
		if (filesystem::exists(name)) {
			cout << "\nFile already exists! Do you want to overwrite it or create a new one?" << endl << endl;
			cout << "1 - Overwrite" << endl;
			cout << "2 - Create a new one\n\n";
			int overwriteOrNot = 1;

			// Вложенный цикл для выбора действия (перезаписать или создать новый файл).
			while (overwriteOrNot) {
				overwriteOrNot = static_cast<int>(GetInt("Choose an option: "));

				switch (overwriteOrNot) {
				case OverwriteOrNot::overwrite:
					overwriteOrNot = 0;
					getNameOfFile = false;
					break;
				case OverwriteOrNot::create:
					overwriteOrNot = 0;
					break;
				default:
					cout << "Incorect option! Try enter again!" << endl;
					cin >> overwriteOrNot;
					break;
				}

			}

		}

		else {
			getNameOfFile = false;
		}

	}

	fout.open(name);

	if (!fout.is_open()) {
		cout << "\nError. You cant open the file!\n" << endl;
	}

	else {

		for (int i = 0; i < res.size(); i++) {
			fout << res[i] << setw(5);
		}

	}

}