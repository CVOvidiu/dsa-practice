// https://www.pbinfo.ro/probleme/8/maxim3

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream in("maxim3.in");
ofstream out("maxim3.out");

int main() {
    int a, b, c;
    in >> a >> b >> c;

    out << max(a, max(b, c));
}