#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <vector>
#include <x86intrin.h>

int main(){
  using namespace boost::multiprecision;
  //unsigned __int128_t k = (__int128_t(1) << 128) - 1;
  cpp_int limit = (cpp_int(1) << 256) - 1;

  std::cout << limit << "\n";
  //std::cout << k << "\n";

  return 0;
}