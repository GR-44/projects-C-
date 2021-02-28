using namespace std;

#include "Package.h"

Package::Package(const string& first, const string& last, const string& addr, const string& city, const string& state,
	const string& zip_send, const string& zip_reciev, double weightVal, double price)
	: firstName(first), lastName(last), address_(addr), city_(city), state_(state), zip_sender(zip_send), zip_reciever(zip_reciev)
{
	setWeight(weightVal);
	setPrice(price);
}

Package::~Package() {};

double Package::calculateCost() const 
{
	return getWeight() * getPrice();
}

void Package::setFirstName(string first)
{
	firstName = first;
}

string Package::getFirstName() const
{
	return firstName;
}

void Package::setLastName(string last)
{
	lastName = last;
}

string Package::getLastName() const
{
	return lastName;
}

void Package::setAddress(string addr)
{
	address_ = addr;
}

string Package::getAddress() const
{
	return address_;
}

void Package::setCity(string city)
{
	city_ = city;
}

string Package::getCity() const
{
	return city_;
}

void Package::setState(string state)
{
	state_ = state;
}

string Package::getState() const
{
	return state_;
}

void Package::setZipSender(string zip_send)
{
	zip_sender = zip_send;
}

string Package::getZipSender() const
{
	return zip_sender;
}

void Package::setZipReciever(string zip_reciev)
{
	zip_reciever = zip_reciev;
}

string Package::getZipReciever() const
{
	return zip_reciever;
}

void Package::setWeight(double weightVal)
{
	weight = (weightVal < 0) ? 0 : weightVal;
}

double Package::getWeight() const
{
	return weight;
}

void Package::setPrice(double price)
{
	price_for_kilo = (price < 0) ? 0 : price;
}

double Package::getPrice() const
{
	return price_for_kilo;
}


















