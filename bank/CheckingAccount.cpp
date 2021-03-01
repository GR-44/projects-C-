#include "CheckingAccount.h"
#include "Account.h"

CheckingAccount::CheckingAccount(double first_balance, double fee)
	: Account(first_balance)
{
	fee = (fee <= 0) ? 1 : fee;
	setFee(fee);
}

CheckingAccount::~CheckingAccount() {}

void CheckingAccount::setFee(double fee)
{
	transaction_fee = fee;
}

void CheckingAccount::credit(double cash)
{
	Account::credit(cash - transaction_fee);
}
void CheckingAccount::debit(double cash)
{
	Account::debit(cash + transaction_fee);
}
