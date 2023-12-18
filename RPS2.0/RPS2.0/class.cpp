#include "class.h"

string QuickSort::NameOfSort() {
    return "Quick Sort\n";
}

void QuickSort::Permutations(vector<int>& arr, int first, int second) {
    swap(arr[first], arr[second]);
}

bool QuickSort::Compare(int a, int b) {
    return a > b;
}

vector<int> QuickSort::Qsort(vector<int>& arr) {
    if (arr.size() < 2) {
        return arr;
    }
    else {
        int pivot = arr[arr.size() / 2];
        vector<int> leftPart;
        vector<int> rightPart;
        int pivot_counter = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == pivot) {
                pivot_counter++;
                continue;
            }

            if (arr[i] < pivot) { leftPart.push_back(arr[i]); }
            else { rightPart.push_back(arr[i]); }


        }
        leftPart = Qsort(leftPart);
        rightPart = Qsort(rightPart);
        vector <int> res(leftPart.begin(), leftPart.end());
        res.insert(res.end(), pivot_counter, pivot);
        res.insert(res.end(), rightPart.begin(), rightPart.end());
        return res;

    }
}
