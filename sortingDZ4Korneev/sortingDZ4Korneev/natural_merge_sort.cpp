#include "natural_merge_sort.h"
#include <vector>
#include <fstream>
#include <algorithm>

template<typename T>
void natural_merge_sort(std::vector<T>& arr) {
    size_t n = arr.size();
    if (n <= 1) return;

    // Записываем в f.txt
    {
        std::ofstream f_out("f.txt");
        for (const T& x : arr) f_out << x << '\n';
    }

    bool changed = true;
    while (changed) {
        changed = false;

        // f.txt в g.txt и h.txt
        std::ifstream f_in("f.txt");
        std::ofstream g_out("g.txt");
        std::ofstream h_out("h.txt");

        T prev, curr;
        bool first = true;
        bool to_g = true;

        while (f_in >> curr) {
            if (!first && curr < prev) {
    
                to_g = !to_g;
                changed = true; 
            }

            if (to_g) g_out << curr << '\n';
            else      h_out << curr << '\n';

            prev = curr;
            first = false;
        }

        f_in.close();
        g_out.close();
        h_out.close();

        if (!changed) break;  

        std::ifstream g_in("g.txt");
        std::ifstream h_in("h.txt");
        std::ofstream f_out("f.txt");

        auto read_natural_series = [&](std::ifstream& in) -> std::vector<T> {
            std::vector<T> s;
            T val;
            if (!(in >> val)) return s;
            s.push_back(val);

            T next;
            while (in >> next) {
                if (next < val) {  
                    in.putback(static_cast<char>(next));  
                    
                    break;
                }
                s.push_back(next);
                val = next;
            }
            return s;
            };

        
        struct SeriesReader {
            std::ifstream& in;
            T next_val;
            bool has_next = false;

            SeriesReader(std::ifstream& stream) : in(stream) {
                if (in >> next_val) has_next = true;
            }

            std::vector<T> next_series() {
                std::vector<T> s;
                if (!has_next) return s;

                T last = next_val;
                s.push_back(last);
                has_next = false;

                T val;
                while (in >> val) {
                    if (val < last) {
                       
                        next_val = val;
                        has_next = true;
                        break;
                    }
                    s.push_back(val);
                    last = val;
                }
                return s;
            }
        };

        SeriesReader g_reader(g_in);
        SeriesReader h_reader(h_in);

        while (true) {
            auto s1 = g_reader.next_series();
            auto s2 = h_reader.next_series();

            if (s1.empty() && s2.empty()) break;

            size_t i = 0, j = 0;
            while (i < s1.size() && j < s2.size()) {
                if (s1[i] <= s2[j]) f_out << s1[i++] << '\n';
                else                f_out << s2[j++] << '\n';
            }
            while (i < s1.size()) f_out << s1[i++] << '\n';
            while (j < s2.size()) f_out << s2[j++] << '\n';
        }

        g_in.close();
        h_in.close();
        f_out.close();
    }

   
    std::ifstream result_in("f.txt");
    for (size_t i = 0; i < n && (result_in >> arr[i]); ++i) {}
    result_in.close();
}


template void natural_merge_sort<int>(std::vector<int>&);
template void natural_merge_sort<double>(std::vector<double>&);
template void natural_merge_sort<float>(std::vector<float>&);
template void natural_merge_sort<char>(std::vector<char>&);