#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char text[11], vocals[] = "AEIOUaeiou";
    cin.get(text, 11);

    bool sw1 = false, sw2 = false; //* check if both of vocal and non vocal exist in the word
    int index1, index2; //* we save the indexes so we can switch the characters later
    for(unsigned int i = 0; i < strlen(text); i++)
        if(strchr(vocals, text[i]) != NULL) { //* if is vocal
            sw1 = true;
            index1 = i;
            break;
        }

    for(unsigned int i = strlen(text) - 1; i > 0; i--)
        if(strchr(vocals, text[i]) == NULL) { //* if is not vocal
            sw2 = true;
            index2 = i;
            break;
        }

    if(sw1 == true && sw2 == true) {
        char aux = text[index1];
        text[index1] = text[index2];
        text[index2] = aux;
        cout << text;
    } else 
        cout << "IMPOSIBIL";
}