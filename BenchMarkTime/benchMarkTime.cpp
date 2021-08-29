#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

int main(){

  auto start = chrono::high_resolution_clock::now();
  //-----------------------------------------------

  //for(int i=0; i<100; ++i){
  //  if(50%2 == 0)
      cout << 50 % 2 << "\n";
  //}
  //cout << "\n";

  //-----------------------------------------------
  auto end = chrono::high_resolution_clock::now();

  auto result = end - start;
  cout << chrono::duration<double,nano> (result).count() << " nano sec" <<"\n";

  return 0;
}
