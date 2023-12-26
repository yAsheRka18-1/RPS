#pragma once


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Data;
using namespace Data::SqlClient;

ref class ClassArrays
{
public:
	ClassArrays();

	static int idArray;
	static property int IDArray
	{
		int get() {
			return idArray;
		}
		void set(int value) {
			idArray = value;
		}
	}

	static String^ arrayValues;
	static property String^ ArrayValues
	{
		String^ get() {
			return arrayValues;
		}
		void set(String^ value) {
			arrayValues = value;
		}
	}

	static bool sortingStatus;
	static property int SortingStatus
	{
		int get() {
			return sortingStatus;
		}
		void set(int value) {
			sortingStatus = value;
		}
	}


};

