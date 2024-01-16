// https://www.pbinfo.ro/probleme/2752/cifrezecimale

#include <iostream>

using namespace std;

int main() {
    int k;
    cin >> k;

    int numere;
    if(k % 2 == 0)
        numere = k / 2 - 1;
    else
        numere = k / 2;

    int numar = 10 + numere;

    if(k % 2 == 0)
        cout << numar % 10;
    else
        cout << numar / 10;
}