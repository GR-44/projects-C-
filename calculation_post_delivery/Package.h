#pragma once
#include<string>
using namespace std;

class Package
{
public:
	Package(const string & first, const string & last, const string & addr, const string & city, const string & state,
		const string& zip_send, const string& zip_reciev, double weightVal, double price);
	~Package();

	double calculateCost() const;

	void setFirstName(string);
	string getFirstName() const;

	void setLastName(string);
	string getLastName() const;

	void setAddress(string);
	string getAddress() const;

	void setCity(string);
	string getCity() const;

	void setState(string);
	string getState() const;

	void setZipSender(string);
	string getZipSender() const;

	void setZipReciever(string);
	string getZipReciever() const;

	void setWeight(double);
	double getWeight() const;

	void setPrice(double);
	double getPrice() const;

private:
	string firstName;
	string lastName;
	string address_;
	string city_;
	string state_;
	string zip_sender;
	string zip_reciever;
	double weight;
	double price_for_kilo;
};

