#include <iostream>
#include <queue>
#include <vector>
#include <functional>

int main(){

	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	std::vector<int> v = {70, 51, 94, 71, 40, 33, 21, 30};

	for(const int &i : v)
		q.push(i);

	while(q.empty() != true){
		std::cout << q.top() << " ";
		q.pop();
	}
	std::cout << "\n";

	return 0;
}