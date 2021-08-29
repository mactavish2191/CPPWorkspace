#include <iostream>
#include <vector>
using namespace std;
vector<int> factorial(300);

// max limit = 100! to 150 !

void extraLongFactorials(int n) {
  //store the first number into vector
  int length = 1;
  factorial[0] = 1;

  int carry = 0, tmp;
  for(int i=2; i<=n; i++){
    for(int j=0; j<length; j++){
      tmp = factorial[j]*i + carry;
      factorial[j] = tmp % 10;
      carry = tmp / 10;
    }

    while(carry){
      factorial[length] = carry%10;
      carry/=10;
      ++length;
    }
  }
  for(int i = length-1; i>=0; i--){
    cout << factorial[i];
  }
  cout << "\n";
}

int main()
{
    int n;
    cin >> n;

    extraLongFactorials(n);

    return 0;
}