// Logic: To determine the biggest sequence of non vocals we need:
// while the character is not a vocal we store each character inside an array of characters.
// if we encounter a vocal, we verify if the array of characters built until now is the biggest we found inside a max array of characters

#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char a[256];
    cin >> a;
    char actual[256] = "", max[256] = "";

    char aux[2]; // to concatenate a character we need aux because we can't concatenate single characters
    aux[1] = '\0';

    for(int i = 0; i <= strlen(a); i++) { // search even the space at the end
        if(strchr("aeiou", a[i]) == NULL && a[i] != '\0') {
            aux[0] = a[i];
            strcat(actual, aux);
        } else {
            if(strlen(actual) >= strlen(max))
                strcpy(max, actual);
            strcpy(actual, ""); // we reset the actual string of characters to continue with the search
        }
    }

    cout << max;
}