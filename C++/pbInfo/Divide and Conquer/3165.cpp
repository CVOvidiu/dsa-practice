#include <iostream>

using namespace std;

int a[100][100], n, m, i; // i trebuie sa fie global ca sa poti sa te referi in functie

int sum(int a[100][100], int left, int right) {
    if(left == right) {
        if(a[i][left] % 2 == 0) {
            return a[i][left];
        }
        else return 0; 
    }
    else {
        int m = (left + right) / 2;
        int S1 = sum(a, left, m);
        int S2 = sum(a, m + 1, right);
        return S1 + S2;
    }
}

int main() {
    int n, m, s = 0;
    cin >> n >> m;
    for(i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    for(i = 0; i < n; i++) {
        s += sum(a, 0, m - 1); // ne plimbam pe fiecare linie (col 0 -> col m - 1, m e numarul coloanelor)
    }
    cout << s;
}

