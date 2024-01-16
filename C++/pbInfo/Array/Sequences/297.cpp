#include <iostream>
#include <fstream>
using namespace std;

ifstream in("secvsummax.in");
ofstream out("secvsummax.out");

int main() {
    int a[100000], n;
    in >> n;
    for(int i = 0; i < n; i++)
        in >> a[i];

    int left, right, Smax = -2000000000, S = a[0], start;
    for(int i = 0; i < n; i++) {
        if(S < 0)
            S = 0, start = i;
        S += a[i];
        if(S > Smax)
            Smax = S, left = start, right = i;
    }
    out << left+1 << " " << right+1;
}
/*int main() {
    int a[100000], n;
    in >> n;
    for(int i = 0; i < n; ++i)
        in >> a[i];

    int left=0, right=0, Smax = a[0], S = a[0], start=0;
    for(int i = 1; i < n; ++i) {
        if(S < 0)
            S = a[i], start = i;
        else S += a[i];
        if(S > Smax) {
            Smax = S;
            left = start;
            right = i;
        }
    }
    out << left+1 << " " << right+1;
}*/