#include <iostream>

using namespace std;

int DaC(int a[1000], int left, int right) {
    if(left == right) { // * Verify each element if prime
        for(int d = 2; d * d <= a[left]; d++)
            if(a[left] % d == 0)
                return 0; // * Is not prime we set with the smallest value so it doesn't affect the comparison
        return a[left]; // * Is prime we return the number for comparison

    }
    else {
        int m = (left + right) / 2;
        int S1 = DaC(a, left, m);
        int S2 = DaC(a, m + 1, right);
        if(S1 > S2)
            return S1;
        else
            return S2;
    }
}

int main() {
    int n, a[1000];

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << DaC(a, 0, n - 1);
}