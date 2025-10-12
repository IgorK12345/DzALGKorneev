#include "OptimizedBubble.h"
#include <vector>
#include <iostream>


template<typename T>
int optimizedbubble_sort(std::vector<T>& arr) {
    if (arr.size() == 0) return 0;
    for (int i = 0; i < arr.size(); i++) {
        int f = 0;
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T x = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = x;
                f = 1;
            }
        }
        if (f == 0) {
            break;
        }
    
    }
    return 0;
}


template int optimizedbubble_sort<int>(std::vector<int>&);
template int optimizedbubble_sort<double>(std::vector<double>&);
template int optimizedbubble_sort<float>(std::vector<float>&);
template int optimizedbubble_sort<char>(std::vector<char>&);