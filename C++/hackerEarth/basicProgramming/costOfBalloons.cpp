// https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/mojtaba-prepares-contest-29b2a044/

#include <iostream>
using namespace std;

int main() {
    
    unsigned T; // Num of test cases
    unsigned gB, pB; // Cost of green balloon && purple balloon
    unsigned n; // Num of participants
    unsigned i, j; // i - Status of 1st pb, j - Status of 2nd pb
    unsigned x, y; // x - Index of cases && y - Index of participants

    // sum - sum of prices for each case

    cin >> T;

    for(x = 1; x <= T; x++) {

        if(x % 2 != 0) {
            
            unsigned sum = 0;

            cin >> gB >> pB;
            cin >> n;

            for(y = 1; y <= n; y++) {
                cin >> i >> j;

                sum += i * gB + j * pB;
            }

            cout << sum << endl;
        }
        
        else if(x % 2 == 0) {

            unsigned sum = 0;

            cin >> gB >> pB;
            cin >> n;

            for(y = 1; y <= n; y++) {
                cin >> i >> j;
                
                sum += i * pB + j * gB;
            }

            cout << sum << endl;
        }
    }
}