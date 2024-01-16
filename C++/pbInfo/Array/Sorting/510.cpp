#include <iostream>

using namespace std;

int main() {
    int a[1000], temp, n;
    cin >> n; // how many numbers you have to check for prime
    
    // is temp prime?
    int j = 0; // save how many numbers are prime
    for(int i = 1; i <= n; i++) { // scroll through the numbers you have to check
        cin >> temp; // we don't store the number right away in the array because we have to check if prime first
        bool prime = true; 
        if(temp < 2) // 0 & 1 are not prime
            prime = false;
        else
            for(int d = 2; d * d <= temp; d++) // we scroll through the potential divisors
                if(temp % d == 0) // if we find a divisor, the number is not prime
                    prime = false;

        if(prime) { // if the number is prime we store it inside the array and update how many numbers are in the array currently
            a[j] = temp;
            j++;
        }
    }
    
    // Sorting the array
    bool sorted;

    do{
        sorted = true;
        for(int i = 0; i < j - 1; i++) // j is the limit of the array
            if(a[i] > a[i + 1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                sorted = false;
            }
    } while(!sorted);

    // Output the array
    for(int i = 0; i < j; i++) 
        cout << a[i] << " ";
}