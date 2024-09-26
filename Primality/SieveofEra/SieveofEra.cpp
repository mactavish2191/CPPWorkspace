#include <iostream>
using namespace std;
//Checking primality with Sieve of Eratosthenes
int main()
{
    int limit{0};
    cin >> limit;
    for (int i=2; i<=limit; i++) {
        bool isPrime = true;
        for (int j=2; j*j<=i ; j++) {
            if (i%j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime == true) {
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}
