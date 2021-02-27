#include <iostream>
#include <iomanip>
#include "pyramid.h"
using namespace std;

void rec_pyramid(std::vector<std::vector<int>>& arr, int step, int a, int b, int size)
{
    // a = 0, b = 0 means arr[0][0]
    int check = step + (step - 1);
    int i, j;
    int num = step;

    if (check == 1)
    {
        arr[a][b] = 1;
        return;
    }

    for (i = a; i <= size - 1; i++)
    {
        if (i == a || i == size - 1)
        {
            for (j = b; j <= size - 1; j++)
            {
                arr[i][j] = num;
            }
        }
        if (i > a && i <= size - 1)
        {
            arr[i][b] = num;
            arr[i][size - 1] = num;
        }
    }
    rec_pyramid(arr, step - 1, a + 1, b + 1, size - 1);
}

void print_arr(const std::vector<std::vector<int>>& arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 0; j < arr.size(); ++j)
            cout << setw(3) <<arr[i][j] << " ";
        cout << endl;
    }
    
}









