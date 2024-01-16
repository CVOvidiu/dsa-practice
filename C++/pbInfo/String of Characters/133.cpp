#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char a[21], b[21], build[42] = "";
    /*
    ? a, b - names
    ? build - program asks us to build a new array following the criteria
    ! build must be empty string otherwise will lead to problem at concatenation
    */

    cin >> a;
    cin >> b;

    char voc[] = "aeiouAEIOU";
    for(int i = 0; i < strlen(b); i++) {
        if(strchr(voc, b[i]) != NULL) {
            char aux[21];
            strcpy(aux, b + i + 1);
            strcpy(b + i, aux);
            i--; //? in case of consecutive vocals and not the first letter
        }
    }

    strcat(build, b);
    strcat(build, " ");
    strcat(build, a);

    cout << build;
}