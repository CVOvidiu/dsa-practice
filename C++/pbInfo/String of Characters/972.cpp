#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char vocals[6] = "aeiou";
    char text[256];
    cin.get(text, 256);

    int count = 0;
    for(unsigned int i = 0; i <= strlen(text); i++) //! This is best way to scroll through the characters
        if(strchr(vocals, text[i]) != NULL) //* Search in vocals character text[i] and finds it
            if(strchr(vocals, text[i - 1]) == NULL && strchr(vocals, text[i + 1]) == NULL) //* If the characters in front and behind are not vocals
                if(text[i - 1] != ' ' && text[i + 1] != ' ') //* Fix for spaces but not other punctuation (for punctuation we can use ASCII letters range)
                count++;

    cout << count;
}
