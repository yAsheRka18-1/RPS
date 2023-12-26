#pragma once
#include "Functions.h"
#include "Class.h"

namespace RPS3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MainScreen
	/// </summary>
	public ref class MainScreen : public System::Windows::Forms::Form
	{
		static int seconds = 0;
		static int minutes = 0;
		String^ sec;
		String^ min;
	private: System::Windows::Forms::Label^ labelForArrSize;
	private: System::Windows::Forms::Label^ labelForTests2;

	private: System::Windows::Forms::Label^ labelForTests3;




	private: System::Windows::Forms::Label^ labelForPattern;



	public:
		MainScreen(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MainScreen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ exitButton;
	private: System::Windows::Forms::TextBox^ textBoxForArray;
	private: System::Windows::Forms::Button^ buttonForInsert;
	private: System::Windows::Forms::ComboBox^ arraysFromDB;
	private: System::Windows::Forms::Button^ getArraysFromDB;

	private: System::Windows::Forms::Button^ SelectArray;
	private: System::Windows::Forms::Button^ SortArray;
	private: System::Windows::Forms::TextBox^ EnterringArray;
	private: System::Windows::Forms::Button^ EnterArray;
	private: System::Windows::Forms::Button^ EditArray;
	private: System::Windows::Forms::Label^ arrayForSort;
	private: System::Windows::Forms::Label^ labelForArrInput;
	private: System::Windows::Forms::Button^ randomInput;
	private: System::Windows::Forms::TextBox^ arrSize;
	private: System::Windows::Forms::Button^ Tests;
	private: System::Windows::Forms::Label^ labelForTests1;



	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->textBoxForArray = (gcnew System::Windows::Forms::TextBox());
			this->buttonForInsert = (gcnew System::Windows::Forms::Button());
			this->arraysFromDB = (gcnew System::Windows::Forms::ComboBox());
			this->getArraysFromDB = (gcnew System::Windows::Forms::Button());
			this->SelectArray = (gcnew System::Windows::Forms::Button());
			this->SortArray = (gcnew System::Windows::Forms::Button());
			this->EnterringArray = (gcnew System::Windows::Forms::TextBox());
			this->EnterArray = (gcnew System::Windows::Forms::Button());
			this->EditArray = (gcnew System::Windows::Forms::Button());
			this->arrayForSort = (gcnew System::Windows::Forms::Label());
			this->labelForArrInput = (gcnew System::Windows::Forms::Label());
			this->randomInput = (gcnew System::Windows::Forms::Button());
			this->arrSize = (gcnew System::Windows::Forms::TextBox());
			this->Tests = (gcnew System::Windows::Forms::Button());
			this->labelForTests1 = (gcnew System::Windows::Forms::Label());
			this->labelForArrSize = (gcnew System::Windows::Forms::Label());
			this->labelForTests2 = (gcnew System::Windows::Forms::Label());
			this->labelForTests3 = (gcnew System::Windows::Forms::Label());
			this->labelForPattern = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// exitButton
			// 
			this->exitButton->Location = System::Drawing::Point(602, 27);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(65, 23);
			this->exitButton->TabIndex = 0;
			this->exitButton->Text = L"�����";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &MainScreen::exitButton_Click);
			// 
			// textBoxForArray
			// 
			this->textBoxForArray->Location = System::Drawing::Point(12, 152);
			this->textBoxForArray->Name = L"textBoxForArray";
			this->textBoxForArray->Size = System::Drawing::Size(371, 20);
			this->textBoxForArray->TabIndex = 1;
			// 
			// buttonForInsert
			// 
			this->buttonForInsert->Location = System::Drawing::Point(13, 207);
			this->buttonForInsert->Name = L"buttonForInsert";
			this->buttonForInsert->Size = System::Drawing::Size(177, 54);
			this->buttonForInsert->TabIndex = 2;
			this->buttonForInsert->Text = L"�������� ���������/�������������� ������ � ���� ������";
			this->buttonForInsert->UseVisualStyleBackColor = true;
			this->buttonForInsert->Click += gcnew System::EventHandler(this, &MainScreen::buttonForInsert_Click);
			// 
			// arraysFromDB
			// 
			this->arraysFromDB->FormattingEnabled = true;
			this->arraysFromDB->Location = System::Drawing::Point(12, 311);
			this->arraysFromDB->Name = L"arraysFromDB";
			this->arraysFromDB->Size = System::Drawing::Size(371, 21);
			this->arraysFromDB->TabIndex = 3;
			// 
			// getArraysFromDB
			// 
			this->getArraysFromDB->Location = System::Drawing::Point(12, 267);
			this->getArraysFromDB->Name = L"getArraysFromDB";
			this->getArraysFromDB->Size = System::Drawing::Size(371, 38);
			this->getArraysFromDB->TabIndex = 4;
			this->getArraysFromDB->Text = L"�������� ������ �������� �� ���� ������";
			this->getArraysFromDB->UseVisualStyleBackColor = true;
			this->getArraysFromDB->Click += gcnew System::EventHandler(this, &MainScreen::getArraysFromDB_Click);
			// 
			// SelectArray
			// 
			this->SelectArray->Enabled = false;
			this->SelectArray->Location = System::Drawing::Point(12, 338);
			this->SelectArray->Name = L"SelectArray";
			this->SelectArray->Size = System::Drawing::Size(371, 22);
			this->SelectArray->TabIndex = 6;
			this->SelectArray->Text = L"����������� ����� �������";
			this->SelectArray->UseVisualStyleBackColor = true;
			this->SelectArray->Click += gcnew System::EventHandler(this, &MainScreen::SelectArray_Click);
			// 
			// SortArray
			// 
			this->SortArray->Enabled = false;
			this->SortArray->Location = System::Drawing::Point(12, 178);
			this->SortArray->Name = L"SortArray";
			this->SortArray->Size = System::Drawing::Size(371, 23);
			this->SortArray->TabIndex = 7;
			this->SortArray->Text = L"������������� ������";
			this->SortArray->UseVisualStyleBackColor = true;
			this->SortArray->Click += gcnew System::EventHandler(this, &MainScreen::SortArray_Click);
			// 
			// EnterringArray
			// 
			this->EnterringArray->Location = System::Drawing::Point(12, 30);
			this->EnterringArray->Name = L"EnterringArray";
			this->EnterringArray->Size = System::Drawing::Size(371, 20);
			this->EnterringArray->TabIndex = 8;
			// 
			// EnterArray
			// 
			this->EnterArray->Location = System::Drawing::Point(12, 104);
			this->EnterArray->Name = L"EnterArray";
			this->EnterArray->Size = System::Drawing::Size(371, 29);
			this->EnterArray->TabIndex = 9;
			this->EnterArray->Text = L"��������� ����/��������� �������";
			this->EnterArray->UseVisualStyleBackColor = true;
			this->EnterArray->Click += gcnew System::EventHandler(this, &MainScreen::EnterArray_Click);
			// 
			// EditArray
			// 
			this->EditArray->Location = System::Drawing::Point(202, 207);
			this->EditArray->Name = L"EditArray";
			this->EditArray->Size = System::Drawing::Size(181, 54);
			this->EditArray->TabIndex = 10;
			this->EditArray->Text = L"��������������� ������ �� ���� ������";
			this->EditArray->UseVisualStyleBackColor = true;
			this->EditArray->Click += gcnew System::EventHandler(this, &MainScreen::EditArray_Click);
			// 
			// arrayForSort
			// 
			this->arrayForSort->AutoSize = true;
			this->arrayForSort->Location = System::Drawing::Point(12, 136);
			this->arrayForSort->Name = L"arrayForSort";
			this->arrayForSort->Size = System::Drawing::Size(165, 13);
			this->arrayForSort->TabIndex = 11;
			this->arrayForSort->Text = L"������ ������� � ����������:";
			// 
			// labelForArrInput
			// 
			this->labelForArrInput->AutoSize = true;
			this->labelForArrInput->Location = System::Drawing::Point(9, 14);
			this->labelForArrInput->Name = L"labelForArrInput";
			this->labelForArrInput->Size = System::Drawing::Size(178, 13);
			this->labelForArrInput->TabIndex = 12;
			this->labelForArrInput->Text = L"�������/�������������� ������:";
			// 
			// randomInput
			// 
			this->randomInput->Location = System::Drawing::Point(161, 75);
			this->randomInput->Name = L"randomInput";
			this->randomInput->Size = System::Drawing::Size(222, 23);
			this->randomInput->TabIndex = 13;
			this->randomInput->Text = L"��������� ����";
			this->randomInput->UseVisualStyleBackColor = true;
			this->randomInput->Click += gcnew System::EventHandler(this, &MainScreen::randomInput_Click);
			// 
			// arrSize
			// 
			this->arrSize->Location = System::Drawing::Point(12, 78);
			this->arrSize->Name = L"arrSize";
			this->arrSize->Size = System::Drawing::Size(126, 20);
			this->arrSize->TabIndex = 14;
			// 
			// Tests
			// 
			this->Tests->Location = System::Drawing::Point(430, 27);
			this->Tests->Name = L"Tests";
			this->Tests->Size = System::Drawing::Size(75, 23);
			this->Tests->TabIndex = 15;
			this->Tests->Text = L"����";
			this->Tests->UseVisualStyleBackColor = true;
			this->Tests->Click += gcnew System::EventHandler(this, &MainScreen::Tests_Click);
			// 
			// labelForTests1
			// 
			this->labelForTests1->AutoSize = true;
			this->labelForTests1->Location = System::Drawing::Point(427, 104);
			this->labelForTests1->Name = L"labelForTests1";
			this->labelForTests1->Size = System::Drawing::Size(204, 52);
			this->labelForTests1->TabIndex = 16;
			this->labelForTests1->Text = L"�������� 100 ��������: \r\n�������� � ���������� 100 ��������:\r\n������� ����� �����"
				L"���� 1 �������: \r\n�������� 100 ��������: ";
			// 
			// labelForArrSize
			// 
			this->labelForArrSize->AutoSize = true;
			this->labelForArrSize->Location = System::Drawing::Point(9, 62);
			this->labelForArrSize->Name = L"labelForArrSize";
			this->labelForArrSize->Size = System::Drawing::Size(129, 13);
			this->labelForArrSize->TabIndex = 18;
			this->labelForArrSize->Text = L"���� ������� �������:";
			// 
			// labelForTests2
			// 
			this->labelForTests2->AutoSize = true;
			this->labelForTests2->Location = System::Drawing::Point(427, 178);
			this->labelForTests2->Name = L"labelForTests2";
			this->labelForTests2->Size = System::Drawing::Size(210, 52);
			this->labelForTests2->TabIndex = 19;
			this->labelForTests2->Text = L"�������� 1000 ��������: \r\n�������� � ���������� 1000 ��������:\r\n������� ����� ���"
				L"������ 1 �������: \r\n�������� 1000 ��������: \r\n";
			// 
			// labelForTests3
			// 
			this->labelForTests3->AutoSize = true;
			this->labelForTests3->Location = System::Drawing::Point(427, 253);
			this->labelForTests3->Name = L"labelForTests3";
			this->labelForTests3->Size = System::Drawing::Size(216, 52);
			this->labelForTests3->TabIndex = 20;
			this->labelForTests3->Text = L"�������� 10000 ��������: \r\n�������� � ���������� 10000 ��������:\r\n������� ����� �"
				L"�������� 1 �������: \r\n�������� 10000 ��������: \r\n";
			// 
			// labelForPattern
			// 
			this->labelForPattern->AutoSize = true;
			this->labelForPattern->Location = System::Drawing::Point(427, 62);
			this->labelForPattern->Name = L"labelForPattern";
			this->labelForPattern->Size = System::Drawing::Size(145, 13);
			this->labelForPattern->TabIndex = 21;
			this->labelForPattern->Text = L"����� ���������� ������:";
			// 
			// MainScreen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(699, 379);
			this->Controls->Add(this->labelForPattern);
			this->Controls->Add(this->labelForTests3);
			this->Controls->Add(this->labelForTests2);
			this->Controls->Add(this->labelForArrSize);
			this->Controls->Add(this->labelForTests1);
			this->Controls->Add(this->Tests);
			this->Controls->Add(this->arrSize);
			this->Controls->Add(this->randomInput);
			this->Controls->Add(this->labelForArrInput);
			this->Controls->Add(this->arrayForSort);
			this->Controls->Add(this->EditArray);
			this->Controls->Add(this->EnterArray);
			this->Controls->Add(this->EnterringArray);
			this->Controls->Add(this->SortArray);
			this->Controls->Add(this->SelectArray);
			this->Controls->Add(this->getArraysFromDB);
			this->Controls->Add(this->arraysFromDB);
			this->Controls->Add(this->buttonForInsert);
			this->Controls->Add(this->textBoxForArray);
			this->Controls->Add(this->exitButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MainScreen";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainScreen";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
		   /// <summary>
		   /// ���������� ������� � ���� ������ ��� ������� �������������� ������
		   /// </summary>
		   /// <param name="sender"></param>
		   /// <param name="e"></param>
		   /// <returns></returns>
	private: System::Void buttonForInsert_Click(System::Object^ sender, System::EventArgs^ e);
		   /// <summary>
		   /// ��������� �������� �� ���� ������ � ���������� ������ ��� ������� �������������� ������
		   /// </summary>
		   /// <param name="sender"></param>
		   /// <param name="e"></param>
		   /// <returns></returns>
	private: System::Void getArraysFromDB_Click(System::Object^ sender, System::EventArgs^ e);
		   /// <summary>
		   /// ��������� ��������� ������ �� ���������� ���� � ���� ��� �������������� ������� � ��� ����������
		   /// </summary>
		   /// <param name="sender"></param>
		   /// <param name="e"></param>
		   /// <returns></returns>
	private: System::Void SelectArray_Click(System::Object^ sender, System::EventArgs^ e);
		   /// <summary>
		   /// ������� ���������� �������, �������� ����� � ���������
		   /// </summary>
		   /// <param name="sender"></param>
		   /// <param name="e"></param>
		   /// <returns></returns>
	private: System::Void SortArray_Click(System::Object^ sender, System::EventArgs^ e);
		   /// <summary>
		   ///  ��������� ��������� ������ �� ����������� ������ � ���� ��� �������������� ������� � ��� ����������
		   /// </summary>
		   /// <param name="sender"></param>
		   /// <param name="e"></param>
		   /// <returns></returns>
	private: System::Void EnterArray_Click(System::Object^ sender, System::EventArgs^ e);
		   /// <summary>
		   /// ������� ��� ���������� ������ ������� � ���� ������
		   /// </summary>
		   /// <param name="sender"></param>
		   /// <param name="e"></param>
		   /// <returns></returns>
	private: System::Void EditArray_Click(System::Object^ sender, System::EventArgs^ e);
		   /// <summary>
		   /// ������� ��� ��������� ��������� �������
		   /// </summary>
		   /// <param name="sender"></param>
		   /// <param name="e"></param>
		   /// <returns></returns>
	private: System::Void randomInput_Click(System::Object^ sender, System::EventArgs^ e);
		   /// <summary>
		   /// ������� ������� ��������� ������
		   /// </summary>
		   /// <param name="sender"></param>
		   /// <param name="e"></param>
		   /// <returns></returns>
	private: System::Void Tests_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
