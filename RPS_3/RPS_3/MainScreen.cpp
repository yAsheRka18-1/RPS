#include "MainScreen.h"
#include "Test.h"

using namespace System;
using namespace System::Windows::Forms;

// �������� ������� ���������
[STAThreadAttribute]
int main(array <String^>^ args) {
	// ��������� ���������� ������ � ��������� ���������� ��� ����������� ������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// �������� ���������� ����� MainScreen � ������ ����������
	RPS3::MainScreen mainScreen;
	Application::Run(% mainScreen);
	return 0;
}

// ���������� ������� ��� ������ buttonForInsert
System::Void RPS3::MainScreen::buttonForInsert_Click(System::Object^ sender, System::EventArgs^ e)
{
	Functions f;
	ClassArrays^ a = gcnew ClassArrays();
	a->ArrayValues = textBoxForArray->Text;   // ��������� �������� ArrayValues �� ���������� ���� textBoxForArray

	// ��������� �������� SortingStatus � ����������� �� ������ � ���������� ������ arrayForSort
	if (arrayForSort->Text == "������ ������������") {
		a->SortingStatus = 1;
	}
	else {
		a->SortingStatus = 0;
	}

	// ����� ������� Insert ��� ������� ������� a � ���� ������
	f.Insert(a);
}

System::Void RPS3::MainScreen::getArraysFromDB_Click(System::Object^ sender, System::EventArgs^ e)
{
	SelectArray->Enabled = true;  //���������� ������ SelectArray
	Functions f;
	arraysFromDB->DataSource = f.FillComboBox();  //����������� �������� ������ ��� ����������� ������ arraysFromDB � �������������� ���������� ������ ������� FillComboBox �� ������� f
}

System::Void RPS3::MainScreen::SelectArray_Click(System::Object^ sender, System::EventArgs^ e)
{
	int numberOfArrays = arraysFromDB->Items->Count;
	for (int i = 0; i < numberOfArrays; i++) {
		if (arraysFromDB->SelectedIndex == i) {
			// ��������� ������ �� ���������� �������� � ���������� �� �� �����
			String^ strokaFromCmd = Convert::ToString(arraysFromDB->SelectedItem);
			array<String^, 1>^ parts = strokaFromCmd->Split(gcnew array<Char, 1>{':'}, System::StringSplitOptions::RemoveEmptyEntries);
			// ��������� ��������� ����� � ���������� �� ������ ����������� ������
			textBoxForArray->Text = parts[1];
			EnterringArray->Text = parts[1];

			if (Convert::ToInt32(parts[2]) == 1) {
				arrayForSort->Text = "������ ������������";
				SortArray->Enabled = false;
			}
			else {
				arrayForSort->Text = "������ ������� � ����������:";
				SortArray->Enabled = true;
			}
		}
	}
}

System::Void RPS3::MainScreen::SortArray_Click(System::Object^ sender, System::EventArgs^ e)
{
	// ���������� ��� ������ SortArray
	arrayForSort->Text = "������ ������������";
	QuickSort sort;
	std::vector<int> arr;
	String^ sortedArr = "";
	array<String^>^ parts = textBoxForArray->Text->Split((Char)' ');  //��������� ������ ���������� ���� textBoxForArray �� ������ �����

	// ��������� ������ arr ���������� �� �����
	arr.assign(parts->Length, 0);
	for (int i = 0; i < parts->Length; i++) {
		arr[i] = Int32::Parse(parts[i]);
	}

	arr = sort.Qsort(arr);

	// �������� ��������������� ������ ������� � ������
	for (int i = 0; i < parts->Length; i++) {
		if (i != parts->Length - 1) {
			sortedArr = sortedArr + arr[i] + " ";
		}
		else {
			sortedArr = sortedArr + arr[i];
		}
	}

	// ���������� ��������������� ������ ������� � ��������� ����
	textBoxForArray->Text = sortedArr;
}

