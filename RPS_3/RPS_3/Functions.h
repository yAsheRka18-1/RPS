#pragma once
#include "ClassArrays.h"
#include <vector>
#include "time.h"
#include "Class.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Data;
using namespace Data::SqlClient;

ref class Functions
{
public:
	Functions();
	SqlConnection^ conn;  // Объект подключения к базе данных
	SqlConnectionStringBuilder^ connStringBuilder;  // Строка подключения к базе данных
	void ConnectToDB();  // Метод для установки соединения с базой данных
public:
	void RandomInput(std::vector<int>& arr, int& sizeOfArr);
	void Insert(ClassArrays^ a);  // Метод для вставки новой записи в базу данных
	void InsertTest(ClassArrays^ a);
	void DeleteTest();
	ListBox::ObjectCollection^ FillComboBox();  // Метод для заполнения ComboBox данными из базы данных
	void SelectTest();
	void Update(ClassArrays^ aOld, ClassArrays^ aNew);  // Метод для обновления записи в базе данных
};