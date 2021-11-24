#include <iostream>
#include <cstdio>
#include <string> 
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

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

const int LIM = 10001;

int main()
{
  vector<int> filter(LIM);
  for(int i=0; i < LIM; i+=2) {
    filter[i] = 1;
    filter[i+1] = 0; 
  }

  int T;
  cin >> T;
  cin.ignore();

  FOR(i, T) { //execute test cases
    int N;
    int C01, C10;

    cin >> N >> C01 >> C10;

    vector<int> zerolead(N);
    vector<int> onelead(N);
    int tmp;
    FOR(j, N) {
      cin >> tmp;
      onelead[j] = (filter[j] ^ tmp);
      zerolead[j] = (filter[j+1] ^ tmp);
    }
    //printContainer(onelead);
    //printContainer(zerolead);

    int lsum = accumulate(onelead.begin(),onelead.end(), 0);
    int rsum = accumulate(zerolead.begin(),zerolead.end(), 0);

    int mincos = min(lsum, rsum);

		if(mincos <= ( C01 + C10 )) {
			println(mincos);
		}
		else {
			println(C01 + C10);
		}
  }
  return 0;
}