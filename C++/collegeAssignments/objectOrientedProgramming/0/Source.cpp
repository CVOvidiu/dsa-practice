/*
	Write a function structure that contains:
		Variables:
		- Numerator
		- Denominator (!= 0)
		Methods:
		- Print function
		- Least common divisor between the numerator and denominator
		- Simplify function
		- Check function argument equality
		- Return the sum with function/int argument (and version with + overloading)
*/

#include <iostream>

struct Fraction {
	int numarator;
	int numitor;

	void print() {
		std::cout << numarator << "/" << numitor << "\n";
	}

	int cmmdc() {
		int auxNumr = abs(numarator), auxNumi = abs(numitor); // numitor != 0

		while (auxNumi != auxNumr)
			if (auxNumi > auxNumr)
				auxNumi -= auxNumr;
			else
				auxNumr -= auxNumi;

		return auxNumr;
	}

	void simplify() {
		int div = cmmdc();

		numarator /= div;
		numitor /= div;
	}

	bool isEqTo(Fraction f) {
		return numarator * f.numitor == numitor * f.numarator;
	}

	Fraction sum(Fraction f) {
		if (numitor == f.numitor)
			return { numarator + f.numarator, numitor };
		else {
			Fraction sum;
			sum.numarator = numarator * f.numitor + numitor * f.numarator;
			sum.numitor = numitor * f.numitor;
			sum.simplify();

			return sum;
		}
	}

	// + overloading with another function
	Fraction operator + (Fraction f) {
		if(numitor == f.numitor)
			return { numarator + f.numarator, numitor };
		else {
			Fraction sum;
			sum.numarator = numarator * f.numitor + numitor * f.numarator;
			sum.numitor = numitor * f.numitor;

			sum.simplify();

			return sum;
		}
	}

	// + overloading with int
	Fraction operator + (int x) {
		return { numarator + numitor * x, numitor };
	}
};

int main() {
	Fraction a = {6, 8};

	a.print();
	std::cout << "CMMDC: " << a.cmmdc() << "\n";
	a.simplify();
	a.print();
	Fraction b = { 6, 8 };
	std::cout << "Equality: " << a.isEqTo(b) << "\n";
	Fraction sum = a.sum(b);
	sum.print();
	sum = a + b;
	sum.print();
	sum = a + 6;
	sum.print();

	return 0;
}