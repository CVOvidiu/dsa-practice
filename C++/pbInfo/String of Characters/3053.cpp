#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

ifstream in("evenoddxxl.in");
ofstream out("evenoddxxl.out");

int main() {
    char n[1001];
    in.get(n, 1001);
    int uc = n[strlen(n) - 1] - '0'; //? strlen(n) - 1 > for last digit of the number; - '0' > to get the exact char to int conversion
    cout << uc;

    if(uc % 2 == 0)
        out << "Par";
    else
        out << "Impar";
}