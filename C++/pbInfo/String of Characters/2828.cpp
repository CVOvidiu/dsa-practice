#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char text[101];
    cin.get(text, 101);

    for(unsigned int i = 0; i < strlen(text); i++)
        if(isupper(text[i]) && !isupper(text[i - 1]))
            cout << text[i];
}