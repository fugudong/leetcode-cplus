#include "pch.h"
#include "account.h"

void Account::PrintBalance() const
{
	cerr << "Error. Balance not available for base type." << endl;
}

void CheckingAccount::PrintBalance() const
{
	cout << "Checking account balance: " << GetBalance() << endl;
}

void SavingsAccount::PrintBalance() const
{
	cout << "Savings account balance: " << GetBalance() << endl;
}

int main()
{
	CheckingAccount * checking = new CheckingAccount(100.00);
	SavingsAccount  * savings = new SavingsAccount(1000.00);

	Account * account = checking;
	account->PrintBalance();

	account = savings;
	account->PrintBalance();

	delete checking;
	delete savings;
	return 0;
}
