#include <iostream>
#include <vector>
using namespace std;

#include "pyramid.h"

int main()
{
    cout << "Pyramids\n"
        "Examples:        2 2 2            3 3 3 3 3\n"
        "                 2 1 2            3 2 2 2 3\n"
        "                 2 2 2            3 2 1 2 3\n"
        "                                  3 2 2 2 3\n"
        "                                  3 3 3 3 3" << endl;

    int step;
    cout << "Enter a number of pyramid step from 2 to 15: ";
    cin >> step;
    if (step == 1)
    {
        cout << "\nSuch pyramid does not exist!!!" << endl;
        return 1;
    }

    int size = step + (step - 1);                      // a pyramid side side
        
       
    vector <vector<int>> arr(size, vector<int>(size, 0));

    rec_pyramid(arr, step, 0, 0, size);

    cout << endl;
    print_arr(arr);
    
    return 0;
}


