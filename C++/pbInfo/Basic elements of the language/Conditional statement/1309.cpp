// https://www.pbinfo.ro/probleme/1309/gresie

#include <iostream>

using namespace std;

int main() {
    int a, b, d;
    cin >> a >> b >> d;

    if(a % d == 0 && b % d == 0)
        cout << (a / d) * (b / d);
    else if(a % d == 0 && b % d != 0)
        cout << ((a / d) * (b / d)) + (a / d);
    else if(a % d != 0 && b % d == 0)
        cout << ((a / d) * (b / d)) + (b / d);
    else if(a % d != 0 && b % d != 0)
        cout << ((a / d) * (b / d)) + (a / d) + (b / d) + 1;
}