#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char text[101], vocals[] = "aeou";
    cin.get(text, 101);

    bool notVocals = true;
    for(unsigned int i = 0; i <= strlen(text); i++) {
        if(strchr(vocals, text[i]) != NULL) //* means that it has vocals
            notVocals = false;
        if(text[i] == 'i' && text[i + 1] == 'i') //* it can accept 'i' but not next to eachother
            notVocals = false;
    }

    notVocals? cout << "DA": cout << "NU";
}