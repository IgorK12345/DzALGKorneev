#include "one_phase_merge_sort.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

template<typename T>
void one_phase_merge_sort(std::vector<T>& arr) {
    size_t n = arr.size();
    if (n <= 1) return;

    
    std::ofstream f1("f1.txt");
    std::ofstream f2("f2.txt");

    if (!f1.is_open() || !f2.is_open()) {
        std::cerr << "Cannot open files for writing\n";
        return;
    }

    for (size_t i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            f1 << arr[i] << '\n';
        }
        else {
            f2 << arr[i] << '\n';
        }
    }

    f1.close();
    f2.close();

    size_t series_length = 1;

    while (series_length < n) {
        
        std::ifstream in1("f1.txt");
        std::ifstream in2("f2.txt");
        std::ofstream out1("f3.txt");  
        std::ofstream out2("f4.txt");  



        bool write_to_first = true;
        T val1, val2;
        bool has_val1 = false, has_val2 = false;

       
        if (in1 >> val1) has_val1 = true;
        if (in2 >> val2) has_val2 = true;

        while (has_val1 || has_val2) {
            size_t count1 = 0, count2 = 0;
            std::ofstream& current_out = write_to_first ? out1 : out2;

            // Слияние двух серий
            while ((has_val1 || has_val2) && (count1 < series_length || count2 < series_length)) {
                if (has_val1 && has_val2) {
                    if (count1 < series_length && count2 < series_length) {
                        if (val1 <= val2) {
                            current_out << val1 << '\n';
                            has_val1 = (in1 >> val1) ? true : false;
                            count1++;
                        }
                        else {
                            current_out << val2 << '\n';
                            has_val2 = (in2 >> val2) ? true : false;
                            count2++;
                        }
                    }
                    else if (count1 < series_length) {
                        current_out << val1 << '\n';
                        has_val1 = (in1 >> val1) ? true : false;
                        count1++;
                    }
                    else { 
                        current_out << val2 << '\n';
                        has_val2 = (in2 >> val2) ? true : false;
                        count2++;
                    }
                }
                else if (has_val1 && count1 < series_length) {
                    current_out << val1 << '\n';
                    has_val1 = (in1 >> val1) ? true : false;
                    count1++;
                }
                else if (has_val2 && count2 < series_length) {
                    current_out << val2 << '\n';
                    has_val2 = (in2 >> val2) ? true : false;
                    count2++;
                }
            }

            write_to_first = !write_to_first;
        }

        in1.close();
        in2.close();
        out1.close();
        out2.close();

        
        std::remove("f1.txt");
        std::remove("f2.txt");
        std::rename("f3.txt", "f1.txt");
        std::rename("f4.txt", "f2.txt");

        series_length *= 2;
    }

    
    std::ifstream final_in("f1.txt");
    if (!final_in.is_open()) {
       
        final_in.open("f2.txt");
    }

    if (final_in.is_open()) {
        for (size_t i = 0; i < n; ++i) {
            T val;
            if (final_in >> val) {
                arr[i] = val;
            }
        }
        final_in.close();
    }

    
}

template void one_phase_merge_sort<int>(std::vector<int>&);
template void one_phase_merge_sort<double>(std::vector<double>&);
template void one_phase_merge_sort<float>(std::vector<float>&);
template void one_phase_merge_sort<char>(std::vector<char>&);