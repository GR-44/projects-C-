#pragma once
#include <vector>

class Sort
{
public:
	void quicksort(std::vector<int>& arr, int low, int high);
	void bucketsort(std::vector<int>& v);
	void sortX(std::vector<int>& v);
	void bubblesort(std::vector<int>& v);

private:
	int numpos(int);
	int min_num(std::vector<int> & v);
	int max_num(std::vector<int> & v);
};

