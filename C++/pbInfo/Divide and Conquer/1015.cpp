#include <iostream>
using namespace std;

int suma(int a[], int left, int right) {
    if(left == right)
        return a[left]; // se imparte de atatea ori pana ajunge sa fie un singur element in sequence
    else {
        // trebuie impartite pe subsequences
        int m = (left + right) / 2; 
        int S1 = suma(a, left, m);
        int S2 =  suma(a, m + 1, right);
        return S1 + S2; // returnam elementele singure din subsequences
    }
}

int main() {
    int a[1000], n;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << suma(a, 0, n - 1);
}