#include "shakerSort.h"
#include <vector>
#include <algorithm>

template<typename T>
void shakerSort(std::vector<T>& arr) {
    int n = arr.size();
    if (n <= 1) return;

    int l = 0;
    int r = n - 1;
    bool flag = true;

    while (flag&& l < r) {
        flag = false;

        for (int i = l; i < r; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                flag = true;
            }
        }

        if (!flag) break;

        flag = false;
        r--; 

        for (int i = r; i > l; i--) {
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                flag = true;
            }
        }

        l++;
    }
}

template void shakerSort<int>(std::vector<int>&);
template void shakerSort<double>(std::vector<double>&);
template void shakerSort<float>(std::vector<float>&);
template void shakerSort<char>(std::vector<char>&);
