#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <tuple>
#include <numeric>
#include <algorithm>

using namespace std;
using P = const pair<int, int>;

int main(){
	FILE *handle = freopen("input_Numbers.txt", "r", stdin);
	if(!handle){
		cerr << "File failed\n";
		exit(1);
	}


	map<int, int> freq;
	int N, tmp;
	cin >> N;
	cin.ignore();
	for(int i=0; i<N; i++){
		cin >> tmp;
		freq[tmp]++; 
	}

	int sum = INT_MIN;

	if(freq.size() == 1){   // single repeating element
		auto it = freq.begin();
		cout << it->second << "\n";
	} 
	else{										// pair wise comparisons
		for(auto [i, c] = tuple{freq.begin(), 1} ; i != freq.end(); ++i){
			for(auto k = next(freq.begin(), c) ; k != freq.end() && c < freq.size(); ++k){
				//cout << i->first << " " << k->first << "\n";
				if(abs(i->first - k->first) <= 1){
					int tmp = i->second + k->second;
					if(tmp > sum){
						sum = tmp;
					}
				}
			}
			c++;
		}

		auto value = *max_element(freq.begin(), freq.end(), [](P &x, P &y) { return x.second < y.second; } );
		if(value.second > sum )
			cout << value.second << "\n";
		else
			cout << sum << "\n";
	}

	return 0;
}