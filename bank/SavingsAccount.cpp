#include "SavingsAccount.h"
#include "Account.h"

SavingsAccount::SavingsAccount(double first_balance, double rate)
	:Account(first_balance)
{
	rate = (rate <= 0.0 || rate > 0.1) ? 1 : rate;
	setRate(rate);
}
SavingsAccount::~SavingsAccount() {}

void SavingsAccount::setRate(double rate)
{
	interest_rate = rate;
}

double SavingsAccount::getRate() const
{
	return interest_rate;
}

double SavingsAccount::calculateInterest() const
{
	return getBalance() * interest_rate;
}

void SavingsAccount::credit(double cash)
{
	Account::credit(cash);
}

void SavingsAccount::debit(double cash)
{
	Account::debit(cash);
}







