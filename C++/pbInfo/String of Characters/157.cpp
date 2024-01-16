#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

ifstream in("doarvocale.in");
ofstream out("doarvocale.out");

int main() {
    char a[31];
    int counter = 0;

    in.getline(a, 31); //? Get rid of the number of words because we do not need it; getline because with 'get' we get all the content of the file

    while(in.getline(a, 31)) {
        bool ok = true;
        
        for(int i = 0; i < strlen(a); i++)
            if(strchr("aeiou", a[i]) == NULL)
                ok = false;

        if(ok == true)
            counter++;
    }

    out << counter;
}