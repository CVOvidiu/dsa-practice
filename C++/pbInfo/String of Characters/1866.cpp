#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

ifstream in("prosir.in");
ofstream out("prosir.out");


int main() {
    char text[201];
    in.get(text, 201);

    for(unsigned int i = 0; i <= strlen(text); i++)
        if((text[i] == ' ' && text[i - 1] != ' ') || text[i] == '.')
            text[i - 1] = '5';

    out << text;
}