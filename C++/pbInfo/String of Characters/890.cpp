#include <iostream>
#include <string.h>

using namespace std;

int vocals_array[4]; // a - 0, ..., u - 4 - frequency array of vocals (global for all zeros)

int main() {
    char text[256];
    cin.get(text, 256);

    char vocals[] = "AEIOU";
    for(unsigned int i = 0; i < strlen(text); i++) {
        if(islower(text[i])) //* we convert it to upper
            text[i] -= 32;
        if(strchr(vocals, text[i]) != NULL) //* if we found a vocal
            for(unsigned int j = 0; j < strlen(vocals); j++)
                if(vocals[j] == text[i]) 
                    vocals_array[j]++; //* we increment the value in the frequency array
    }

    int maximum = 0;
    char c = ' ';
    for(unsigned int i = 0; i < strlen(vocals); i++)
        if(vocals_array[i] > maximum) {
            maximum = vocals_array[i];
            c = vocals[i];
        }

    cout << c;
}