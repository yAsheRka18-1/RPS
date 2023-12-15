#include "interface.h"
#include "getinfo.h"
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include<filesystem>


void Borders() {
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
}

void Task() {
	cout << "Arrange array in ascending order.\n";
}

void MenuForInput() {
	cout
		<< "1. Console input" << endl
		<< "2. File input" << endl
		<< "3. Random input" << endl
		<< "4. Exit" << endl << endl;
}

void SavingMenu() {
	cout << "1. Save results to a file" << endl
		<< "2. Return to a main menu" << endl << endl;
}

void WitchOneSave() {
	cout << "1. Save original array" << endl
		<< "2. Save sorted array" << endl
		<< "3.Back to the previous menu" << endl << endl;
}

void PrintArr(vector<int>& arr) {

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << setw(5);    //выводит текущий элемент массива с отступом в 5 символов
	}

	cout << "\n";
}

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

bool FileInput(vector<int>& arr, string name) {
	// Открытие файла для чтения.
	ifstream fin;
	fin.open(name);
	int value = 0;
	int sizeOfArr = 0;

	// Проверка, успешно ли открыт файл.
	if (!fin.is_open()) {
		cout << "\nError. You cant open the file!\n" << endl;
		return false;
	}
	else {

		// Проверка на пустоту файла.
		if (fin.eof()) {
			cout << "\nFail empty!\n\n";
			return false;
		}
		else {

			while (!fin.eof()) {
				fin >> value;
				sizeOfArr++;
			}

			arr.assign(sizeOfArr, 0);
			fin.close();
			fin.open(name);

			// Заполнение вектора значениями из файла.
			for (int i = 0; i < sizeOfArr; i++) {
				fin >> value;
				arr[i] = value;
			}

			fin.close();
			return true;
		}
	}
}

void RandomInput(vector<int>& arr, int& sizeOfArr) {
	arr.assign(sizeOfArr, 0);    // Присвоение вектору указанного размера и заполение его нулями.
	srand(static_cast<unsigned int>(time(NULL)));    // Инициализация генератора случайных чисел.
	int min = -100;
	int max = 100;

	// Заполнение вектора случайными значениями.
	for (int i = 0; i < sizeOfArr; i++) {
		arr[i] = min + rand() % (max - min + 1);
	}
}

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