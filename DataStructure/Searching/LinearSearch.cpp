#include <iostream>
#include <vector>

using namespace std;

void search_linear(vector<int> &data, int key)
{
    //linear search
    bool found = false;
    
    for (const auto &ref : data) {
        if (ref == key) {
            cout << "Key Found :" << ref << endl;
            found = true;
            break;
        }
    }
    
    if(found == false)
    {
        cout << "No Key Found." << endl;
    }
}


int main() {
    
    vector<int> data = {69, 2, 93, 76, 51, 97, 69, 85, 76, 85, 78, 77};
    
    int search_key = 97;
    
    search_linear(data, search_key);
    
    return 0;
}
