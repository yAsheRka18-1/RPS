#include "Test.h"

bool Test::Test1(int numberOfArr)
{
	try {
		auto start = std::chrono::steady_clock::now();
		Functions f;
		QuickSort sort;
		srand(static_cast<unsigned int>(time(NULL)));
		int min = 1;
		int max = 10;
		ClassArrays^ a = gcnew ClassArrays();

		for (int i = 0; i < numberOfArr; i++) {
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
				else {
					a->SortingStatus = 1;
				}
			}

			f.Insert(a, "ArraysTest");
		}
		auto end = std::chrono::steady_clock::now();
		timeForTest1 = Convert::ToString(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
		return true;
	}
	catch (...) {
		return false;
	}
}

bool Test::Test2()
{
	try {
		Functions f;
		auto start = std::chrono::steady_clock::now();
		f.SelectTest();
		auto end = std::chrono::steady_clock::now();
		timeForTest2 = Convert::ToString(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
		timeForArr100 = Convert::ToString(Convert::ToInt32(timeForTest2) / 100);
		timeForArr1000 = Convert::ToString(Convert::ToInt32(timeForTest2) / 1000);
		timeForArr10000 = Convert::ToString(Convert::ToInt32(timeForTest2) / 10000);
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
		f.DeleteTest();
		auto end = std::chrono::steady_clock::now();
		timeForTest3 = Convert::ToString(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
		return true;
	}
	catch (...) {
		return false;
	}
}
