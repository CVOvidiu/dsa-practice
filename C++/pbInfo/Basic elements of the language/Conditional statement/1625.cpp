// https://www.pbinfo.ro/probleme/1625/ec2

#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    double delta = pow(b, 2) - 4 * a * c;

    if(delta < 0)
        cout << "Nu are solutii reale";
    else if(delta == 0) {
        double x = (-b) / (4 * a);
        cout << "Radacina dubla " << x;    
    }
    else if(delta > 0) {
        double x1 = (-b + sqrt(delta)) / (4 * a);
        double x2 = (-b - sqrt(delta)) / (4 * a);
        cout << x1 << " " << x2;
    }
}