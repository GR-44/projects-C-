#include <iostream>
#include <chrono>
#include "time_calculation.h"
using namespace std;

Timer::Timer()
{
	start = chrono::high_resolution_clock::now();
}

Timer::~Timer()
{
	end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	cout << "duration: " << duration.count() << " second" << endl;
}





