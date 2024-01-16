// Sa se scrie o fct care returneaza si suma si produsul a doua numere

#include <iostream>

void sumprod(int a, int b, int& sum, int& prod) {
	sum = a + b;
	prod = a * b;
}

int* sumprodarr(int a, int b) {
	static int res[2];

	res[0] = a + b;
	res[1] = a * b;

	return res;
}

void sumprodarr2(int a, int b, int* v) {
    v[0] = a + b;
    v[1] = a * b;
}

int main() {
	int a, b, sum, prod;

	std::cout << "a, b = ";
	std::cin >> a >> b;

	// Prin referinta
	sumprod(a, b, sum, prod);
	std::cout << sum << " " << prod << '\n';

	// Prin array returnat
	int* ptr = sumprodarr(a, b);
	std::cout << ptr[0] << " " << ptr[1] << '\n';
}