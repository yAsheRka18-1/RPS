#include "MainScreen.h"
#include "Test.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array <String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	RPS3::MainScreen mainScreen;
	Application::Run(% mainScreen);
	return 0;
}

System::Void RPS3::MainScreen::buttonForInsert_Click(System::Object^ sender, System::EventArgs^ e)
{
	Functions f;
	ClassArrays^ a = gcnew ClassArrays();
	a->ArrayValues = textBoxForArray->Text;
	if (arrayForSort->Text == "Массив отсортирован") {
		a->SortingStatus = 1;
	}
	else {
		a->SortingStatus = 0;
	}
	f.Insert(a, "Arrays");
}

System::Void RPS3::MainScreen::getArraysFromDB_Click(System::Object^ sender, System::EventArgs^ e)
{
	SelectArray->Enabled = true;
	Functions f;
	arraysFromDB->DataSource = f.FillComboBox();
}

System::Void RPS3::MainScreen::SelectArray_Click(System::Object^ sender, System::EventArgs^ e)
{
	int numberOfArrays = arraysFromDB->Items->Count;
	for (int i = 0; i < numberOfArrays; i++) {
		if (arraysFromDB->SelectedIndex == i) {
			String^ strokaFromCmd = Convert::ToString(arraysFromDB->SelectedItem);
			array<String^, 1>^ parts = strokaFromCmd->Split(gcnew array<Char, 1>{':'}, System::StringSplitOptions::RemoveEmptyEntries);
			textBoxForArray->Text = parts[1];
			EnterringArray->Text = parts[1];
			if (Convert::ToInt32(parts[2]) == 1) {
				arrayForSort->Text = "Массив отсортирован";
				SortArray->Enabled = false;
			}
			else {
				arrayForSort->Text = "Массив готовый к сортировке:";
				SortArray->Enabled = true;
			}
		}
	}
}

System::Void RPS3::MainScreen::SortArray_Click(System::Object^ sender, System::EventArgs^ e)
{
	arrayForSort->Text = "Массив отсортирован";
	QuickSort sort;
	std::vector<int> arr;
	String^ sortedArr = "";
	array<String^>^ parts = textBoxForArray->Text->Split((Char)' ');
	arr.assign(parts->Length, 0);
	for (int i = 0; i < parts->Length; i++) {
		arr[i] = Int32::Parse(parts[i]);
	}
	arr = sort.Qsort(arr);
	for (int i = 0; i < parts->Length; i++) {
		if (i != parts->Length - 1) {
			sortedArr = sortedArr + arr[i] + " ";
		}
		else {
			sortedArr = sortedArr + arr[i];
		}
	}
	textBoxForArray->Text = sortedArr;
}

System::Void RPS3::MainScreen::EnterArray_Click(System::Object^ sender, System::EventArgs^ e)
{
	try {
		textBoxForArray->Text = EnterringArray->Text;
		QuickSort sort;
		std::vector<int> res;
		std::vector<int> arr;
		String^ sortedArr = "";
		array<String^>^ parts = textBoxForArray->Text->Split((Char)' ');
		arr.assign(parts->Length, 0);
		for (int i = 0; i < parts->Length; i++) {
			arr[i] = Int32::Parse(parts[i]);
		}

		res = sort.Qsort(arr);
		for (int i = 0; i < parts->Length; i++) {
			if (arr[i] != res[i]) {
				arrayForSort->Text = "Массив готовый к сортировке:";
				SortArray->Enabled = true;
			}
			else {
				arrayForSort->Text = "Массив отсортирован";
				SortArray->Enabled = false;
			}

		}
		for (int i = 0; i < parts->Length; i++) {
			if (i != parts->Length - 1) {
				sortedArr = sortedArr + arr[i] + " ";
			}
			else {
				sortedArr = sortedArr + arr[i];
			}
		}
		textBoxForArray->Text = sortedArr;
	}
	catch (...) {
		arrayForSort->Text = "Ошибка. Вводите только целочисленные значения!";
		textBoxForArray->Clear();
	}
}

