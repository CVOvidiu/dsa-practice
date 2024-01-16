#include <iostream>

using namespace std;

int maximum = 0;

void DaC(int a[1000], int left, int right) {
    if(left == right) {
        if(a[left] > maximum)
            maximum = a[left];
    }
    else {
        int m = (left + right) / 2;
        DaC(a, left, m);
        DaC(a, m + 1, right);
    }
}

int main() {
    int n, a[1000];

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    DaC(a, 0, n - 1);
    cout << maximum;
}