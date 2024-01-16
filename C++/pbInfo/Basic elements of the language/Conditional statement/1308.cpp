// https://www.pbinfo.ro/probleme/1308/cifrecomune

#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int c_n[2], c_m[2];
    c_n[0] = n % 10;
    c_n[1] = n / 10;
    c_m[0] = m % 10;
    c_m[1] = m / 10;

    int c = 0;
    if(c_n[0] == c_m[0] || c_n[0] == c_m[1])
        c = 1;
    if(c_n[1] == c_m[0] || c_n[1] == c_m[1])
        c = 1;

    if(c == 1)
        cout << "da";
    else 
        cout << "nu";
}   