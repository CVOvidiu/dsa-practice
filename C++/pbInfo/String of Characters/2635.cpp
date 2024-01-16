#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ifstream in("capslock.in");
ofstream out("capslock.out");

int main() {
    char a[256];
    bool sw = false;
    in.get(a, 256);
    
    for(int i = 0; i < strlen(a); i++) {
        while(a[i] == '#') { //? if '#' then we delete it and flip the switch
            char aux[256];
            strcpy(aux, a + i + 1);
            strcpy(a + i, aux);
            if(sw == false)
                sw = true; //? Caps ON
            else
                sw = false;
        }
        
        if(isalpha(a[i])){ //? if the caracter is letter
            if(sw == true && islower(a[i]))
                a[i] -= 32;
            else if(sw == false && isupper(a[i]))
                a[i] += 32;
        }
    }

    out << a;
}