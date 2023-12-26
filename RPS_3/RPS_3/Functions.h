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
	SqlConnection^ conn;
	SqlConnectionStringBuilder^ connStringBuilder;
	void ConnectToDB();
public:
	void RandomInput(std::vector<int>& arr, int& sizeOfArr);
	void Insert(ClassArrays^ a, String^ dataBase);
	void DeleteTest();
	ListBox::ObjectCollection^ FillComboBox();
	void SelectTest();
	void Update(ClassArrays^ aOld, ClassArrays^ aNew);
};