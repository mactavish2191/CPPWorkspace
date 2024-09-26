#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
   vector<int> product = {217, 1891, 4819, 2291, 2987, 3811, 1739, 2491, 4717, 445, 65, 1079, 8383, 5353, 901, 187, 649, 1003, 697, 3239, 7663, 291, 123, 779, 1007, 3551, 1943, 2117, 1679, 989, 3053};
   vector<int> primes = {2, 3,5, 7, 11,13,17, 19, 23, 29, 31,	37,	41,	43,	47,	53,	59,	61,	67,	71, 73,	79,	83,	89,	97,	101, 103};
   map<int, int> val;
    
        
   for(int &prime : primes){
       for(auto &p : product){
           if(p % prime == 0){
               val[p / prime]++;
           }
       }
   }
   
   for(auto it : val){
       cout << it.first << " "<< it.second << "\n";
   }
   
   return 0;
}

