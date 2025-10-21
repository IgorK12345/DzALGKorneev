#include "insertionWithBinarySearch.h"

#include <vector>

template<typename T>
int insertionWithBinarySearch(std::vector<T>& arr) {
    if (arr.size() == 0) return 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size() - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T x = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = x;
            }
        }
    }
    return 0;
}


template int insertionWithBinarySearch<int>(std::vector<int>&);
template int insertionWithBinarySearch<double>(std::vector<double>&);
template int insertionWithBinarySearch<float>(std::vector<float>&);
template int insertionWithBinarySearch<char>(std::vector<char>&);
