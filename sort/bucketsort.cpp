#include <iostream>
#include <vector>
#include "Sort.h"
#include "time_calculation.h"
using namespace std;

void print_arr(vector<int>& v, int x)
{
    for (int i = 0; i < v.size(); i += x)
        cout << v[i] << " ";
}

int main()
{
    const int SIZE = 100000;
    vector<int> v1(SIZE);
    vector<int> v2(SIZE);
    vector<int> v3(SIZE);
    int step = 500;

    srand(time(0));
    for (int i = 0; i < SIZE; ++i)
    {
        v1[i] = rand() % 10000;
        v2[i] = rand() % 10000;
        v3[i] = rand() % 10000;  
    }   

    cout << "v1: ";
    print_arr(v1, step);
    cout << endl << endl;
    cout << "v2: ";
    print_arr(v2, step);
    cout << endl << endl;
    
    cout << "===========================================================" << endl;

    Sort a;
    // block sorting and calculation of runtime 
    a.bucketsort(v1);

    // bubble sorting and calculation of runtime
    {
        Timer t;
        a.quicksort(v2, 0, v2.size());
    }

    // sortX and calculation of runtime
    a.sortX(v3);

    cout << "===========================================================" << endl;
    cout << endl;

    cout << "v1: ";
    print_arr(v1, step);
    cout << endl << endl;
    cout << "v2: ";
    print_arr(v2, step);
    cout << endl << endl;
    cout << "v3: ";
    print_arr(v3, step);
    cout << endl;

    return 0;
}


