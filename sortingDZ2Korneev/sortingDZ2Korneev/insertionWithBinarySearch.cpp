#include "insertionWithBinarySearch.h"
#include <algorithm>
#include <vector>

template<typename T>
int binarySearch(const std::vector<T>& arr, int x, int a, int b) {
    while (a <= b) {
        int mid = a + (b - a) / 2;

        if (x == arr[mid])
            return mid + 1;
        else if (x > arr[mid])
            a = mid + 1;
        else
            b = mid - 1;
    }
    return a;
}

template<typename T>
void insertionWithBinarySearch(std::vector<T>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;

        
        int pos = binarySearch(arr, key, 0, j);

        while (j >= pos) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


template void insertionWithBinarySearch<int>(std::vector<int>&);
template void insertionWithBinarySearch<double>(std::vector<double>&);
template void insertionWithBinarySearch<float>(std::vector<float>&);
template void insertionWithBinarySearch<char>(std::vector<char>&);

//template int binarySearch<int>(std::vector<int>&);
//template void binarySearch<double>(std::vector<double>&);
//template void binarySearch<float>(std::vector<float>&);
//template void binarySearch<char>(std::vector<char>&);
