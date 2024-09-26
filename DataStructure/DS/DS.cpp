#include <iostream>
#include <queue>
#include <vector>
#include <string>

auto main() -> int {

  std::vector<int> nodes = { 92, 73, 45, 12, 6, 30, 42, 67, 88 };

  std::cout << "Raw Data: ";
  for(int i=0; i < (int)nodes.size(); i++)  {
    std::cout << nodes[i] << " ";
  }
  std::cout << "\n";

  std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

  for(auto &x: nodes) {
    pq.push(x);
  }

  std::cout << "Priority Queue Sorted: ";
  while(pq.empty() != true) {
    std::cout << pq.top() << " ";
    pq.pop();
  }
  std::cout << "\n";

  std::wstring ws1 = L"Infinity: \u221E\n";
  std::wcout << ws1;
  
  return 0;
}