#include "Selection.h"
#include <vector>

template<typename T>
int selection_sort(std::vector<T>& arr) {
    if (arr.size() == 0) return 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        T min = arr[i];
        int min_id = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < min) {
                min = arr[j];
                min_id = j;
            }
        }
        arr[min_id] = arr[i];
        arr[i] = min;
    }
    return 0;
}


template int selection_sort<int>(std::vector<int>&);
template int selection_sort<double>(std::vector<double>&);
template int selection_sort<float>(std::vector<float>&);
template int selection_sort<char>(std::vector<char>&);