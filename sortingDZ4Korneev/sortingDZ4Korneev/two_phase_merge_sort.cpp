#include "two_phase_merge_sort.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

template<typename T>
void two_phase_merge_sort(std::vector<T>& arr) {
    size_t n = arr.size();
    if (n <= 1) return;

    //  записать в f.txt 
    {
        std::ofstream f_out("f.txt");
        for (const T& x : arr) {
            f_out << x << '\n';
        }
    }

    size_t len = 1;

    while (len < n) {
        // Распределение f.txt → g.txt и t.txt 
        std::ifstream f_in("f.txt");
        std::ofstream g_out("g.txt");
        std::ofstream t_out("t.txt");

        bool to_g = true;
        size_t count_in_series = 0;
        T val;

        while (f_in >> val) {
            if (to_g) {
                g_out << val << '\n';
            }
            else {
                t_out << val << '\n';
            }

            if (++count_in_series == len) {
                to_g = !to_g;
                count_in_series = 0;
            }
        }

        f_in.close();
        g_out.close();
        t_out.close();

        
        auto read_series = [&](std::ifstream& in, size_t l) -> std::vector<T> {
            std::vector<T> series;
            T v;
            for (size_t i = 0; i < l && (in >> v); ++i) {
                series.push_back(v);
            }
            return series;
            };

        // Слияние g.txt + t.txt → f.txt 
        std::ifstream g_in("g.txt");
        std::ifstream t_in("t.txt");
        std::ofstream f_out("f.txt");

        while (true) {
            auto series_g = read_series(g_in, len);
            auto series_t = read_series(t_in, len);

            if (series_g.empty() && series_t.empty()) break;

            size_t i = 0, j = 0;
            while (i < series_g.size() && j < series_t.size()) {
                if (series_g[i] <= series_t[j]) {
                    f_out << series_g[i] << '\n';
                    ++i;
                }
                else {
                    f_out << series_t[j] << '\n';
                    ++j;
                }
            }
            while (i < series_g.size()) {
                f_out << series_g[i] << '\n';
                ++i;
            }
            while (j < series_t.size()) {
                f_out << series_t[j] << '\n';
                ++j;
            }
        }

        g_in.close();
        t_in.close();
        f_out.close();

        len *= 2;
    }

    
    std::ifstream result_in("f.txt");
    for (size_t i = 0; i < n && (result_in >> arr[i]); ++i) {
        
    }
    result_in.close();

    
    std::remove("g.txt");
    std::remove("t.txt");
}


template void two_phase_merge_sort<int>(std::vector<int>&);
template void two_phase_merge_sort<double>(std::vector<double>&);
template void two_phase_merge_sort<float>(std::vector<float>&);
template void two_phase_merge_sort<char>(std::vector<char>&);