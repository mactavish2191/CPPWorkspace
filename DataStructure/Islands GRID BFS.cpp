#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
string ln = "\n";

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define SZ(x) ((int)x.size())

/* Solution for no.of Islands problem using BFS 
 * with directional vector in a 2D Matrix for competitive challenges 
 *  */
int numIslands( vector<vector<char>> &grid ) {
  //check if the grid is empty
  if (grid.empty() ||grid[0].empty()) {
    return 0;
  }
  
  //BFS approach
  int H = SZ(grid);
  int W = SZ(grid[0]);
  int answer = 0;
  auto inside = [&](int row, int col) { 
    return 0 <= row && row < H && 0 <= col && col < W;
  };

  vpii directions { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
  
  vector<vector<bool>> visited(H, vector<bool>(W, false));

  for(auto row = 0; row < H; row++) {
    for (auto col = 0; col < W; col++) {
      if(!visited[row][col] && grid[row][col] == '1') {
        answer++;
        queue<pii> q;
        q.push({row, col});
        visited[row][col] = true;

        while(!q.empty()) {
          pii p = q.front();
          q.pop();

          for (pii dir : directions) {
            int new_row = p.first + dir.first;
            int new_col = p.second + dir.second;
            if(inside(new_row, new_col) && !visited[new_row][new_col] && grid[new_row][new_col] == '1') {
              q.push({new_row, new_col});
              visited[new_row][new_col] = true;
            }
          }

        }
        
      }
    }
  }

  return answer;
}



auto main() -> int 
{
  //feed input 1
  vector<vector<char>> mat1 = {
    {'1','1','1','1','0'},
    {'1','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}
  };

  vector<vector<char>> mat2 = {
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','0','1','0'},
    {'0','0','0','1','1'}
  };

  cout << "No.of islands :" <<numIslands(mat1) << ln;
  cout << "No.of islands :" <<numIslands(mat2) << ln;

  return 0;
}