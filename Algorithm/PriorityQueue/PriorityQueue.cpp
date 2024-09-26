#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iterator>
#include <set>

using namespace std;
using pii = pair<int, int>;

template<typename T>
void print_queue(T q) {
	while (!q.empty()) {
		cout << q.top().first << ':' << q.top().second << " ";
		q.pop();
	}
	cout << '\n';
}

template<typename T>
void print_multiset(T q) {
	for (auto &k : q) {
		cout << k.first << ":" << k.second << " ";
	}
	cout << '\n';
}

auto main() -> int {

	const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
	// priority_queue<pii, vector<pii>, greater<pii>> pq;

	// for (int i : data) {
	// 	pq.push({i, i + 1});
	// }

	// print_queue(pq);

	// pq.push({9, 10});
	// pq.push({9, 11});

	// print_queue(pq);


	multiset<pii> ms;

	for (auto i : data) {
		ms.insert({i, i + 1});
	}

	print_multiset(ms);

	ms.insert({9, 10});
	ms.insert({9, 11});

	print_multiset(ms);

	return 0;
}