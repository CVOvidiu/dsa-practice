// https://www.pbinfo.ro/probleme/1740/suma-b-numere

#include <iostream>

int main() {
    short a, b;
    std::cin >> a >> b;

    if ((a - (b * (b - 1) / 2)) % b == 0)
        std::cout << "DA";
    else 
        std::cout << "NU";
}