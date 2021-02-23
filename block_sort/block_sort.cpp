#include <iostream>
#include <vector>
#include "Sort.h"
using namespace std;

int main()
{
    vector<int> v;
    srand(time(0));
    for (int i = 0; i < 5000; ++i)
        v.push_back(rand() % 100000 - 3000);

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


