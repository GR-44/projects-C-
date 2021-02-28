#include <iostream>
#include <vector>
using namespace std;

#include "Sort.h"

int main()
{
    vector<int> a;
    vector<double> b;
    vector<float> c;
    vector<char> ch = {'c', 'a', 's', 't', 'i', 'n', 'g'};

    for (int i = 0; i < 20; ++i)
    {
        a.push_back(rand() % 99 + 1);
        b.push_back(rand() % 99 + 1.4);
        c.push_back(rand() % 99 + 1.5);
    }

    print_arr(ch);
    bubble_sort(ch);
    print_arr(ch, 0, 4);

    cout << "==========================================================================" << endl;
    print_arr(a);
    bubble_sort(a);
    print_arr(a);


    return 0;
}

