#include <vector>
#include "Sort.h"
#include "time_calculation.h"
using namespace std;

void Sort::quicksort(vector<int>& arr, int low, int high)
{
    int i = low;
    int j = high - 1;
    int temp;
    do
    {
        while (j > i)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                ++i;
                break;
            }
            --j;
        }
        while (i < j)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                --j;
                break;
            }
            ++i;
        }
    } while (i < j);

    if (i < high - 1)
        quicksort(arr, i + 1, high);
    if (low < j - 1)
        quicksort(arr, low, j);

}

void Sort::bucketsort(vector<int>& v)     // bucketsort - only for INTEGERS!!!
{
    Timer t;
    // create 2 arrays for negative and positive integers of origin array
    vector<int> pos;
    vector<int> neg;
    for (auto x : v)
    {
        if (x < 0)
            neg.push_back(x);
        else
            pos.push_back(x);
    }

    // ======================= sorting negative numbers ================================
    // create two-dimentional array
    vector<vector<int>> neg_nums(10);
    for (int i = 0; i < 10; ++i)
    {
        neg_nums[i].resize(neg.size());
        for (int j = 0; j < neg.size(); ++j)
            neg_nums[i][j] = 0;
    }

    // define min nagative integer
    int min_number = min_num(neg);

    // define a count of positions of negative integer
    int number_position = numpos(min_number);

    int num;
    int sum;
    int div_step = 0;
    int step = 1;
    int decade;
    int index;
    int j;

    // block sort of negative numbers
    for (decade = 1; decade <= number_position; ++decade)
    {
        j = 0;
        num = 0;
        for (int i = 0; i < neg.size(); ++i)
        {
            sum = pow(10, step);                                                
            index = abs(neg[i]) % sum / pow(10, div_step);
            neg_nums[index][j++] = neg[i];
        }
        ++step;
        ++div_step;

        for (int i = 0; i < 10; i++)
        {
            for (j = 0; j < neg.size(); j++)
            {
                if (neg_nums[i][j] < 0)
                {
                    neg[num++] = neg_nums[i][j];
                    neg_nums[i][j] = 0;
                }
            }
        }
    }

    //================================= sorting positive numbers ==============================================
    // create two-dimentional array
    vector<vector<int>> pos_nums(10);
    for (int i = 0; i < 10; ++i)
    {
        pos_nums[i].resize(pos.size());
        for (int j = 0; j < pos.size(); ++j)
            pos_nums[i][j] = -1;
    }

    // define max positive integer
    int max_number = max_num(pos);

    // define a count of position of positive integer
    number_position = numpos(max_number);

    div_step = 0;
    step = 1;

    // block sort of positive numbers
    for (decade = 1; decade <= number_position; ++decade)
    {
        j = 0;
        num = 0;
        for (int i = 0; i < pos.size(); i++)
        {
            sum = pow(10, step);                     
            index = pos[i] % sum / pow(10, div_step);
            pos_nums[index][j++] = pos[i];
        }
        ++step;
        ++div_step;

        for (int i = 0; i < 10; i++)
        {
            for (j = 0; j < pos.size(); j++)
            {
                if (pos_nums[i][j] != -1)
                {
                    pos[num++] = pos_nums[i][j];
                    pos_nums[i][j] = -1;
                }
            }
        }
    }

    // join sorted negative and sorted positive integers in origin array 
    num = 0;
    for (int i = neg.size() - 1; i >= 0; i--)
    {
        v[num++] = neg[i];
    }
    for (int i = 0; i < pos.size(); i++)
    {
        v[num++] = pos[i];
    }
}

int Sort::numpos(int number)                              // define a count of positions of integer
{
    int count = 0;
    if(number < 0)
    {
        number = -number;
    }

    while (true)
    {
        number /= 10;
        ++count;
        if (number == 0) break;
    }

    return count;
}

int Sort::min_num(std::vector<int>& v)                   // define min negative integer in array
{
    int min_number = 0;
    for (auto x : v)
    {
        if (x < min_number)
            min_number = x;
    }
    return min_number;
}

int Sort::max_num(std::vector<int>& v)                   // define max positive integer in array
{
    int max_number = 0;
    for (auto x : v)
    {
        if (x > max_number)
            max_number = x;
    }
    return max_number;
}

void Sort::bubblesort(std::vector<int>& v)                   // bubble sort
{
    Timer t;
    
    int i, j, temp;
    for (i = 0; i < v.size(); i++)
    {
        for (j = 0; j < (v.size() - i - 1); j++)
        {
            if (v[j] > v[j + 1])
            {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}





















