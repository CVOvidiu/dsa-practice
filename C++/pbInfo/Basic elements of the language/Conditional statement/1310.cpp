// https://www.pbinfo.ro/probleme/1310/cifdiv

#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int c1 = n % 10;
    int c2 = n % 100 / 10;
    int c3 = n / 100;

    int c = 0;
    if(c1 != 0)
        if(m % c1 == 0)
            c++;
    if(c2 != 0)        
        if(m % c2 == 0)
            c++;
    if(c3 != 0)
        if(m % c3 == 0)
            c++;

    cout << c;
}