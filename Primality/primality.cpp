#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
using ULL = unsigned long long;
const unsigned int MOD = 1000'000'007;

auto power(ULL a, ULL n)-> ULL {
    ULL result = 1;
    while (n > 0) {
        if (n & 1) //equivalent to b % 2 == 1 
            result = (result * a) % MOD;
        a = (a * a) % MOD;
        n = n >> 1; // equivalent to b = b / 2
    }
    return result;
}

auto main() -> int {

    int num;
    cout << "Enter: ";
    cin >> num;
    cout << setprecision(16);
    cout << "Right Shift divide: " << (num >> 1) << "\n";

    return 0;
}