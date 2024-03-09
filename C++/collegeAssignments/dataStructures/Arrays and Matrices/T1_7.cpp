// #7

#include <iostream>
#include <fstream>
#include <vector>

struct Produs {
	std::string nume;
	int cantitate;
};

bool readArr(std::vector<Produs>& arr, std::ifstream& in) {
	int nrProduse; in >> nrProduse;

	for (int i = 0; i < nrProduse; i++) {
		Produs prod;
		if (!(in >> prod.nume >> prod.cantitate)) {
			std::cerr << "Eroare la citire produs\n";
			return 1;
		}
		arr.push_back(prod);
	}

	return 0;
}

std::vector<Produs> mergeLists(const std::vector<Produs>& arr1, const std::vector<Produs>& arr2) {
	std::vector<Produs> res;
	Produs prodRes;
	for (const Produs& prod : arr1) {
		prodRes.nume = prod.nume;
		prodRes.cantitate = prod.cantitate;
		for (const Produs& prod2 : arr2) {
			if (prod.nume == prod2.nume)
				prodRes.cantitate = std::max(prod.cantitate, prod2.cantitate);
		}
		res.push_back(prodRes);
	}

	for (const Produs& prod : arr2) {
		int sw = 0;
		for (const Produs& prod2 : res) {
			if (prod.nume == prod2.nume)
				sw = 1;
		}

		if (sw == 0)
			res.push_back(prod);
	}

	return res;
}

int main() {
	std::ifstream in("file.in");
	if (!in.is_open()) {
		std::cerr << "Eroare la deschidere fisier\n";
		return 1;
	}

	std::vector<Produs> lista1, lista2;
	readArr(lista1, in);
	readArr(lista2, in);
	in.close();

	std::vector<Produs> res = mergeLists(lista1, lista2);

	std::cout << "Lista finala de produse:\n";
	for (Produs prod : res)
		std::cout << prod.nume << " " << prod.cantitate << "\n";

	return 0;
}