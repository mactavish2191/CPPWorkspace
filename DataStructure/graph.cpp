#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <iterator>

using namespace std;

//Adjacency list definition
class GraphList {
private:
  int m_V;  //vertices
  int m_E = 0;  //edges
  map<int, vector<pair<int, int>> > Adj; //for storing undirected and digraph

  //DFS Util private function
  void DFS_PathTrack(vector<bool> &visited, int index) {
    //mark the current node as visted and print the node 
    visited[index] = true;
    cout << index << " ";

    //Recur for all the vertices adjacent to the vertex
    for (const auto& i : Adj[index]) {
      if (visited[i.first] == false)
        DFS_PathTrack(visited, i.first);
    }
  }

public:
  GraphList(int V = 0) :m_V(V)
  {
    if (V == 0) {
      cout << "Graph cannot be created. \n";
      exit(0);
    }
  }

  void addEdge(int a, int b) { //undirected edge graph
    if ((a > m_V || b > m_V) || (a < 0 || b < 0)) {
      cout << "The vertex does not exits \nPlease enter new value \n";
    }
    else {
      Adj[a].push_back({ b, 0 });
      Adj[b].push_back({ a, 0 });
      m_E++;
    }
  }

  void addDiEdge(int a, int b, int weight) { //undirected edge graph
    if ((a > m_V || b > m_V) || (a < 0 || b < 0)) {
      cout << "The vertex does not exits \nPlease enter new value \n";
    }
    else {
      Adj[a].push_back({ b, weight });
      m_E++;
    }
  }

  void printUnDiGraph() {
    if (m_V == 0) {
      cout << "No graph vertices are available\n";
    }
    else {
      for (const auto &x : Adj) {
        cout << x.first;
        for (const auto& y : x.second) {
          cout << "->" << y.first;
        }
        cout << "\n";
      }
    }
  }

  void printDiGraph() {
    if (m_V == 0) {
      cout << "No graph vertices are available\n";
    }
    else {
      for (const auto& x : Adj) {
        cout << x.first;
        for (const auto& y : x.second) {
          cout << "-> " << y.first << ":" << y.second;
        }
        cout << "\n";
      }
    }
  }

  void BreadthFirstSearch(){
    vector<bool> visited(m_V + 1, false); //start with index 1
    cout << "BFS Traversal order: ";

    for (int i = 0; i < m_V+1 ; i++) {
      if(Adj.find(i) != Adj.end()){
        if(visited[i] == false){
          queue<int> Q;
          Q.push(i);
          visited[i] = true;

          while(Q.empty() != true){
            int key = Q.front(); Q.pop();
            cout << key << " ";

            for(const auto &node : Adj[key]){
              if(visited[node.first] == false){
                Q.push(node.first);
                visited[node.first] = true;
              }
            }

          }//end while
        }
      }
    }//end for loop for all vertices

    cout << "\n";
  }

  void DepthFirstSearch() {
    vector<bool> visited(m_V + 1, false); //start with index 1
    cout << "DFS Traversal order: ";

    //It enables to travel the whole set of graph even if the nodes are not connected
    for (int i = 0; i < m_V + 1; i++) {
      if(Adj.find(i) != Adj.end()){
        if(visited[i] == false)
          DFS_PathTrack(visited, i);
      }
    }
    cout << "\n";
  }

  void DepthFirstSearch_Loop() {
    vector<bool> visited(m_V + 1, false); //start with index 1
    cout << "DFS Traversal Loop order: ";

    for (int i = 0; i < m_V + 1; i++) {
      if(Adj.find(i) != Adj.end()){
        if(visited[i] == false){
          stack<int> S;
          S.push(i);

          visited[i] = true;

          while (S.empty() != true)
          {
            int key = S.top(); S.pop();
            cout << key << " ";

            vector<pair<int, int>>::reverse_iterator ritr;
            for (ritr = Adj[key].rbegin(); ritr != Adj[key].rend(); ritr++) {
              if (visited[ritr->first] == false) {
                S.push(ritr->first);
                visited[ritr->first] = true;
              }
            }
          }// end while
        }// end for  
      }
    }
    cout << "\n";  
  }

  void UnweightedShortestPath(int start, int end){
   if(start <= 0 && start > m_V){
    cout << "Please check the start vertex\n";
   }
   else if(end <= 0 && end > m_V){
    cout << "Please check the end vertex\n";
   }
   else{
    vector<int> distance(m_V + 1, -1); //starts with index 1
    vector<int> path(m_V + 1, -1); //starts with index 1
    queue<int> Q;
    Q.push(start);
    distance[start] = 0;
    bool flag = false;

    while(Q.empty() != true){
      int idx = Q.front(); Q.pop();
      for(const auto &node : Adj[idx]){
        if(distance[node.first] == -1){
          distance[node.first] = distance[idx] + 1;
          path[node.first] = idx;
          Q.push(node.first);

          if(node.first == end){
            flag = true;
            break;
          }

        }
      }
      if(flag == true)
        break;
    }

    // cout << "Distance :";
    // for(int i = 0; i <= m_V; i++){
    //   cout << distance[i] << " ";
    // }

    // cout << "\nPath :";
    // for(int i = 0; i <= m_V; i++){
    //   cout << path[i] << " ";
    // }

    cout << "\nShortest Path :";
    vector<int> track;
    int i = end;
    while (path[i] != -1){
      track.push_back(i);
      i = path[i];
    }
    track.push_back(i);
    for(int i = track.size()-1 ; i >= 0 ; i--){
      cout << track[i] << " ";
    }
    cout << "\n";
   } 
  }

  void getStat() {
    cout << "Vertices:" << m_V << "\n";
    cout << "Edges:" << m_E << "\n";
  }

};

int main() {
  int vertices = 7;
  vector<pair<int, int>> V = {
    {1, 2},
    {1, 4},
    {2, 4},
    {2, 5},
    {3, 1},
    {3, 6},
    {4, 3},
    {4, 5},
    {4, 6},
    {4, 7},
    {5, 7},
    {7, 6}
  };

  GraphList gl(vertices);
  int weight = 0;
  // finding the unweighted shortest path
  for(const auto &i : V)
    gl.addDiEdge(i.first, i.second, weight);


  gl.printDiGraph();

  gl.UnweightedShortestPath(3, 7);

  return 0;
}