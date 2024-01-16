// https://www.pbinfo.ro/probleme/102/cifre

#include<iostream>

using namespace std;

int main() {
  long long int n, s;

  cin >> n;

  int ucU, ucZ;

  ucU = n % 10;
  n = n / 10;
  ucZ = n % 10;

  s = ucU + ucZ;

  cout << s;
}
