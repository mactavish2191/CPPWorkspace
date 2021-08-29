#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>

using namespace std;

vector<int> A;
typedef long long int64;

int solve(int l, int r){
  if(r-l <= 1){
    return 0;
  }

  int64 total = accumulate(A.begin()+l, A.begin()+r, 0LL);

  if(total % 2 != 0){
    return 0;
  }

  int64 partial = 0;

  for(int i=l; i<r; i++){
    partial += A[i];
    if(partial * 2 == total){
      return 1 + max(solve(l, i+1), solve(i+1, r));
    }
  }   

  return 0;
}


int main(){
  FILE *handle = freopen("input_arraysplit.txt", "r",  stdin);
  if(!handle){
    cerr << "Failed to open file...\n";
    exit(EXIT_FAILURE);
  }
  
  int T;
  cin >> T;

  while(T--){
    int N;
    cin >> N;
    A.resize(N);

    for(int i=0; i<N; i++){
      cin >> A[i];
    }
    cout << solve(0, N) << "\n";
  }


  return 0;
}