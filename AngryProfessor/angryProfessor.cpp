#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <tuple>
#include <numeric>
#include <algorithm>

using namespace std;

int main(){
	FILE *handle = freopen("test.txt", "r", stdin);
	if(!handle){
		cerr << "File failed\n";
		exit(1);
	}


	int T;
  cin >> T;
  cin.ignore();

  while(T--){
    int N, K;
    cin >> N >> K;

    vector<int> student(N);

    int count = 0, tmp;
    for(int i=0 ; i<N; i++){
      cin >> tmp;
      if(tmp <= 0)
        count++;
    }
    
    if(count < K)
      cout << "YES\n";
    else
      cout << "NO\n";

  }

	return 0;
}