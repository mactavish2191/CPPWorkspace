#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;


int main()
{
    int T{0};
    freopen("input.txt","r", stdin);
    cin >> T;
    cin.ignore();
    int test_case = 1;
    while(T--){
        int N{0};
        cin >> N;
        cin.ignore();
        vector<unsigned int> list;
        list.reserve(N);
        for (int i=0; i<N; i++) {
            cin >> list[i];
        }
        cin.ignore();
        //----------------
        bool done = false;
        while(!done){
            done = true;
            for (int i=0; i<(N-2) ; i++){
                if(list[i] >= list[i+2]){
                    swap(list[i], list[i+2]);
                    done = false;
                }
            }
        }

        for (int i=0; i<N ; i++) {
            cout << list[i] << " ";
        }
        cout << "\n";
        
        bool rule = true;
        int index{0};
        for (int i=0; i<N-1 ; i++) {
            if(list[i] > list[i+1]){
                index = i;
                rule = false;
                break;
            }
        }

        if(rule == true){
            cout << "Case #" << test_case << ": OK\n";
        }
        else{
            cout << "Case #" << test_case <<": " << index << "\n";
        }
        
        test_case++;
    }
    
    return 0;
}
