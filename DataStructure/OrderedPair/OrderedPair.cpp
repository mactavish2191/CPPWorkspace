#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
using namespace std;

long long combination(long long n)
{
    if (n < 2) {
        return 0;
    }
    return (n*(n-1))/2;
}
int main() {
    string input = "";
    getline(std::cin, input);

    long long n,k;
    stringstream ss;
    ss << input;
    ss >> n;
    ss >> k;

    vector<unsigned int> count(k, 0);

    for (long long i=1; i<=n; i++) {
        if (i%k != 0) {
            count[i%k -1] += 1;
        }
        else
        {
            count[k -1] += 1;
        }
    }

    long long sum(0);
    for (auto& i : count ) {
        sum += combination(i);
    }
    cout << sum <<"\n";

    return 0;
}

