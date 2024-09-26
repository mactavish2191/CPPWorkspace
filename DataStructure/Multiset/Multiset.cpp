#include <iostream>
#include <vector>
#include <set>

using namespace std;

//print a container
template<typename T>
void printContainer(T &t) {
    for (const auto &e : t) std::cout << e << " ";
    std::cout << "\n";
}

auto main() -> int {

	multiset<int> ms;

	ms.insert(50);
	ms.insert(10);
	ms.insert(20);
	ms.insert(10);
	ms.insert(50);
	ms.insert(60);

	printContainer(ms);

	ms.erase(10);

	printContainer(ms);


	return 0;
}