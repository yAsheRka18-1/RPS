#pragma once
#include"class.h"
#include <fstream>

enum MenuForInput { console = 1, file, random, quit };
enum SavingMenu { savetofile = 1, back2 };
enum WitchOneSave { original = 1, sorted, back3 };
enum OverwriteOrNot { overwrite = 1, create };
void Borders();
void Task();
void MenuForInput();
void SavingMenu();
void WitchOneSave();
void ConcoleInput(vector<int>& arr, int& sizeOfArr);
void RandomInput(vector<int>& arr, int& sizeOfArr);
bool FileInput(vector<int>& arr, string name);
void PrintArr(vector<int>& arr);
vector<int> SortWithCertainMethod(shared_ptr<ISort> sort, vector<int>& arr);
void SaveOriginalArr(vector<int>& arr);
void SaveSortedArr(vector<int>& arr);
