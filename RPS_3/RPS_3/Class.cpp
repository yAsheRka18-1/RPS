#include "Functions.h"

Functions::Functions()
{
}

void Functions::ConnectToDB()
{
	// Создание строки подключения к базе данных
	connStringBuilder = gcnew SqlConnectionStringBuilder();
	connStringBuilder->DataSource = "127.0.0.1, 1433";  // IP-адрес и порт сервера базы данных
	connStringBuilder->InitialCatalog = "RPS3";  // Имя базы данных
	connStringBuilder->IntegratedSecurity = true;  // Использование Windows-аутентификации
	conn = gcnew SqlConnection(Convert::ToString(connStringBuilder));  //создает новый объект SqlConnection, который представляет собой соединение с базой данных
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

// Метод для вставки новой записи в базу данных
void Functions::Insert(ClassArrays^ a)
{
	try {
		ConnectToDB();  // Установка соединения с базой данных
		DateTime localDate = localDate.Now;  // Получение текущей даты и времени
		String^ cmdText = "INSERT INTO dbo.Arrays(ArrayValues, sortingStatus, dateOfAdd) VALUES(@ArrayValuesVstavka, @sortingStatus, @dateOfAdd)";
		// Подготовка SQL-команды с параметрами
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

void Functions::InsertTest(ClassArrays^ a)
{
	try {
		ConnectToDB();
		DateTime localDate = localDate.Now;
		String^ cmdText = "INSERT INTO dbo.ArraysTest(ArrayValues, sortingStatus, dateOfAdd) VALUES(@ArrayValuesVstavka, @sortingStatus, @dateOfAdd)";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		cmd->Parameters->AddWithValue("@ArrayValuesVstavka", a->ArrayValues);
		cmd->Parameters->AddWithValue("@sortingStatus", a->SortingStatus);
		cmd->Parameters->AddWithValue("@dateOfAdd", Convert::ToString(localDate));
		conn->Open();  // Открытие соединения с базой данных
		cmd->ExecuteNonQuery();  // Выполнение SQL-команды без возврата данных
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

		// Перебор результатов чтения и выполнение DELETE-команды для каждой записи
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

// Метод для заполнения ComboBox данными из базы данных
ListBox::ObjectCollection^ Functions::FillComboBox()
{
	try {
		ConnectToDB();
		ListBox^ ListWithArrays = gcnew ListBox();  // Создание ListBox для хранения данных
		ClassArrays^ a = gcnew ClassArrays();
		String^ cmdText = "SELECT * FROM dbo.Arrays";  // SQL-команда для выборки данных из основной таблицы
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		conn->Open();
		SqlDataReader^ reader = cmd->ExecuteReader();

		// Перебор результатов чтения и добавление элементов в ListBox
		while (reader->Read()) {
			a->IDArray = Convert::ToInt32(reader["idArray"]->ToString());
			a->ArrayValues = reader["ArrayValues"]->ToString();
			a->SortingStatus = Convert::ToBoolean(reader["sortingStatus"]->ToString());
			ListWithArrays->Items->Add(String::Format("{0}:{1}:{2}", a->IDArray, a->ArrayValues, a->SortingStatus));
		};

		return ListWithArrays->Items;  // Возвращение коллекции элементов ListBox
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

		// Перебор результатов чтения
		while (reader->Read()) {
			a->ArrayValues = reader["ArrayValues"]->ToString();
			a->SortingStatus = Convert::ToBoolean(reader["sortingStatus"]->ToString());

			if (a->SortingStatus == 1) {
				continue;  // Пропуск сортированных массивов
			}
			// Сортировка и обработка данных, если массив не отсортирован
			else {
				QuickSort sort;
				std::vector<int> arr;
				String^ sortedArr = "";
				array<String^>^ parts = a->ArrayValues->Split((Char)' ');
				arr.assign(parts->Length, 0);

				// Преобразование строковых элементов массива в целочисленные значения
				for (int i = 0; i < parts->Length; i++) {
					arr[i] = Int32::Parse(parts[i]);
				}

				arr = sort.Qsort(arr);

				// Формирование строки с отсортированными значениями массива
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
		ConnectToDB();  // Установка соединения с базой данных
		String^ cmdText = "UPDATE dbo.Arrays SET ArrayValues = @ArrayValues, sortingStatus = @sortingStatus  WHERE idArray = @idArray";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);

		// Передача параметров для обновления
		cmd->Parameters->AddWithValue("@ArrayValues", aNew->ArrayValues);
		cmd->Parameters->AddWithValue("@idArray", aOld->IDArray);
		cmd->Parameters->AddWithValue("@sortingStatus", aNew->SortingStatus);
		conn->Open();
		cmd->ExecuteNonQuery();  // Выполнение SQL-запроса для обновления данных
	}
	finally {
		if (conn != nullptr) {
			conn->Close();
		}
	}
}
