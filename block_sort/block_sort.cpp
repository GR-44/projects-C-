#include <iostream>
#include <vector>
#include "Sort.h"
using namespace std;

int main()
{
    vector<int> v;
    for (int i = 0; i < 2000; ++i)
        v.push_back(rand() % 100 - 50);

    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << "\narray size: " << v.size() << endl;
    cout << "===========================================================" << endl;

    Sort a;
    a.block_sort(v);

    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << "\narray size: " << v.size() << endl;


    return 0;
}


