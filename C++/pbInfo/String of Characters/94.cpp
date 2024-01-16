#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char a[21];

    cin.get(a, 21);

    for(int i = 0; i < strlen(a); i++) {
        char voc[] = "aeiou";
        if(strchr(voc, a[i]) != NULL) { //? Found a vocal at position i
            //? Eliminate the vocal
            char aux[21];
            strcpy(aux, a + i + 1);
            strcpy(a + i, aux);
            i--; //? If there are consecutive vocals
        }
    }

    cout << a;
}