// https://www.pbinfo.ro/probleme/1/sum

#include <iostream>
#include <fstream>

using namespace std;

ifstream f("sum.in");
ofstream o("sum.out");

int main() {
  long long int a, b;

  f >> a >> b;

  int S = a + b;

  o << S;
}
