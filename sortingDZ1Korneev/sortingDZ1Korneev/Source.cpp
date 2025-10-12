#include "Bubble.h"
#include "OptimizedBubble.h"
#include "Exchange.h"
#include "Selection.h"
#include "Insertion.h"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> a = {1, 2, 3, 4, 5, 6};
	std::vector<int> b = {6, 5, 4, 3, 2, 1};
	std::vector<int> c = {2, 5, 3, 1, 6, 4};
	std::vector<int> d = { 12, 4, 18, 7, 1, 15, 9, 20, 6, 13, 3, 16, 10, 19, 2, 8, 14, 5, 17, 11 };
	std::vector<int> e = {};
	std::vector<int> f = {1};

	insertion_sort(a);
	insertion_sort(b);
	insertion_sort(c);
	insertion_sort(d);
	insertion_sort(e);
	insertion_sort(f);


	for (int i = 0; i < a.size(); ++i) {
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
	for (int i = 0; i < b.size(); ++i) {
		std::cout << b[i] << " ";
	}
	std::cout << "\n";
	for (int i = 0; i < c.size(); ++i) {
		std::cout << c[i] << " ";
	}
	std::cout << "\n";
	for (int i = 0; i < d.size(); ++i) {
		std::cout << d[i] << " ";
	}
	std::cout << "\n";
	for (int i = 0; i < e.size(); ++i) {
		std::cout << e[i] << " ";
	}
	std::cout << "\n";
	for (int i = 0; i < f.size(); ++i) {
		std::cout << f[i] << " ";
	}
	std::cout << "\n";
	return 0;
}