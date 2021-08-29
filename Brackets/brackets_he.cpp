#include <iostream>
#include <map>
#include <string>

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define SZ(x) ((int)x.size())

#define FOR(i,n) for(int i=0;i<(int)n;++i)
#define FORI(i,n) for(int i=1;i<=(int)n;++i)

#define REP(i,a,b) for(int i=a; (int)i<=b;++i)
#define REPD(i,a,b) for(int i=a; (int)i>=b;--i)

#define REMAX(a,b) a=max( a, b);
#define REMIN(a,b) a=min( a, b);


//print a container
template<typename T>
void printContainer(T &t) {
	for(const auto &e : t) std::cout << e << " ";
	std::cout << "\n";
}

//print a object
template<typename T>
void println(T &t) {
    std::cout << t << "\n";
}

template<typename T>
void println(T &&t) {
    std::cout << t << "\n";
}

using namespace std;


// int main() {
// 	string str = ")()(())()(";
// 	//getline(cin, str);

// 	map<char, int> qt;

// 	for(const auto &c : str){
// 		qt[c]++;
// 	}

// 	char openBkt = '(';
// 	char closeBkt = ')';

// 	if (qt[openBkt] == qt[closeBkt]){
// 		int c=0, d=0, shiftPos=0;

// 		FOR(i, str.length()) {
// 			if(str[i]== openBkt) 
// 				c++;
// 			else 
// 				c--;

// 			//cout << i << " " << c << " " << d <<"\n";

// 			if(c < d) {
// 					d=c;
// 					shiftPos = i+1;
// 			}

// 			//println(shiftPos);
// 		}

// 		//shift the position of characters to left by shiftPos
// 		println(str);
// 		rotate(str.begin(), str.begin() + shiftPos, str.end());
// 		println(str);

// 		int ans=0;
// 		c=0;
// 		FOR(i, str.length()) {
// 			if(str[i]== openBkt) 
// 				c++;
// 			else 
// 				c--;

// 			if(c==0)
// 				ans++;
// 		}
// 		println(ans);
// 	}
// 	else {
// 		println(0);
// 	}


// 	return 0;
// }

//best solution
int main() {
	string str = ")()(())()(";
	//getline(cin, str);

	map<int, int> qt;
	int c=0;

	FOR(i, str.length()) {
		if(str[i] == '(')
			c++;
		else
			c--;
		
		qt[c]++;
	}

	for( const auto &x : qt) {
		cout << x.first << " " << x.second << "\n";
	}

	if(c == 0){
		println(qt.begin()->second);
	}
	else
		println(0);
	

	return 0;
}