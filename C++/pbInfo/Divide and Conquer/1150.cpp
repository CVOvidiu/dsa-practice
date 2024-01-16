#include <iostream>

using namespace std;

int countEven(int a[1000], int left, int right) {
    if(left == right) {
        if(a[left] % 2 == 0)
            return 1; // Adunam parele
        return 0;
    }
    else {
        int m = (left + right) / 2;
        int S1 = countEven(a, left, m);
        int S2 = countEven(a, m + 1, right);
        return S1 + S2;
    }
}

int main() {
    int n, a[1000];

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    if(countEven(a, 0, n - 1) == n)
        cout << "DA";
    else
        cout << "NU";
}