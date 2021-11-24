#include <iostream>
#include <string>
#include <random>
#include <chrono>
#define ln "\n"
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

auto main() -> int {
	cout << "Hello " << ln;

	for (int i = 0; i < 30; ++i)
	{
		cout << uid(10, 100) << " ";
	}
	cout << ln;

	return 0;
}