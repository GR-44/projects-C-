#pragma once
#include <vector>

class Sort
{
public:
	void block_sort(std::vector<int>& v);
	void bubble_sort(std::vector<int>& v);

private:
	int numpos(int number);
	int min_num(std::vector<int> & v);
	int max_num(std::vector<int> & v);
};

