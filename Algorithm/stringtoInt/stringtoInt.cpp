#include <iostream>
#include <string>

auto main() -> int {

  const char *numbers = "2223334";
  int toNum[7];
  for (int i = 0; i < 7; i++) {
    toNum[i] = std::atoi(numbers[i]);
    std::cout << toNum[i] << " ";
  }
  std::cout << "\n";

  return 0;
}
