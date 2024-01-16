// https://www.pbinfo.ro/probleme/173/medie1

#include <iostream>
#include <iomanip>

using namespace std;

int n1, n2, n3;
float media;

int main() {
  cin >> n1 >> n2 >> n3;
  media = (n1 + n2 + n3) / 3.0;
  media = int(media * 100);
  media = float(media / 100.00);
  cout << fixed << setprecision(2) << media;
}
