/*
	We have a bank account class. Utility:
	- constructor
	- input bank account info
	- print info
	- deposit/withdraw sum
	- getters/setters for balance and first name
*/

#include <iostream>
#include <string>
#include <vector>

class BankAccount {
	std::string m_firstName = "", m_lastName = "", m_IBAN = "", m_currency = "";
	float m_balance = 0;

public:
	BankAccount(std::string firstName, std::string lastName, std::string IBAN, std::string currency, float balance)
	:m_firstName(firstName), m_lastName(lastName), m_IBAN(IBAN), m_currency(currency), m_balance(balance) {
		// or this:
		/*
		m_firstName = firstName;
		m_lastName = lastName;
		m_IBAN = IBAN;
		m_currency = currency;
		m_balance = balance;
		*/
	}

	void read() {
		std::cin >> m_firstName >> m_lastName >> m_IBAN >> m_currency >> m_balance;
	}

	void print() {
		std::cout << "Detinator:	" << m_firstName << " " << m_lastName << "\n";
		std::cout << "IBAN:		" << m_IBAN << "\n";
		std::cout << "Moneda:		" << m_currency << "\n";
		std::cout << "Sold:		" << m_balance << "\n";
		std::cout << "\n";
	}

	void deposit(float sum) {
		m_balance += sum;
		std::cout << "Success deposit.\n";
		std::cout << "\n";
	}

	void withdraw(float sum) {
		if (sum > m_balance)
			std::cout << "Can't withdraw that sum!\n";
		else {
			m_balance -= sum;
			std::cout << "Success withdraw.\n";
		}

		std::cout << "\n";
	}

	// Getters
	float getBalance() {
		return m_balance;
	}

	std::string getFirstName() {
		return m_firstName;
	}

	// Setters
	void setBalance(float newBalance) {
		m_balance = newBalance;
	}

	void setFirstName(std::string newFirstName) {
		m_firstName = newFirstName;
	}
};

int main() {
	BankAccount b1("Jamal", "C", "51235", "EUR", 2563.5);
	BankAccount b2("Luigi", "M", "52352", "EUR", 1523.7);
	b1.print();
	b1.deposit(523);
	b2.withdraw(1523);
	std::cout << "getter: " << b2.getBalance() << "\n";
	b1.setBalance(521351);
	b1.print();
	b2.print();

	return 0;
}