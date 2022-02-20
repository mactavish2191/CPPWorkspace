#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void func(int &&x){
  int k = move(x);
  cout << k << "\n" << x << "\n";
}

int main(){

  func(5 + 6);

   int list[] = {45, 31, 46, 67, 88, 91};
   int k = 66;

   cout << k << "\n";
   for(int i=0; i<6; i++){
     cout << list[i] << " ";
   }
   cout << "\n";

   k = move(list[2]);

   cout << k << "\n";
   for(int i=0; i<6; i++){
     cout << list[i] << " ";
   }
   cout << "\n"; 

  return 0;
}
