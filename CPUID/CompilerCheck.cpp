#include <iostream>

int main()
{
  #ifdef __clang_major__
    std::cout << "Clang detected version " << __clang_major__ << "."  << __clang_minor__ << "\n";
  #endif

  #ifdef __GNUC__
    std::cout << "GCC detected version " <<  __GNUC__ << "."  << __GNUC_MINOR__ << "\n";
  #endif

  return 0;
}