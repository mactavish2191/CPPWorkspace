#include <iostream>
#include <set>
#define ln "\n"
using namespace std;


class UnionFind {
private:
	set<int> S;

public:
	UnionFind(int X) {
		MakeSet(X);
	}
	UnionFind(UnionFind &X) {
		Union(X);
	}

	decltype(S) getSetElements() {
		return S;
	}

	void MakeSet(int X) {
		S.insert(X);
	}

	int Find(int X) {
		if (S.contains(X)) {
			if (S.empty()) {
				cout << "Empty Set" << ln;
				return -1;
			}
			else
				return *(S.begin());
		}
		else {
			return -1;
		}
	}

	void Union(int X) {
		int p = Find(X);

		if (p == -1) {
			MakeSet(X);
		}
		else {
			cout << "Element already belongs to the group" << ln;
			return;
		}

	}

	void Union(UnionFind &X) {
		S.merge(X.getSetElements());
	}

	size_t getSize() {
		return S.size();
	}

	void printSet() {
		if (!S.empty()) {
			for (auto &k : S) {
				cout << k << " ";
			}
			cout << ln;
		}
	}

};

int main() {
	UnionFind K(2);
	K.MakeSet(3);
	K.MakeSet(4);
	K.MakeSet(5);
	K.MakeSet(6);

	K.Union(11);

	K.printSet();


	UnionFind M(5);
	M.MakeSet(6);
	M.MakeSet(7);
	M.MakeSet(8);
	M.MakeSet(9);

	M.printSet();

	K.Union(M);
	K.printSet();

	int j = 100;
	int *k = &j;
	cout << "Size of int * :" << sizeof(k) << ln;
	cout << "Size of ULL :" << sizeof(unsigned long long) << ln;
	return 0;
}