System::Void RPS3::MainScreen::EnterArray_Click(System::Object^ sender, System::EventArgs^ e)
{
	try {
		// ������� ������ ������ � ��������� ����������
		textBoxForArray->Text = EnterringArray->Text;
		QuickSort sort;
		std::vector<int> res;
		std::vector<int> arr;
		String^ sortedArr = "";
		array<String^>^ parts = textBoxForArray->Text->Split((Char)' ');
		arr.assign(parts->Length, 0);

		// �������������� ����� � ����� ����� � ���������� � ������ arr
		for (int i = 0; i < parts->Length; i++) {
			arr[i] = Int32::Parse(parts[i]);
		}

		res = sort.Qsort(arr);

		// �������� �� ����������������� �������
		for (int i = 0; i < parts->Length; i++) {
			if (arr[i] != res[i]) {
				arrayForSort->Text = "������ ������� � ����������:";
				SortArray->Enabled = true;
			}
			else {
				arrayForSort->Text = "������ ������������";
				SortArray->Enabled = false;
			}
		}

		// �������� ��������������� ������ ������� � ������ � ������� ��� � ��������� ����
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
		arrayForSort->Text = "������. ������� ������ ������������� ��������!";
		textBoxForArray->Clear();
	}
}

System::Void RPS3::MainScreen::EditArray_Click(System::Object^ sender, System::EventArgs^ e)
{
	Functions f;
	if (textBoxForArray->Text == "") {
		MessageBox::Show("���� ��� ����� ������ ������� �� ����� ���� ������!");  // �������� �� ������ ���� ��� ����� ������ �������
	}
	else {
		// �������������� ������� � ���� ������
		ClassArrays^ aOld = gcnew ClassArrays();
		String^ strokaFromCmd = Convert::ToString(arraysFromDB->SelectedItem);
		array<String^, 1>^ parts = strokaFromCmd->Split(gcnew array<Char, 1>{':'}, System::StringSplitOptions::RemoveEmptyEntries);
		aOld->IDArray = Convert::ToInt32(parts[0]);
		aOld->ArrayValues = parts[1];

		ClassArrays^ aNew = gcnew ClassArrays();

		// ���������� ����� �������� � �������� ����������
		aNew->ArrayValues = textBoxForArray->Text;
		if (arrayForSort->Text == "������ ������������") {
			aNew->SortingStatus = 1;
		}
		else {
			aNew->SortingStatus = 0;
		}

		// ����� ������� Update ��� ���������� ������ � ����
		f.Update(aOld, aNew);
	}
}

System::Void RPS3::MainScreen::randomInput_Click(System::Object^ sender, System::EventArgs^ e)
{
	labelForArrSize->Text = "���� ������� �������: ";
	arrayForSort->Text = "������ ������� � ����������:";
	Functions f;
	std::vector<int> arr;
	String^ arrForSort = "";
	try {
		int sizeOfArr = Convert::ToInt32(arrSize->Text);

		if (sizeOfArr <= 0) {
			labelForArrSize->Text = "������. ������� ������������� ������������� �����!";
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
		// ��������� ������ ����������, ���� ������ ��� ����� � ����������
		if (arrayForSort->Text == "������ ������� � ����������:") {
			SortArray->Enabled = true;
		}
	}
	catch (...) {
		labelForArrSize->Text = "������. ������� ������������� ������������� �����!";
	}
}

System::Void RPS3::MainScreen::Tests_Click(System::Object^ sender, System::EventArgs^ e)
{
	//labelForPattern->Text = "���� ���������� ������";
	Test t;
	if (t.Test1() && t.Test4() && t.Test5()) {
		labelForTests1->Text = "�������� 100 ��������: " + t.timeForTest1 + " �� " + "\n"
			+ "�������� � ���������� 100 ��������: " + t.timeForTest4 + " ��� " + "\n"
			+ "������� ����� ��������� 1 �������: " + t.timeForArr100 + " ��� " + "\n"
			+ "�������� 100 ��������: " + t.timeForTest5 + " ���";
	}
	if (t.Test2() && t.Test4() && t.Test5()) {
		labelForTests2->Text = "�������� 1000 ��������: " + t.timeForTest2 + " �� " + "\n"
			+ "�������� � ���������� 1000 ��������: " + t.timeForTest4 + " ��� " + "\n"
			+ "������� ����� ��������� 1 �������: " + t.timeForArr1000 + " ��� " + "\n"
			+ "�������� 1000 ��������: " + t.timeForTest5 + " ���";
	}
	if (t.Test3() && t.Test4() && t.Test5()) {
		labelForTests3->Text = "�������� 10000 ��������: " + t.timeForTest3 + " �� " + "\n"
			+ "�������� � ���������� 10000 ��������: " + t.timeForTest4 + " ��� " + "\n"
			+ "������� ����� ��������� 1 �������: " + t.timeForArr10000 + " ��� " + "\n"
			+ "�������� 10000 ��������: " + t.timeForTest5 + " ���";
	}
	labelForPattern->Text = "��� ����� ��������� �������!\n����� ����������:";
}
