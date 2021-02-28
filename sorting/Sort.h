#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print_arr(const std::vector<T>& v)      // template array printing
{
	for (int i = 0; i < v.size(); ++i)
		cout << v.at(i) << " ";
	cout << endl;
}

template <typename T>
int print_arr(const vector<T>& v, int low_subscript, int high_subscript)   // template array printing from low index to high index
{
	if(low_subscript < 0 || low_subscript > high_subscript) return 0;
	if(high_subscript < low_subscript || high_subscript > v.size()) return 0;

	for (; low_subscript <= high_subscript; ++low_subscript)
		cout << v.at(low_subscript) << " ";
	cout << endl;
}

template <typename T>
void bubble_sort(vector<T>& v)      // template bubble sort  
{
    int pass;
    int j;
    int hold;

    for (pass = 1; pass < v.size(); ++pass)
    {
        for (j = 0; j < v.size() - 1; ++j)
        {
            if (v[j] > v[j + 1])
            {
                hold = v[j];
                v[j] = v[j + 1];
                v[j + 1] = hold;
            }
        }
    }
}



#endif // !SORT_H











