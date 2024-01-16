#include <iostream>

using namespace std;

int DaC(int a[1000], int left, int right) {
    if(left == right)
        return 1; // ? Why
    else {
        int m = (left + right) / 2;
        int S1 = DaC(a, left, m);
        int S2 = DaC(a, m + 1, right);
        if(S1 == S2 && a[m] <= a[m + 1]) // ? What does this mean
            return 1;
        return 0;
    }
}

int main() {
    int n, a[1000];

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    if(DaC(a, 0, n - 1))
        cout << "DA";
    else
        cout << "NU";
}