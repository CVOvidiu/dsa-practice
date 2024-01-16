#include <iostream>

using namespace std;

int main() {
    int a[1000], n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    bool sorted;
    do {
        sorted = true;
        for(int i = 0; i < n - 1; i++)
            if(a[i] > a[i + 1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                sorted = false;
            }
    } while(!sorted);

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
}