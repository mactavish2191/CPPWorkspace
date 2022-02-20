#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    cin.ignore();

    string buffer;
    getline(cin, buffer);
    //cout << buffer << endl;
    stringstream ss;
    ss << buffer;
    
    int temp(0);
    vector<int> data,newData,diff;
    
    while (ss >> temp) {
        data.push_back(temp);
        newData.push_back(temp);
    }
    
    sort(newData.begin(), newData.end());
    
    auto last = unique(newData.begin(), newData.end());
    newData.erase(last, newData.end());

    
    for (int i = 0; i < newData.size(); i++) {
        diff.push_back(abs(newData[i] - data[i]));
    }
    
    int ops = accumulate(diff.begin(), diff.end(), 0);
    
    cout << ops << "\n";
    
    return 0;
}
