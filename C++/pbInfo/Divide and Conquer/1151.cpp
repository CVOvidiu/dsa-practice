#include <iostream>

using namespace std;

bool ok = true;

void DaC(int a[1000], int left, int right) {
    if(left == right) {
        if(a[1] != a[left])
            ok = false;
    }
    else {
        int m = (left + right) / 2;
        DaC(a, left, m);
        DaC(a, m + 1, right);
    }
}

int main() {
    int n, a[500];

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    DaC(a, 0, n - 1);
    if(ok == false)
        cout << "NU";
    else
        cout << "DA";
}