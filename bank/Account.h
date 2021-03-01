#pragma once

class Account
{
public:
	Account(double);
	~Account();

	void setBalance(double);
	double getBalance() const;

	virtual void credit(double);
	virtual void debit(double);

private:
	double balance;
};

