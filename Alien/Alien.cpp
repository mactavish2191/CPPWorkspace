#include <iostream>
#include <map>
#include <string>
using namespace std;

struct Cmp {
  bool operator()(const string& a, const string& b) const {
    if (a.size() != b.size()) return a.size() > b.size();
    return a < b;
  }
};

int main() {
  int T, prob=1;
  for (cin >> T; T--;) {
    int N;
    cin >> N;
    map<string, int, Cmp> m;
    for (int i = 0; i < N; i++) {
      string s;
      cin >> s;
      while (s.size()) {
        m[s]++;
        s = s.substr(1);
      }
    }

    int ret = 0;

    for (auto const& it : m){
      if (it.second >= 2) {
        ret += 2;
        string s = it.first.substr(1);
        while (s.size()) {
          m[s] -= 2;
          s = s.substr(1);
        } //end while
      }
    }
    cout << "Case #" << prob++ << ": " << ret << endl;
  }

  return 0;
}
