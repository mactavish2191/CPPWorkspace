#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int c, char **v){

  vector<int> av = {3, 5, 1, 12, 45, 99, 33, 43, 22, 19, 17, 23};

  int cap = 3;
  cout << "Integers that are multiples of "<< cap << ": " << count_if(av.begin(), av.end(), [cap](int x) { return !(x % cap);} ) << "\n";

  int sum =0;
  for_each(av.begin(), av.end(), [&sum](int x) { sum += x;} );

  cout << "Sum : " << sum << "\n";
  return 0;
}