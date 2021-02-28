using namespace std;
#include "TwoDayPackage.h"
#include "Package.h"

TwoDayPackage::TwoDayPackage(const string& first, const string& last, const string& addr, const string& city, const string& state,
	const string& zip_send, const string& zip_reciev, double weightVal, double price, double markupVal)
	: Package(first, last, addr, city, state, zip_send, zip_reciev, weightVal, price)
{
	setMarkup(markupVal);
}

TwoDayPackage::~TwoDayPackage() {};

void TwoDayPackage::setMarkup(double markupVal)
{
	markup = (markupVal < 0) ? 0 : markupVal;
}

double TwoDayPackage::getMarkup() const
{
	return markup;
}

double TwoDayPackage::calculateCost() const
{
	return markup + Package::calculateCost();
}