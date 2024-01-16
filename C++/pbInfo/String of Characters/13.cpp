#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char text[11];
    cin.get(text, 11);

    int size = strlen(text);
    while(size != 0) {
        for(int i = 0; i < size; i++)
            cout << text[i];
        cout << "\n";
        size--;
    }

    for(unsigned int i = 0; i < strlen(text); i++)
        cout << text + i << "\n";
}