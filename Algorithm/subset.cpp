#include <iostream>
#include <vector>
#include <set>

int main(){

  std::vector<int> S = {19, 10, 12, 24, 25, 22};
  int count = 0;
  std::set<int> element;

  for(auto i=0; i < 6; i++){
    for(auto j=i+1; j < 6; j++){
      //cout << S[i] << " " << S[j] << " " << S[i] + S[j] <<"\n";
      //count++;
      if( (S[i] + S[j]) % 4 != 0){
        std::cout << S[i] << " " << S[j] << " " << S[i] + S[j] <<"\n";
        element.insert(S[i]);
        element.insert(S[j]);
        count++;
      }
    }
  }

  std::cout << count << "\n";

  for(auto &key : element){
    std::cout << key << " ";
  }
  std::cout << "\n";
  std::cout << element.size() / 2 << "\n";

  return 0;
}