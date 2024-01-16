#include <iostream>

using namespace std;

int sum(int a[], int left, int right) {
    if(left == right)
        if(a[left] % 2 == 0)
            return a[left];
        else
            return 0;
    else {
        int m = (left + right) / 2;
        int S1 = sum(a, left, m);
        int S2 = sum(a, m + 1, right);
        return S1 + S2;
    }
}

int main() {
    int n, a[1000];

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << sum(a, 0, n - 1);
}