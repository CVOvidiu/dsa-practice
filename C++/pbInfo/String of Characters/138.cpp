#include <iostream>
#include <string.h>

using namespace std;

//? Vector de frecventa cu caractere concatenate din sirul dat
//* O alta rezolvare ar fi sa ne plimbam peste literele mici in ordine alfabetica si un vector de frecventa peste toate
int c[256]; //? frequency array of characters; global so the entire array will be assigned 0

int main() {
    char a[256], b[256] = ""; //? a - given text, b - array of unique characters inside the given text
    cin.get(a,256);

    //? Form the unique characters array
    char aux[2]; //? to concatenate a character because we can't concatenate a single character because is not a string that ends with \0
    aux[1] = '\0';
    for(int i = 0; i < strlen(a); i++)
        if(strchr(b, a[i]) == NULL && islower(a[i])) { //? Have not found the character inside b
            aux[0] = a[i]; //? to form a string because concatenation accepts only strings to concatenate
            strcat(b, aux);
        }

    //? The number of appearances inside the text
    for(int i = 0; i < strlen(b); i++)
        for(int j = 0; j < strlen(a); j++) {
            if(b[i] == a[j])
                c[i]++;
        }

    //? Figure out the most frequent letter inside the text
    int max = 0; //? Max number of appearances
    char maxc = 'a'; //? The letter that has the max number of appearances; delcared 'a' to output the one in alphabetical order
    for(int i = 0; i < strlen(b); i++) { //? The length of b is the same as c
        if(c[i] >= max && int(c[i]) < int(maxc)) { //? Find out the letter that appears the most in the text in alphabetical order
            max = c[i];
            maxc = b[i];
        }
    }

    cout << maxc;
}