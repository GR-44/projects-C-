using namespace std;
#include "OvernightPackage.h"
#include "Package.h"

OvernightPackage::OvernightPackage(const string& first, const string& last, const string& addr, const string& city, const string& state,
	const string& zip_send, const string& zip_reciev, double weightVal, double price, double markup)
	: Package(first, last, addr, city, state, zip_send, zip_reciev, weightVal, price)
{
	setMarkup(markup);
}

OvernightPackage::~OvernightPackage() {};

void OvernightPackage::setMarkup(double markup)
{
	this->markup = (markup < 0) ? 0 : markup;
}

double OvernightPackage::getMarkup() const
{
	return this->markup;
}

double OvernightPackage::calculateCost() const
{
	return (markup + getPrice()) * getWeight();
}