System::Void RPS3::MainScreen::EditArray_Click(System::Object^ sender, System::EventArgs^ e)
{
	Functions f;
	if (textBoxForArray->Text == "") {
		MessageBox::Show("Поле для ввода нового массива не может быть пустым!");
	}
	else {
		ClassArrays^ aOld = gcnew ClassArrays();
		String^ strokaFromCmd = Convert::ToString(arraysFromDB->SelectedItem);
		array<String^, 1>^ parts = strokaFromCmd->Split(gcnew array<Char, 1>{':'}, System::StringSplitOptions::RemoveEmptyEntries);
		aOld->IDArray = Convert::ToInt32(parts[0]);
		aOld->ArrayValues = parts[1];

		ClassArrays^ aNew = gcnew ClassArrays();

		aNew->ArrayValues = textBoxForArray->Text;
		if (arrayForSort->Text == "Массив отсортирован") {
			aNew->SortingStatus = 1;
		}
		else {
			aNew->SortingStatus = 0;
		}

		f.Update(aOld, aNew);
	}
}

System::Void RPS3::MainScreen::randomInput_Click(System::Object^ sender, System::EventArgs^ e)
{
	labelForArrSize->Text = "Ввод размера массива: ";
	arrayForSort->Text = "Массив готовый к сортировке:";
	Functions f;
	std::vector<int> arr;
	String^ arrForSort = "";
	try {
		int sizeOfArr = Convert::ToInt32(arrSize->Text);

		if (sizeOfArr <= 0) {
			labelForArrSize->Text = "Ошибка. Введите положительное целочисленное число!";
		}
		f.RandomInput(arr, sizeOfArr);
		for (int i = 0; i < sizeOfArr; i++) {
			if (i != sizeOfArr - 1) {
				arrForSort = arrForSort + arr[i] + " ";
			}
			else {
				arrForSort = arrForSort + arr[i];
			}
		}
		textBoxForArray->Text = arrForSort;
		EnterringArray->Text = arrForSort;
		///
		if (arrayForSort->Text == "Массив готовый к сортировке:") {
			SortArray->Enabled = true;
		}
	}
	catch (...) {
		labelForArrSize->Text = "Ошибка. Введите положительное целочисленное число!";
	}
}

System::Void RPS3::MainScreen::Tests_Click(System::Object^ sender, System::EventArgs^ e)
{
	//labelForPattern->Text = "Идет выполнение тестов";
	Test t;
	if (t.Test1(100) && t.Test2() && t.Test3()) {
		labelForTests1->Text = "Загрузка 100 массивов: " + t.timeForTest1 + " мс " + "\n"
			+ "Выгрузка и сортировка 100 массивов: " + t.timeForTest2 + " мкс " + "\n"
			+ "Среднее время обработки 1 массива: " + t.timeForArr100 + " мкс " + "\n"
			+ "Удаление 100 массивов: " + t.timeForTest3 + " мкс";
	}
	if (t.Test1(1000) && t.Test2() && t.Test3()) {
		labelForTests2->Text = "Загрузка 1000 массивов: " + t.timeForTest1 + " мс " + "\n"
			+ "Выгрузка и сортировка 1000 массивов: " + t.timeForTest2 + " мкс " + "\n"
			+ "Среднее время обработки 1 массива: " + t.timeForArr1000 + " мкс " + "\n"
			+ "Удаление 1000 массивов: " + t.timeForTest3 + " мкс";
	}
	if (t.Test1(10000) && t.Test2() && t.Test3()) {
		labelForTests3->Text = "Загрузка 10000 массивов: " + t.timeForTest1 + " мс " + "\n"
			+ "Выгрузка и сортировка 10000 массивов: " + t.timeForTest2 + " мкс " + "\n"
			+ "Среднее время обработки 1 массива: " + t.timeForArr10000 + " мкс " + "\n"
			+ "Удаление 10000 массивов: " + t.timeForTest3 + " мкс";
	}
	labelForPattern->Text = "Все тесты выполнены успешно!\nВремя выполнения:";
}
