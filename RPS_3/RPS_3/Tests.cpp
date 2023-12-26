#include "Tests.h"
#include "Functions.h"
#include "MainScreen.h"
#include "Class.h"

Tests::Tests()
{
}

bool Tests::Test1()
{
	try {
		auto start = std::chrono::steady_clock::now();
		Functions f;
		QuickSort sort;
		srand(static_cast<unsigned int>(time(NULL)));
		int min = 1;
		int max = 10;
		ClassArrays^ a = gcnew ClassArrays();

		for (int i = 0; i < 100; i++) {
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
		timeForTest1 = Convert::ToString(std::chrono::duration_cast<std::chrono::seconds>(end - start).count());
		return true;
	}
	catch (...) {
		return false;
	}
}

bool Tests::Test2()
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
		timeForTest2 = Convert::ToString(std::chrono::duration_cast<std::chrono::seconds>(end - start).count());
		return true;
	}
	catch (...) {
		return false;
	}
}

bool Tests::Test3()
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
		timeForTest3 = Convert::ToString(std::chrono::duration_cast<std::chrono::seconds>(end - start).count());
		return true;
	}
	catch (...) {
		return false;
	}
}

bool Tests::Test4()
{
	try {
		Functions f;
		auto start = std::chrono::steady_clock::now();
		f.SelectTest();
		auto end = std::chrono::steady_clock::now();
		String^ timeForTest4 = Convert::ToString(std::chrono::duration_cast<std::chrono::seconds>(end - start).count());
		String^ timeForArr100 = Convert::ToString(Convert::ToInt32(timeForTest4) / 100);
		String^ timeForArr1000 = Convert::ToString(Convert::ToInt32(timeForTest4) / 1000);
		String^ timeForArr10000 = Convert::ToString(Convert::ToInt32(timeForTest4) / 10000);
		return true;
	}
	catch (...) {
		return false;
	}
}

bool Tests::Test5()
{
	try {
		Functions f;
		f.DeleteTest();
		return true;
	}
	catch (...) {
		return false;
	}
}