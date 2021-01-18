#include "pch.h"
#include <iostream>
#include "Account.h"
using namespace std;

int main()
{
	Account client_1(-12);
	Account client_2(100);

	client_1.getBalance();
	puts("");

	cout << "Client_2 balance: $" << client_2.getBalance() << endl;
	client_2.credit(25);
	cout << "Client_2 balance: $" << client_2.getBalance() << endl;
	client_2.debit(160);
	client_2.debit(97.67);
	cout << "Client_2 balance: $" << client_2.getBalance() << endl;
}

