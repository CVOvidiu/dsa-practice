#include <iostream>
#include <math.h>

using namespace std;

int prime(int a[], int left, int right) {
    if(left == right) { // daca e un singur element
        for(int d = 2; d * d <= a[left]; d++)
            if(a[left] % d == 0) // nu e prim
                return 1;
        return 0;
    } else {
        int m = (left + right) / 2;
        int S1 = prime(a, left, m);
        int S2 = prime(a, m + 1, right);
        return S1 + S2;
    }
}

int main() {
    int a[200], n;
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int result = prime(a, 0, n - 1);
    if(result != n)
        cout << "DA";
    else
        cout << "NU";
}