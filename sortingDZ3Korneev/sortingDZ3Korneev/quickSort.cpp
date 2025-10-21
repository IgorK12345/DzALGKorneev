#include "quickSort.h"

#include <vector>
#include <algorithm>

template<typename T>
int partition(std::vector<T>& arr, int a, int b) {
    T pivot = arr[b];
    int i = a - 1;      

    for (int j = a; j < b; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[b]);
    return i + 1;
}

template<typename T>
void quickSortRecursive(std::vector<T>& arr, int a, int b) {
    if (a < b) {
        int pi = partition(arr, a, b);

        quickSortRecursive(arr, a, pi - 1);
        quickSortRecursive(arr, pi + 1, b);
    }
}

template<typename T>
void quickSort(std::vector<T>& arr) {
    if (arr.size() <= 1) return;
    quickSortRecursive(arr, 0, arr.size() - 1);
}
template void quickSort<int>(std::vector<int>&);
template void quickSort<double>(std::vector<double>&);
template void quickSort<float>(std::vector<float>&);
template void quickSort<char>(std::vector<char>&);
