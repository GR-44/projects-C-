#pragma once
#include "Account.h"

class CheckingAccount : public Account
{
public:
	CheckingAccount(double, double);
	~CheckingAccount();

	void setFee(double);
	virtual void credit(double);
	virtual void debit(double);

private:
	double transaction_fee;
};

