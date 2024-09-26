#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <iterator>
#include <chrono>

using namespace std;

//minmax algorithm
auto solve() -> int {
	vector v = {4, 6, 10, 34, 12, 2};
	auto [a, b] = minmax_element(v.begin(), v.end());
	return *b - *a;
}

//add elements in a range
auto accumaulate_calc() -> int{
	vector x(100, 0);
	iota(x.begin(), x.end(), 1);
	auto store = accumulate(x.cbegin(), x.cend(), 0);
	return store;
}

auto reduce_calc() -> int{
	vector x(100, 0);
	iota(x.begin(), x.end(), 1);
	auto store = reduce(x.cbegin(), x.cend(), 0, plus{});
	return store;
}

auto adjacent_diff(){
	vector x = {1, 2, 3, 4, 5};
	vector y(x.size(), 0);
	adjacent_difference(x.begin(), x.end(), y.begin());
	copy(y.begin(), y.end(), ostream_iterator<int>{cout , " "});
	cout << "\n";
}

auto fibonacci(){ //transforming the container 
	vector list(10, 1);
	adjacent_difference(list.begin(), list.end()-1, list.begin()+1, plus{});
	copy(list.begin(), list.end(), ostream_iterator<int>{cout , " "});
	cout << "\n";
}

auto root_mean_square() -> float{ //inner product default : 1.multiply 2.add
	vector x = {2, 2, 2, 2};
	vector y = {2, 2, 2, 2};
	float factor = 1.0f / x.size();
	return sqrt(inner_product(x.begin(), x.end(), y.begin(), 0)) * factor;
}

auto overload_inner1() -> int{ //inner product overload
	vector x = {2, 2, 3, 2};
	vector y = {2, 3, 2, 2};
	return inner_product(x.begin(), x.end(), y.begin(), 0, plus{}, [](auto a, auto b) { return max(a,b); });
}

auto overload_inner2() -> int{ //inner product overload 1.plus 2.multiply
	vector x = {2, 2, 2, 2};
	vector y = {3, 3, 3, 3};
	return inner_product(x.begin(), x.end(), y.begin(), 1, multiplies{}, plus{});
}

auto op_transform_reduce() -> int{ //default operation is 1. multiply 2.add
	vector v = {1, 2, 3};
	vector u = {2, 3, 4};

	//return transform_reduce(v.begin(), v.end(), u.begin(), 0);
	//return transform_reduce(v.begin(), v.end(), u.begin(), 0, plus{}, multiplies{} );
	return transform_reduce(v.begin(), v.end(), u.begin(), 0,
													[](auto a, auto b) { return max(a,b); },
													[](auto a, auto b) { return a + b * b; }
													);
}

/* complex transform operation */
auto op_transform_reduce1() -> int{
	vector x = {1, 4, 2, 8, 6};
	sort(x.begin(), x.end());
	/*return transform_reduce(x.cbegin(), --x.cend(), ++x.begin(), numeric_limits<int>::max(),
	                        [](auto a, auto b) { return min(a, b); },
													[](auto a, auto b) { return abs(a - b); }
													); */

	return transform_reduce(++x.cbegin(), x.cend(), x.begin(), numeric_limits<int>::max(),
	                        [](auto a, auto b) { return min(a, b); },
													minus{}
													);

}

/* partial sum */
auto compound_sum() {
	vector v = { 2, 2, 2, 2, 2};
	vector u(5, 0);
	partial_sum(v.begin(), v.end(), u.begin(), multiplies{});
	copy(u.begin(), u.end(), ostream_iterator<int>{cout, " "});
	cout << "\n";
}

/* leetcode rainwater example */
using rev = reverse_iterator<vector<int>::iterator>;

auto trap() -> int {
	vector v = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	vector u(v.size(), 0);

	auto it = max_element(v.begin(), v.end());
	inclusive_scan(v.begin(), next(it), u.begin(), [] (auto a, auto b) { return max(a, b); } );
	copy(u.begin(), u.end(), ostream_iterator<int>(cout, " ")); cout << "\n";
	inclusive_scan(v.rbegin(), rev(it), u.rbegin(), [] (auto a, auto b) { return max(a, b); } );
	copy(u.begin(), u.end(), ostream_iterator<int>(cout, " ")); cout << "\n";

	return transform_reduce(u.cbegin(), u.cend(), v.cbegin(), 0, plus(), minus());

}

auto main() -> int {

	//cout << solve() << "\n";
	//cout << accumaulate_calc() << "\n";
	//cout << reduce_calc() << "\n";
	//adjacent_diff();
	//cout << root_mean_square() << "\n";
	//cout << overload_inner1() << "\n";
	//cout << overload_inner2() << "\n";
	//fibonacci();
	//cout << op_transform_reduce() << "\n";
	//cout << op_transform_reduce1() << "\n";
	//compound_sum();
	cout << trap() << "\n";

	return 0;
}