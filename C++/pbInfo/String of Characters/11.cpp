#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char text[21], vocale[] = "aeiou";
    cin.get(text, 21);

    for(unsigned int i = 0; i <= strlen(text); i++)
        if(strchr(vocale, text[i]) == NULL)
            cout << text[i];
        else
            cout << char(int(text[i]) - 32); //* Character that represents the value in ASCII table at lowercase character number in ASCII - 32 to convert to upper
}