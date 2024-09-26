#include <iostream>
#include <string>
#include <cstdint>
#include <charconv>

using namespace std;
string ln = "\n";

unsigned int average(unsigned int a, unsigned int b)
{
    return (a + b) / 2;
}

auto main() -> int {
  char str[] = "11.03e 0mn";
  char* end = str;
  double x = strtod(str, &end);

  cout << str << "\n" << end << "\n" << x << "\n";

  /*
    auto [p, ec] = std::from_chars(st.data(), st.data()+st.size(), result);
    still the from_chars function is not supportted by gcc 9.3 as of now
  */

  //If the divisor is power of two, 2^n 
  int value = 2000;
  int remainder = value % 1024;
  cout << remainder << "\n";
  cout << (value & 1023) << "\n";

  
  unsigned int first = 0x80000000U;
  unsigned int second = 0x80000000U; 

  cout << first << ln;
  cout << second << ln;
  cout << average(first, second) << ln;
  

  return 0;
}