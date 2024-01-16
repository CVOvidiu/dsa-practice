#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

ifstream in("palindrom.in");
ofstream out("palindrom.out");

int main() {
    char cuv[21];

    in >> cuv; //? we don't need the number of words
    
    while(in >> cuv) { //? for each word
        bool sw = true; //? switch false if word is not palindrome; presume each word is a palindrome at first

        //? Compare the words from start and end simultaniously
        int i = 0;
        int j = strlen(cuv) - 1;
        while(i <= strlen(cuv) / 2) {
            if(cuv[i] != cuv[j]) { //? if one letter is different is no longer considered as palindrome
                cout << cuv[i] << " " << cuv[j] << "\n";
                sw = false;
                break;
            } else i++, j--;
        }

        if(sw == true)
            out << "1\n";
        else
            out << "0\n";
    }
}