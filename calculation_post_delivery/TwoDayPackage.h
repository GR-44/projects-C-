#pragma once
#include <string>
using namespace std;

#include "Package.h"

class TwoDayPackage : public Package
{
public:
	TwoDayPackage(const string& first, const string& last, const string& addr, const string& city, const string& state,
		const string& zip_send, const string& zip_reciev, double weightVal, double price, double markupVal);
	~TwoDayPackage();

	double calculateCost() const;

	void setMarkup(double);
	double getMarkup() const;

private:
	double markup;
};

