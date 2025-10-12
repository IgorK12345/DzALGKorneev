#include "Bubble.h"
#include <vector>

template<typename T>
int bubble_sort(std::vector<T>& arr) {
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


template int bubble_sort<int>(std::vector<int>&);
template int bubble_sort<double>(std::vector<double>&);
template int bubble_sort<float>(std::vector<float>&);
template int bubble_sort<char>(std::vector<char>&);
