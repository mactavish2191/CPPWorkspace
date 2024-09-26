#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <map>
#include <set>
#define FOR(i,n) for(int i=0; i<n; i++)

using namespace std;

//Functor passed to a set
struct CaseInsensitiveComapre{
  bool operator()(const string &x, const string &y) const{
    return ( strcasecmp(x.c_str(), y.c_str()) < 0 );
  }
};

int main ()
{
  vector<int> list = {4, 5, 6, 2, 8, 12, 54, 99, 10, 54, 43, 70};
  set<pair<int, int>> k;
  map<string, double> salaries;

  set<string,CaseInsensitiveComapre> s;

  salaries["matt"] = 7500.00f;
  salaries["harry"] = 6500.00f;


  s.insert("Hello");
  s.insert("HeLLo");

  k.insert({2, 3});
  k.insert({4, 5});
  k.insert({3, 8});
  k.insert({12, 33});
  k.insert({21, 34});

  char32_t code = U"";


  for(auto &x : salaries){
      cout << x.first << " " << x.second << "\n";
  }

  return 0;
}
