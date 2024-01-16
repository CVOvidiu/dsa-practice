#include <iostream>
using namespace std;

int imp(int a[], int left, int right) {
    if(left == right)
        if(a[left] % 2 != 0)
            return 1;
        else
            return 0;
    else {
        int m = (left + right) / 2;
        int S1 = imp(a, left, m);
        int S2 = imp(a, m + 1, right);
        return S1 + S2;
    }
}

int main() {
    int n, a[100];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    if(imp(a, 0, n - 1) != 0)
        cout << "DA";
    else
        cout << "NU";
}