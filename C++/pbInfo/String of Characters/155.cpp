#include <iostream>
#include <string.h>

using namespace std;

int b[10]; //? Frequency array of digits

int main() {
    char a[61];
    bool sw = false; //? false - text doesn't contain any digits
    cin.get(a, 61);

    for(int i = 0; i < strlen(a); i++)
        for(int j = 0; j <= 9; j++) {
            if(isdigit(a[i]) && (int(a[i]) - 48) == j) { //? (int(a[i]) - 48) > because ASCII of char 0 is 48
                b[j]++;
                sw = true;
            }
        }

    int max = 0;
    int maxc = 0;
    for(int i = 0; i <= 9; i++)
        if(b[i] > max) {
            max = b[i];
            maxc = i;
    }

    if(sw == true)
        cout << maxc;
    else
        cout << "NU";
}