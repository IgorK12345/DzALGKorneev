#include "Exchange.h"
#include <vector>

template<typename T>
int exchenge_sort(std::vector<T>& arr) {
    if (arr.size() == 0) return 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                T x = arr[i];
                arr[i] = arr[j];
                arr[j] = x;
            }
        }
    }
    return 0;
}


template int exchenge_sort<int>(std::vector<int>&);
template int exchenge_sort<double>(std::vector<double>&);
template int exchenge_sort<float>(std::vector<float>&);
template int exchenge_sort<char>(std::vector<char>&);