#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<int> climbingLeaderboard(vector<int>& scores, vector<int>& alice) {
  vector<int> rank;
  vector<int> result;
  rank.push_back(1);
  for(int i=1; i < scores.size(); i++){
    if(scores[i-1] == scores[i]){
        rank.push_back(rank[i-1]);
    }
    else{
        int tmp = rank[i-1];
        rank.push_back(++tmp);
    }
  }

  for(int i=0; i<alice.size(); i++){
    for(int j=scores.size()-1; j >= 0; j--){
      if(alice[i] <= scores[j]){
        if(alice[i] == scores[j]){
          result.push_back(rank[j]);
          //cout << rank[j] << "\n";
        }
        else{
          result.push_back(rank[j] + 1);
          //cout << rank[j] + 1 << "\n";
        }
        break;
      }
      else if(i == alice.size() - 1 || j == 0){
        if(alice[i] > scores[j]){
          result.push_back(rank[0]);
          //cout << rank[j] << "\n";
          break;
        }
      }
    }
  }


  return result;
}

int main()
{
    vector<int> scores;
    vector<int> alice;

    int n=0;
    cin >> n;
    cin.ignore();

    string line1;
    getline(cin, line1);
    stringstream ss1;
    ss1 << line1;
    int tmp = 0;
    while(ss1 >> tmp) {
      scores.push_back(tmp);
    }
    int m=0;
    cin >> m;
    cin.ignore();

    tmp =0;
    string line2;
    getline(cin, line2);
    stringstream ss2;
    ss2 << line2;
    while(ss2 >> tmp) {
      alice.push_back(tmp);
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";



  return 0;
}
