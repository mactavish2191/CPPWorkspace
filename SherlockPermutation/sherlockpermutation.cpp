#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
const unsigned int MOD = 1000'000'007;

/*
  string list = "00111";
  do {
    cout << list << "\n";
  }while(next_permutation(list.begin(), list.end() ));
*/


using ULL = unsigned long long;

//Factorial will start fact from bigger to smaller
auto fact(unsigned int F, unsigned int limit = 1) -> ULL {
    if (F == 0 || F == 1) {
        return 1;
    }
    else {
        ULL result = F;

        for (unsigned int i = F - 1; i >= limit; i--) {

            result = result * i;

            /*if (result < MOD) {
                result = result * i;
            }
            else {
                result = (result % MOD) * i;
            }*/
        }

        return result;
    }
}


auto calculate(unsigned int N, unsigned int M) -> ULL {
    if (M == 1) {
        return 1;
    }
    else {
        unsigned int total = N + M - 1;
        if (N >= M - 1) {
            ULL num = fact(total, N + 1);
            ULL dem = fact(M - 1);
            return num / dem;
        }
        else {
            ULL num = fact(total, M);
            ULL dem = fact(N);
            return num / dem;
        }
    }
}


int main() {

    ifstream icin("input.txt", ios::in);

    int T = 0;
    icin >> T;

    while (T--) {
        unsigned int N, M;
        icin >> N >> M;

        ULL result = calculate(N, M);
        cout << result << "\n";
    }

    icin.close();

    cin.get();
    return 0;
}