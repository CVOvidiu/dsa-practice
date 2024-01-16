// https://www.pbinfo.ro/probleme/169/sumcif

#include <iostream>

using namespace std;

int main() {
  int a;
  cin >> a;

  int uc1 = a % 10;
  a = a / 10;
  int uc2 = a % 10;
  a = a / 10;
  int uc3 = a % 10;

  cout << uc1+uc2+uc3;
}
