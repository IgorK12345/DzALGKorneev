#include "shakerSort.h"
#include <vector>

template<typename T>
int shakerSort(std::vector<T>& arr) {
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


template int shakerSort<int>(std::vector<int>&);
template int shakerSort<double>(std::vector<double>&);
template int shakerSort<float>(std::vector<float>&);
template int shakerSort<char>(std::vector<char>&);
