/*
Se dă un șir de n elemente. Sirul este sortat descrescator si are elemente distincte. Se dorește
identificarea următoarei situații: există un index i pentru care A[i] = i. Să se elaboreze un
algoritm D&I cu complexitate O (log n).
*/

#include <iostream>
#include <vector>
#include <fstream>

void readArr(std::vector<int>& arr) {
	std::ifstream in("file.in");

	int n; in >> n;

	int temp;
	for (int i = 0; i < n; i++) {
		in >> temp;
		arr.push_back(temp);
	}

	in.close();
}

void writeArr(const std::vector<int>& arr) {
	for (int el : arr)
		std::cout << el << " ";
}

bool indexProperty(std::vector<int>& arr, int st, int dr) {
	int mij = (st + dr) / 2;
	if (arr[mij] == mij) {
		std::cout << "R: " << arr[mij];
		return true;
	}
	if (st == dr) // Daca am ajuns aici inseamna ca proprietatea nu este valabila pt niciun element 
		return false;
	if (arr[mij] > mij) // Inseamna ca toate elementele din inaintea elementului curent nu respecta regula (fiind descrescatoare si distincte)
		return indexProperty(arr, mij + 1, dr);
	else // Inseamna ca e o posibilitate ca un element din stanga elementului curent sa respecte
		return indexProperty(arr, st, mij);
}

int main() {
	std::vector<int> arr;
	readArr(arr);

	if (indexProperty(arr, 0, arr.size() - 1))
		std::cout << "\nExista un element ce respecta proprietatea";
	else
		std::cout << "\nNu exista elemente ce respecta proprietatea";

	return 0;
}

/*
20

100
99
94
89
85
73
71
70
68
59
57
56
47
46
45
33
30
26
23
19

R: True pt 19
R: False daca 19 era 20
*/