#include "Functions.h"

Functions::Functions()
{
}

void Functions::ConnectToDB()
{
	connStringBuilder = gcnew SqlConnectionStringBuilder();
	connStringBuilder->DataSource = "127.0.0.1, 1433";
	connStringBuilder->InitialCatalog = "RPS3";
	connStringBuilder->IntegratedSecurity = true;
	conn = gcnew SqlConnection(Convert::ToString(connStringBuilder));
}

void Functions::RandomInput(std::vector<int>& arr, int& sizeOfArr)
{
	arr.assign(sizeOfArr, 0);
	srand(static_cast<unsigned int>(time(NULL)));
	int min = -100;
	int max = 100;

	for (int i = 0; i < sizeOfArr; i++) {
		arr[i] = min + rand() % (max - min + 1);
	}
}

void Functions::Insert(ClassArrays^ a, String^ dataBase)
{
	try {
		ConnectToDB();
		DateTime localDate = localDate.Now;
		String^ cmdText = "INSERT INTO dbo." + dataBase + "(ArrayValues, sortingStatus, dateOfAdd) VALUES(@ArrayValuesVstavka, @sortingStatus, @dateOfAdd)";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		cmd->Parameters->AddWithValue("@ArrayValuesVstavka", a->ArrayValues);
		cmd->Parameters->AddWithValue("@sortingStatus", a->SortingStatus);
		cmd->Parameters->AddWithValue("@dateOfAdd", Convert::ToString(localDate));
		conn->Open();
		cmd->ExecuteNonQuery();
	}
	finally {
		if (conn != nullptr) {
			conn->Close();
		}
	}
}

void Functions::DeleteTest()
{
	try {
		ConnectToDB();
		String^ cmdText = "DELETE FROM dbo.ArraysTest";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		conn->Open();
		SqlDataReader^ reader = cmd->ExecuteReader();

		while (reader->Read()) {
			cmd->ExecuteNonQuery();
		}
	}
	finally {
		if (conn != nullptr) {
			conn->Close();
		}
	}
}

ListBox::ObjectCollection^ Functions::FillComboBox()
{
	try {
		ConnectToDB();
		ListBox^ ListWithArrays = gcnew ListBox();
		ClassArrays^ a = gcnew ClassArrays();
		String^ cmdText = "SELECT * FROM dbo.Arrays";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		conn->Open();
		SqlDataReader^ reader = cmd->ExecuteReader();

		while (reader->Read()) {
			a->IDArray = Convert::ToInt32(reader["idArray"]->ToString());
			a->ArrayValues = reader["ArrayValues"]->ToString();
			a->SortingStatus = Convert::ToBoolean(reader["sortingStatus"]->ToString());
			ListWithArrays->Items->Add(String::Format("{0}:{1}:{2}", a->IDArray, a->ArrayValues, a->SortingStatus));
		};

		return ListWithArrays->Items;
	}
	finally {
		if (conn != nullptr) {
			conn->Close();
		}
	}
}

void Functions::SelectTest()
{
	try {
		ConnectToDB();
		ClassArrays^ a = gcnew ClassArrays();
		String^ cmdText = "SELECT * FROM dbo.Arrays";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		conn->Open();
		SqlDataReader^ reader = cmd->ExecuteReader();

		while (reader->Read()) {
			a->ArrayValues = reader["ArrayValues"]->ToString();
			a->SortingStatus = Convert::ToBoolean(reader["sortingStatus"]->ToString());

			if (a->SortingStatus == 1) {
				continue;
			}
			else {
				QuickSort sort;
				std::vector<int> arr;
				String^ sortedArr = "";
				array<String^>^ parts = a->ArrayValues->Split((Char)' ');
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
			}
		};
	}
	finally {
		if (conn != nullptr) {
			conn->Close();
		}
	}
}

void Functions::Update(ClassArrays^ aOld, ClassArrays^ aNew)
{
	try {
		ConnectToDB();
		String^ cmdText = "UPDATE dbo.Arrays SET ArrayValues = @ArrayValues, sortingStatus = @sortingStatus  WHERE idArray = @idArray";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		cmd->Parameters->AddWithValue("@ArrayValues", aNew->ArrayValues);
		cmd->Parameters->AddWithValue("@idArray", aOld->IDArray);
		cmd->Parameters->AddWithValue("@sortingStatus", aNew->SortingStatus);
		conn->Open();
		cmd->ExecuteNonQuery();
	}
	finally {
		if (conn != nullptr) {
			conn->Close();
		}
	}
}
