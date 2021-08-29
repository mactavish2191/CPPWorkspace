#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  cin.ignore();

  vector<int> freq(k, 0);
  int tmp;

  //calculate cardinality of the remainder values
  for(int i=0; i<n ; i++){
    cin >> tmp;
    freq[tmp % k]++; 
  }

  int ndivCardinality = 0;

  //check for the 0 case
  ndivCardinality = min(freq[0], 1);
  //check for the k/2 case
  ndivCardinality += (k%2 == 0 && freq[k/2] >= 1)? 1:0;
   
  //check for the max buckets
  int maxBucket = 0;
  if(k%2 == 0)
    maxBucket = (k/2) -1;
  else
    maxBucket = k/2;

  //count for the biggest subset of non divisible remainders
  for(int i=1; i<=maxBucket; i++){
    ndivCardinality += max(freq[i], freq[k-i]);
  }

  cout << ndivCardinality << "\n";

  return 0;
}
