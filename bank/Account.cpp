#include <iostream>
using namespace std;

#include "Account.h"

Account::Account(double first_balance)
{
	if (first_balance < 0)
	{
		setBalance(0.0);
		cout << "Error: The first balance is negative" << endl;
	}
	else
		setBalance(first_balance);
}

Account::~Account() {}

void Account::setBalance(double first_balance)
{
	balance = first_balance;
}

double Account::getBalance() const
{
	return balance;
}

void Account::credit(double cash)
{
	balance += (cash < 0) ? 0 : cash;
}

void Account::debit(double cash)
{
	if (cash > getBalance())
		cout << "Debit amount exceeds account balance" << endl;
	else
		balance -= (cash < 0) ? 0 : cash;
}

