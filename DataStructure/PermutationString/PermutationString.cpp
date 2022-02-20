#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Enumerate(vector<char> &A, int N, int K)
{
    if(K == 0)
    {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i];
        }
        cout <<"\n";
        return;
    }
    
    for (int i = N-1; i >= 0; i--) {
        swap(A[i], A[N-1]);
        Enumerate(A, N-1, K-1);
        swap(A[i], A[N-1]);
    }
}

void Permute(vector<char> &A, int K)
{
    Enumerate(A, static_cast<int>(A.size()), K);
}

int main()
{
    std::vector<char> val{'A', 'B', 'C', 'D'};
    Permute(val, 2);
    
    return 0;
}

