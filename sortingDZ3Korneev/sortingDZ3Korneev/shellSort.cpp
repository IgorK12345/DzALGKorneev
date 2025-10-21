#include "shellSort.h"

#include <vector>
#include <algorithm>

template<typename T>
void shellSort(std::vector<T>& arr) {
    int n = arr.size();
    if (n <= 1) return;

    int gap = 1;
    while (gap < n / 3) {
        gap = 3 * gap + 1;
    }

    while (gap >= 1) {
        for (int i = gap; i < n; i++) {
            T t = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > t) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = t;
        }
        gap = gap / 3;
    }
}

template void shellSort<int>(std::vector<int>&);
template void shellSort<double>(std::vector<double>&);
template void shellSort<float>(std::vector<float>&);
template void shellSort<char>(std::vector<char>&);
