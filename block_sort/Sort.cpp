#include "Sort.h"
#include <vector>
using namespace std;

void Sort::block_sort(vector<int>& v)
{
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

    // define min negative number
    /*int min_number = 0;
    for (auto x : neg)
    {
        if (x < min_number)
            min_number = x;
    }*/
    int min_number = min_num(neg);
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

    // define min negative number
    /*int max_number = 0;
    for (auto x : pos)
    {
        if (x > max_number)
            max_number = x;
    }*/
    int max_number = max_num(pos);
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
            sum = pow(10, step);                     // sum = pow(10, step) - программа выдает ошибку, sum = 99!!!!!!!!!
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

int Sort::numpos(int number)                              // определяет количество разрядов в числе.
{
    int count = 0;
    if (number < 0)
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

int Sort::min_num(std::vector<int>& v)
{
    int min_number = 0;
    for (auto x : v)
    {
        if (x < min_number)
            min_number = x;
    }
    return min_number;
}

int Sort::max_num(std::vector<int>& v)
{
    int max_number = 0;
    for (auto x : v)
    {
        if (x > max_number)
            max_number = x;
    }
    return max_number;
}

void bubble_sort(vector<int>& v)
{
    int temp;
    bool swapped;

    do
    {
        swapped = false;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i + 1] < v[i])
            {
                temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                swapped = true;
            }
        }
    } while (swapped);
}





















