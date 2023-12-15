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
		cout << arr[i] << setw(5);    //������� ������� ������� ������� � �������� � 5 ��������
	}

	cout << "\n";
}

void ConcoleInput(vector<int>& arr, int& sizeOfArr) {

	// ���������� ������� ���������� ������� � ���������� ��� ������.
	arr.assign(sizeOfArr, 0);

	cout << "Input array values:\n";

	// ���� ��� ����� ������� �������� �������.
	for (int i = 0; i < sizeOfArr; i++) {
		// ��������� �������� �� ������������ � �������������� ������� GetValue.
		arr[i] = static_cast<int>(GetValue("Enter #" + to_string(i + 1) + " element of array: "));
	}
}

bool FileInput(vector<int>& arr, string name) {
	// �������� ����� ��� ������.
	ifstream fin;
	fin.open(name);
	int value = 0;
	int sizeOfArr = 0;

	// ��������, ������� �� ������ ����.
	if (!fin.is_open()) {
		cout << "\nError. You cant open the file!\n" << endl;
		return false;
	}
	else {

		// �������� �� ������� �����.
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

			// ���������� ������� ���������� �� �����.
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
	arr.assign(sizeOfArr, 0);    // ���������� ������� ���������� ������� � ��������� ��� ������.
	srand(static_cast<unsigned int>(time(NULL)));    // ������������� ���������� ��������� �����.
	int min = -100;
	int max = 100;

	// ���������� ������� ���������� ����������.
	for (int i = 0; i < sizeOfArr; i++) {
		arr[i] = min + rand() % (max - min + 1);
	}
}

void SaveOriginalArr(vector<int>& arr) {
	// ���������� ��� ������ � ������ � ������� ����� �����.
	ofstream fout;
	string name = " ";
	int setting = 1;

	// ���� ��� ����� ����� ����� � ��������� �� ������������� �����.
	while (setting) {
		cout << "Enter the name of the file: ";
		cin >> name;

		// �������� �� ������������� �����.
		if (filesystem::exists(name)) {
			cout << "\nFile already exists! Do you want to overwrite it or create a new one?" << endl << endl;
			cout << "1 - Overwrite" << endl;
			cout << "2 - Create a new one\n\n";
			int setting2 = 1;

			// ��������� ���� ��� ������ �������� (������������ ��� ������� ����� ����).
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

	// �������� ����� ��� ������.
	fout.open(name);

	// �������� ���������� �������� �����.
	if (!fout.is_open()) {
		cout << "\nError. You cant open the file!\n" << endl;
	}
	else {

		// ������ ��������� ������� � ���� � ��������.
		for (int i = 0; i < arr.size(); i++) {
			fout << arr[i] << setw(5);
		}

	}

}

void SaveSortedArr(vector<int>& arr) {
	// �������� ����� ������� � ����� ��������� ����������.
	vector<int> res = arr;
	QuickSort sort;
	sort.Sort(res);

	// �������� ����� ��� ������.
	ofstream fout;
	string name = " ";
	bool getNameOfFile = true;

	// ���� ��� ����� ����� ����� � ��������� �� ������������� �����.
	while (getNameOfFile) {
		cout << "Enter the name of the file: ";
		cin >> name;

		// �������� �� ������������� �����.
		if (filesystem::exists(name)) {
			cout << "\nFile already exists! Do you want to overwrite it or create a new one?" << endl << endl;
			cout << "1 - Overwrite" << endl;
			cout << "2 - Create a new one\n\n";
			int overwriteOrNot = 1;

			// ��������� ���� ��� ������ �������� (������������ ��� ������� ����� ����).
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