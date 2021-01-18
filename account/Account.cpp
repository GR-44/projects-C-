#include "pch.h"
#include <iostream>
#include "Account.h"
using namespace std;

Account::Account(double sum)
{
	balance = (sum >= 0) ? sum : 0;
	if (sum < 0)
	{
		cout << "Balance: $" << getBalance() << endl;
		cout << "First balance is wrong!" << endl;
	}
}

void Account::credit(double sum)
{
	balance += sum;
}

void Account::debit(double sum)
{
	if (sum <= balance)
	{
		balance -= sum;
	}
	else
	{
		cout << "\nNOT MONEY ENOUGH!" << endl;
	}
}

double Account::getBalance()const
{
	return balance;
}











