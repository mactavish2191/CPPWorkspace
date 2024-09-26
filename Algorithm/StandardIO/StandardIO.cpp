#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>
#include <sstream> 
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <chrono>
using namespace std;


#define MOD 1000'000'007
#define fastio ios_base::sync_with_stdio(false)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define SZ(x) ((int)x.size())

#define FOR(i,n) for(int i=0;i<(int)n;++i)
#define FORI(i,n) for(int i=1;i<=(int)n;++i)

#define REP(i,a,b) for(int i=a; (int)i<=b;++i)
#define REPD(i,a,b) for(int i=a; (int)i>=b;--i)

#define REMAX(a,b) a=max( a, b);
#define REMIN(a,b) a=min( a, b);
#define ln '\n'

//print a container
template<typename T>
void printContainer(T &t) {
	for(const auto &e : t) std::cout << e << " ";
	std::cout << "\n";
}

//print a object
template<typename T>
void println(T &t) {  //lhs ref
    std::cout << t << "\n";
}

template<typename T>
void println(T &&t) {  //rhs ref
    std::cout << t << "\n";
}

using LL = long long;
using ULL = unsigned long long;

//important functions
/*auto compute_Binomail_Coefficient() -> void {

    for (ULL i = 0; i <= MAX; i++) {
        comb[i][0] = comb[i][i] = 1;

        for (ULL j = 1; j < i; j++) {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1]; //n+1Cr = nCr + nCr-1 
            if (comb[i][j] >= MOD)
                comb[i][j] -= MOD;
        }
    }
}*/

auto power(ULL a, ULL b)-> ULL {
    ULL result = 1;
    while (b > 0) {
        if (b & 1) //equivalent to b % 2 == 1 
            result = (result * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1; // equivalent to b /= 2
    }
    return result;
}

int main()
{	
    fastio;
	cout << setprecision(15);
	// auto start = chrono::steady_clock::now();

	// println(pow(9, 8));

	// auto end = chrono::steady_clock::now();
	// auto time_diff = end - start;
	// cout << chrono::duration <double, milli> (time_diff).count() << " ms\n";

	// start = chrono::steady_clock::now();
 //    println(power(9, 8));
 //    end = chrono::steady_clock::now();
 //    time_diff = end - start;
 //    cout << chrono::duration <double, milli> (time_diff).count() << " ms\n";

    string sent = "This is a very different.";

    cout << "Size of sent string container is " << sizeof( sent ) << ln;
    cout << "Size of char * is " << sizeof( char* ) << ln;
    cout << "Size of void * is " << sizeof( void* ) << ln;
    cout << sent.capacity() << " " << sent.length() << ln; 

    return 0;
}