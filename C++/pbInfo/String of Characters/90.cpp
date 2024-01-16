#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

ifstream in("vocmax.in");
ofstream out("vocmax.out");

int main() {
    char a[251], maxPhrase[251];
    int maxCounter = 0; //? The biggest number of vocals 

    in.getline(a, 251); //? Get one line at a time; get rid of number of phrases because we do not need them
    
    while(in.getline(a, 251)) { //? While we read each phrase
        char voc[] = "aeiou";
        int counter = 0; //? Count the vocals of each phrase

        for(int i = 0; i < strlen(a); i++)
            if(strchr(voc, a[i]) != NULL) //? We found a vocal
                counter++;

        if(counter > maxCounter) { //? Find out the phrase with the biggest number of vocals
            maxCounter = counter;
            strcpy(maxPhrase, a);
        }
    }

    out << maxPhrase;
}