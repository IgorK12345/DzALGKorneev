#include "Insertion.h"
#include <vector>

template<typename T>
int insertion_sort(std::vector<T>& arr) {
    if (arr.size() == 0 || arr.size() == 1) return 0;
    for (int i = 1; i < arr.size(); i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                T x = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = x;
            }
        }
    }
    return 0;
}


template int insertion_sort<int>(std::vector<int>&);
template int insertion_sort<double>(std::vector<double>&);
template int insertion_sort<float>(std::vector<float>&);
template int insertion_sort<char>(std::vector<char>&);