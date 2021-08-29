#include <iostream>
#include <cstdio>
#include <string>
#include <sstream> 
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cassert>
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

int main()
{
  int T;
  cin >> T;
  cin.ignore();

  FOR(i, T) { //execute test cases
    int length;
    int sum =0;

    map<int, vector<int> > pp;

    cin >> length;
    int val =0;

    FOR(j, length) {
      cin >> val;
      pp[val].pb(j);
    }

/*  for(auto &k : pp) {
      cout << k.first << " :";
      for(auto len : k.second ) {
        cout << len << " ";
      }
      cout << "\n";
    } */

    for(const auto &key : pp) {
      if(key.second.size() == 1) {
        sum += 0;
      }
      else {
         sum += key.second[key.second.size() - 1] - key.second[0];
      }
    }

    println(sum);
  }

  return 0;
}