#include "Test.h"

bool Test::Test1()
{
	try {
		auto start = std::chrono::steady_clock::now();   //записывает текущее время для последующего измерения времени выполнения кода
		Functions f;
		QuickSort sort;
		srand(static_cast<unsigned int>(time(NULL)));  //инициализация генератора случайных чисел
		int min = 1;
		int max = 10;
		ClassArrays^ a = gcnew ClassArrays();

		//Цикл, который повторяется 100 раз для проведения 100 тестов
		for (int i = 0; i < 100; i++) {
			int sizeOfArr = min + rand() % (max - min + 1);
			std::vector<int> arr;
			std::vector<int> res;
			String^ sortedArr = "";
			f.RandomInput(arr, sizeOfArr);   //заполняет массив случайными числами

			//Цикл для формирования строки sortedArr из элементов массива
			for (int i = 0; i < sizeOfArr; i++) {

				if (i != sizeOfArr - 1) {
					sortedArr = sortedArr + arr[i] + " ";
				}
				else {
					sortedArr = sortedArr + arr[i];
				}
			}

			a->ArrayValues = sortedArr;
			res = sort.Qsort(arr);

			//Цикл для сравнения элементов отсортированного массива с исходным
			for (int i = 0; i < sizeOfArr; i++) {

				if (arr[i] != res[i]) {
					a->SortingStatus = 0;
				}
				else if (i != sizeOfArr - 1) {
					continue;
				}
				else {
					a->SortingStatus = 1;
				}
			}

			f.InsertTest(a);   //Вставка объекта a в базу данных с использованием функции InsertTest из объекта f
		}
		auto end = std::chrono::steady_clock::now();   // //Измерение времени выполнения теста
		timeForTest1 = Convert::ToString(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());  //сохранение времени в строку timeForTest1
		return true;
	}
	catch (...) {
		return false;
	}
}

bool Test::Test2()
{
	try {
		auto start = std::chrono::steady_clock::now();
		Functions f;
		QuickSort sort;
		srand(static_cast<unsigned int>(time(NULL)));
		int min = 1;
		int max = 10;
		ClassArrays^ a = gcnew ClassArrays();

		for (int i = 0; i < 1000; i++) {
			int sizeOfArr = min + rand() % (max - min + 1);
			std::vector<int> arr;
			std::vector<int> res;
			String^ sortedArr = "";
			f.RandomInput(arr, sizeOfArr);

			for (int i = 0; i < sizeOfArr; i++) {

				// Формирование строки sortedArr из элементов массива
				if (i != sizeOfArr - 1) {
					sortedArr = sortedArr + arr[i] + " ";
				}
				else {
					sortedArr = sortedArr + arr[i];
				}
			}

			a->ArrayValues = sortedArr;
			res = sort.Qsort(arr);

			for (int i = 0; i < sizeOfArr; i++) {

				// Сравнение отсортированного массива с исходным
				if (arr[i] != res[i]) {
					a->SortingStatus = 0;
				}
				else if (i != sizeOfArr - 1) {
					continue;
				}
				else {
					a->SortingStatus = 1;
				}
			}

			f.InsertTest(a);   // Вставка объекта ClassArrays в базу данных
		}
		auto end = std::chrono::steady_clock::now();
		// Измерение времени выполнения теста и сохранение в переменную timeForTest2
		timeForTest2 = Convert::ToString(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
		return true;
	}
	catch (...) {
		return false;
	}
}

bool Test::Test3()
{
	try {
		auto start = std::chrono::steady_clock::now();
		Functions f;
		QuickSort sort;
		srand(static_cast<unsigned int>(time(NULL)));
		int min = 1;
		int max = 10;
		ClassArrays^ a = gcnew ClassArrays();

		for (int i = 0; i < 10000; i++) {
			int sizeOfArr = min + rand() % (max - min + 1);
			std::vector<int> arr;
			std::vector<int> res;
			String^ sortedArr = "";
			f.RandomInput(arr, sizeOfArr);

			for (int i = 0; i < sizeOfArr; i++) {

				if (i != sizeOfArr - 1) {
					sortedArr = sortedArr + arr[i] + " ";
				}
				else {
					sortedArr = sortedArr + arr[i];
				}
			}

			a->ArrayValues = sortedArr;
			res = sort.Qsort(arr);

			for (int i = 0; i < sizeOfArr; i++) {

				if (arr[i] != res[i]) {
					a->SortingStatus = 0;
				}
				else if (i != sizeOfArr - 1) {
					continue;
				}
				else {
					a->SortingStatus = 1;
				}
			}

			f.InsertTest(a);
		}
		auto end = std::chrono::steady_clock::now();
		timeForTest3 = Convert::ToString(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
		return true;
	}
	catch (...) {
		return false;
	}
}

bool Test::Test4()
{
	try {
		Functions f;
		auto start = std::chrono::steady_clock::now();   // Вызов функции SelectTest для выборки данных из базы данных
		f.SelectTest();
		auto end = std::chrono::steady_clock::now();
		timeForTest4 = Convert::ToString(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());  // Измерение времени выполнения теста и сохранение в переменную timeForTest4
		// Вычисление времени выполнения для массивов разных размеров
		timeForArr100 = Convert::ToString(Convert::ToInt32(timeForTest4) / 100);
		timeForArr1000 = Convert::ToString(Convert::ToInt32(timeForTest4) / 1000);
		timeForArr10000 = Convert::ToString(Convert::ToInt32(timeForTest4) / 10000);
		return true;
	}
	catch (...) {
		return false;
	}
}

bool Test::Test5()
{
	try {
		auto start = std::chrono::steady_clock::now();
		Functions f;
		f.DeleteTest();  // Вызов функции DeleteTest для удаления данных из базы данных
		auto end = std::chrono::steady_clock::now();
		timeForTest5 = Convert::ToString(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
		return true;
	}
	catch (...) {
		return false;
	}
}
