#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int var = 100;

    cout << var << "\n";
    vector<int> list = { 12, 35, 58, 8, 75, 2, 21, 82, 
                         78, 95, 80, 33, 80, 53, 60, 22, 
                         48, 68, 81, 65, 65, 59, 39, 81, 
                         65, 35, 34, 78, 33, 52, 70, 33, 
                         90, 57, 58, 18, 99, 65, 96, 77, 
                         63, 29, 11, 79, 48, 74, 83, 19, 
                         14, 42, 21, 45, 94, 16, 72, 39, 
                         57, 78, 22, 42, 25, 50, 65, 22, 
                         21, 21, 21, 30, 100, 93, 83, 85, 
                         35, 34, 57, 69, 78, 2, 74, 53, 92, 
                         79, 8, 67, 46, 26, 70, 52, 8, 21, 
                         60, 74, 51, 64, 26, 60, 15, 20, 98, 82 };
    
    set<int> setInt;
    for (auto &&i : list) {
        setInt.insert(i);
    }

    for (auto &&i : setInt) {
        cout << i << " ";
    }
    cout << "\n";
    auto it = setInt.begin();
    cout << "Second smallest element :" << *(++it) << "\n";

    return 0;
}