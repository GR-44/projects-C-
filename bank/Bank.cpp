#include <iostream>
#include <vector>
using namespace std;

#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

int main()
{
    Account client(1000);
    SavingsAccount client2(200, 0.07);
    CheckingAccount client3(1000, 1.5);

    vector<Account*> clients{&client, &client2, &client3};
    
    cout << "Client 1:" << endl;
    cout << "Balance: $" << clients[0]->getBalance() << endl;;
    clients[0]->credit(500);
    cout << "Balance after credit: $" << clients[0]->getBalance() << endl;;
    clients[0]->debit(100);
    cout << "Balance after debit: $" << clients[0]->getBalance() << endl;
    cout << endl;

    cout << "Client 2:" << endl;
    cout << "Balance: $" << clients[2]->getBalance() << endl;;
    clients[2]->credit(500);
    cout << "Balance after credit: $" << clients[2]->getBalance() << endl;
    clients[2]->debit(100);
    cout << "Balance after debit: $" << clients[2]->getBalance() << endl;

    return 0;
}
