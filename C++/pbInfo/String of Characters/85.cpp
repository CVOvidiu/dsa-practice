//? aflam pe ce pozitie e vocala si punem pe pozitia vocalei + 1 '*'

#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char vocals[] = "aeiou";
    char a[101];

    cin.get(a, 101);

    bool sw = false;
    for(int i = 0; i < strlen(a); i++) {
        if(strchr(vocals, a[i]) != NULL) { //? Found vocal at position i
            sw = true;
            char aux[101];
            strcpy(aux, a + i + 1); //? insert AFTER the vocal
            strcpy(a + i + 2, aux);
            a[i + 1] = '*';
        }
    }

    if(sw == false)
        cout << "FARA VOCALE";
    else
        cout << a;
}