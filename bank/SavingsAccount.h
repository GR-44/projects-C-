#pragma once
#include "Account.h"

class SavingsAccount : public Account
{
public:
	SavingsAccount(double, double);
	~SavingsAccount();

	void setRate(double);
	double getRate() const;

	virtual void credit(double);
	virtual void debit(double);

	double calculateInterest() const;

private:
	double interest_rate;	
};

