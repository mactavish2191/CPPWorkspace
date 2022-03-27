#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <iterator>
#include <stack>
#include <limits>
#include <algorithm>
#include <set>

using namespace std;
constexpr int INF = 1E9 + 7;
const string ln = "\n";
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

class FloydWarshall
{ //Using Adjacency Matrix
private:
	int m_V = 0;			   // Vertices
	int m_E = 0;			   // Edges
	vector<vector<int>> Graph; // 2D matrix to hold the edges and vertices of a Graph

public:
	FloydWarshall(int V = 0) : m_V(V) {
		Graph.resize(m_V, vector<int>(m_V));

		//Initialize with INF for all the Edge weights
		for (int i = 0; i < m_V; ++i) {
			for (int j = 0; j < m_V; ++j) {
				Graph[i][j] = INF;
				if (i == j)
					Graph[i][j] = 0;
			}
		}
	}

	void PrintMatrix() {
		cout << "Initial Matrix:\n";
		for (int i = 0; i < m_V; ++i)
		{
			for (int j = 0; j < m_V; ++j)
			{
				cout << Graph[i][j] << ((Graph[i][j] == INF) ? "\t" : " \t\t");
			}
			cout << ln;
		}
		cout << ln;
	}

	void AddDiEdge(int a, int b, int weight = 0) { //directed edge graph with optional weight
		if ((a > m_V || b > m_V) || (a < 0 || b < 0))
		{
			cout << "The vertex does not exits \nPlease enter new value \n";
		}
		else
		{ // Starting with Index 1 as Graph Vertex counting
			Graph[a - 1][b - 1] = weight;
			m_E++;
		}
	}

	void FloydWarshallSolver() {
		vector<vector<int>> dpGraph(m_V, vector<int>(m_V));

		//Initilaize the Solver matrix
		for (int i = 0; i < m_V; ++i)
			for (int j = 0; j < m_V; ++j)
				dpGraph[i][j] = Graph[i][j];

		for (int k = 0; k < m_V; ++k)
			for (int i = 0; i < m_V; ++i)
				for (int j = 0; j < m_V; ++j)
					dpGraph[i][j] = min(dpGraph[i][j], dpGraph[i][k] + dpGraph[k][j]);

		//Check for negative cycles by spreading the value -INF
		for (int k = 0; k < m_V; ++k)
			for (int i = 0; i < m_V; ++i)
				for (int j = 0; j < m_V; ++j)
					if ((dpGraph[i][k] + dpGraph[k][j]) < dpGraph[i][j]) {
						dpGraph[i][j] = -INF;
					}

		//Print value of DP Matrix
		cout << "Solved Matrix Final Path:\n";
		for (int i = 0; i < m_V; ++i) {
			for (int j = 0; j < m_V; ++j) {
				cout << dpGraph[i][j] << ((dpGraph[i][j] == INF) ? "\t" : " \t\t");
			}
			cout << ln;
		}
		cout << ln;

	} //end FloydWarshallSolver
};

class GraphList { // Using Adjacency List
private:
	int m_V;		  //vertices
	int m_E = 0;	  //edges
	bool DAG = false; // to check if the graph is a Directed Graph

	//0 index means null pointer in Graph structure pointing to nothing. N -> null
	map<int, vector<pair<int, int>>> Adj; //for storing undirected and digraph
	vector<int> indegree;				  // for storing indegree data

	//DFS Utility private function
	void DFS_PathTrack(vector<bool> &visited, int index) {

		visited[index] = true;
		if (index != 0)
			cout << index << " ";

		//Scan for all the vertices adjacent to the vertex
		for (const auto &i : Adj[index])
		{
			if (visited[i.first] == false)
				DFS_PathTrack(visited, i.first);
		}
	}

	void PrintShortestPath(const vector<int> &path, int end) {
		cout << "Shortest Path :";
		vector<int> track;
		int i = end;

		//backtrack from the end to start of the path array
		while (path[i] != INF) {
			track.push_back(i);
			i = path[i];
		}
		track.push_back(i); //trailing node

		for (int i = (int)track.size() - 1; i >= 0; i--) {
			cout << track[i] << " ";
		}
		cout << ln;
	}

public:
	GraphList(int V = 0) : m_V(V) {
		if (V == 0)
		{
			cout << "Graph cannot be created. \n";
			exit(0);
		}
		indegree.assign(V + 1, 0);
	}

	inline void GetStat() {
		cout << "Vertices:" << m_V << "\n";
		cout << "Edges:" << m_E << "\n";
	}

	void AddEdge(int a, int b, int weight = 0) { //undirected edge graph with optional weight
		if ((a > m_V || b > m_V) || (a < 0 || b < 0))
		{
			cout << "The vertex does not exits \nPlease enter new value \n";
		}
		else if (a == 0)
		{
			Adj[b].push_back({0, 0});
			m_E++;
		}
		else if (b == 0)
		{
			Adj[a].push_back({0, 0});
			m_E++;
		}
		else
		{
			Adj[a].push_back({b, weight});
			Adj[b].push_back({a, weight});
			m_E++;
		}
	}

	void AddDiEdge(int a, int b, int weight = 0) { //directed edge graph with optional weight
		if ((a > m_V || b > m_V) || (a < 0 || b < 0)) {
			cout << "The vertex does not exits \nPlease enter new value \n";
		}
		else if (a == 0) {
			Adj[b].push_back({0, 0});
			m_E++;
			DAG = true;
		}
		else if (b == 0) {
			Adj[a].push_back({0, 0});
			m_E++;
			DAG = true;
		} 
		else{
			Adj[a].push_back({b, weight});
			m_E++;
			indegree[b]++;
			DAG = true;
		}
	}

	void PrintUnDiGraph() {
		if (m_V == 0) {
			cout << "No graph vertices are available\n";
		}
		else {
			for (const auto &x : Adj) {
				cout << x.first;
				for (const auto &y : x.second) {
					cout << " -> " << y.first << "{" << y.second << "}";
				}
				cout << "\n";
			}
		}
	}

	void PrintDiGraph() {
		if (m_V == 0) {
			cout << "No graph vertices are available\n";
		}
		else {
			for (const auto &x : Adj) {
				cout << x.first;
				for (const auto &y : x.second) {
					cout << " -> " << y.first << "{" << y.second << "}";
				}
				cout << "\n";
			}
		}
	}

	void BreadthFirstSearch() {
		vector<bool> visited(m_V + 1, false); //start with index 1
		cout << "BFS Traversal order: ";

		for (int i = 1; i < m_V + 1; i++) {
			if (Adj.find(i) != Adj.end()) {
				if (visited[i] == false) {
					queue<int> Q;
					Q.push(i);
					visited[i] = true;

					while (Q.empty() != true) {
						int key = Q.front();
						Q.pop();
						cout << key << " ";

						for (const auto &node : Adj[key]) {
							if (visited[node.first] == false) {
								Q.push(node.first);
								visited[node.first] = true;
							}
						}

					} //end while
				}
			}
		} //end for loop for all vertices

		cout << "\n";
	}

	void DepthFirstSearch() {
		vector<bool> visited(m_V + 1, false); //start with index 1
		cout << "DFS Traversal order: ";

		for (int i = 1; i < m_V + 1; i++) {
			if (visited[i] == false)
				DFS_PathTrack(visited, i);
		}
		cout << ln;
	}

	void DepthFirstSearch_Loop() {
		vector<bool> visited(m_V + 1, false); //start with index 1
		cout << "DFS Traversal Loop order: ";

		for (int i = 1; i < m_V + 1; i++) {
			if (visited[i] == false) {
				stack<int> S;
				S.push(i);

				visited[i] = true;

				while (S.empty() != true) {
					int key = S.top();
					S.pop();
					cout << key << " ";

					vector<pii>::reverse_iterator ritr;
					for (ritr = Adj[key].rbegin(); ritr != Adj[key].rend(); ritr++) {
						if (visited[ritr->first] == false) {
							S.push(ritr->first);
							visited[ritr->first] = true;
						}
					}
				} // end while
			}	  // end if
		}		  //end for
		cout << "\n";
	}

	void TopSort() {
		if (DAG == true) {
			queue<int> q;
			int counter = 0;

			//copy all the vertex with indegree 0 into the queue
			for (int i = 1; i < (int)indegree.size(); i++) {
				if (indegree[i] == 0) {
					q.push(i);
				}
			}

			cout << "Top Sort Ordering: ";
			while (q.empty() != true) {
				int v = q.front();
				q.pop();
				cout << v << " ";
				counter++;

				for (auto &val : Adj[v]) {
					if (--indegree[val.first] == 0) {
						q.push(val.first);
					}
				}
			}
			cout << "\n";

			if (counter != m_V) {
				cout << "Cycle Found in Graph!.\n";
			}
		}
		else
			cout << "Cannot perform a Topological Sort on a Undirected Graph\n";
	}

	int FindComponents() {										  //count the no.of connected componenets
		vector<bool> visited(m_V + 1, false); //start with index 1
		int count = 0;

		for (int i = 1; i < m_V + 1; i++) {
			if (Adj.find(i) != Adj.end()) {
				if (visited[i] == false) {
					count++;
					DFS_PathTrack(visited, i);
				}
			}
		}
		cout << "\n";
		cout << "Connected components: ";
		return count;
	}

	void UnweightedShortestPath(int start, int end) {
		if (start <= 0 && start > m_V) {
			cout << "Please check the start vertex\n";
			return;
		}
		if (end <= 0 && end > m_V) {
			cout << "Please check the end vertex\n";
			return;
		}

		// Main Logic
		cout << "Running Unweighted Shortest Path Algorithm......\n";
		vector<int> distance(m_V + 1, INF); //starts with index 1
		vector<int> path(m_V + 1, INF);		//starts with index 1
		queue<int> Q;
		Q.push(start);
		distance[start] = 0;
		bool flag = false;

		while (Q.empty() != true) {
			int idx = Q.front();
			Q.pop();
			for (const auto &node : Adj[idx]) { //check the surrounding nodes
				if (distance[node.first] == INF) { //if the node is not visited then visit and update the distance
					distance[node.first] = distance[idx] + 1;
					path[node.first] = idx;
					Q.push(node.first);

					if (node.first == end) {
						flag = true;
						break;
					}
				}
			}
			if (flag == true)
				break;
		}

		cout << "Minimum Distance :" << distance[end] << "\n";

		PrintShortestPath(path, end);
		
	}

	void LazyDijkstra(int start, int end) { //Standard Dijkstra Algorithm with PQ
		if (start <= 0 && start > m_V) {
			cout << "Please check the start vertex\n";
			return;
		}
		if (end <= 0 && end > m_V) {
			cout << "Please check the end vertex\n";
			return;
		}

		// Main Logic
		cout << "Running Lazy Dijsktra Shortest Path Algorithm...\n";
		vector<bool> visisted(m_V + 1, false);
		vector<int> distance(m_V + 1, INF); //starts with index 1
		vector<int> path(m_V + 1, INF);		//starts with index 1

		distance[start] = 0;

		priority_queue<pii, vector<pii>, greater<pii>> pq; //minimim priority queue

		pq.push({distance[start], start}); // Entry[distance, vertex]

		while (pq.empty() != true) {
			auto node = pq.top();
			pq.pop();
			visisted[node.second] = true;

			if(distance[node.second] < node.first)
				continue;

			for (const auto &w : Adj[node.second]) { // Scan all the neighbour vertices
				if(visisted[w.first] == true)
					continue;

				int new_dist = distance[node.second] + w.second;

				if (distance[w.first] > new_dist) {
					distance[w.first] = new_dist;
					pq.push({new_dist, w.first});
					path[w.first] = node.second;
				}
			}
		}
		
		cout << "Minimum Distance :" << distance[end] << "\n";

		PrintShortestPath(path, end);
	}

	void EagerDijkstra(int start, int end) { //Optimzed Dijkstra Algorithm with Multiset
		if (start <= 0 && start > m_V) {
			cout << "Please check the start vertex\n";
			return;
		}
		if (end <= 0 && end > m_V) {
			cout << "Please check the end vertex\n";
			return;
		}

		// Main Logic
		cout << "Running Eager Dijsktra Shortest Path Algorithm......\n";
		vector<int> distance(m_V + 1, INF); //starts with index 1
		vector<int> path(m_V + 1, INF);		//starts with index 1

		distance[start] = 0;

		multiset<pii> ms; //multiset data structure

		ms.insert({distance[start], start}); // Entry[distance, vertex]
		int counter = 0, depthcnt = 0;
		while (!ms.empty()) {
			auto node = *ms.begin();
			ms.erase(ms.begin());
			counter++;
			for (const auto &w : Adj[node.second]) { // Scan all the neighbour vertices
				int new_dist = distance[node.second] + w.second;
				depthcnt++;
				if (distance[w.first] == INF) {
					distance[w.first] = new_dist;
					ms.insert({new_dist, w.first});
					path[w.first] = node.second;
				}

				if (distance[w.first] > new_dist) {
					distance[w.first] = new_dist;
					for (auto &it : ms) {
						if (it.second == w.first) {
							ms.erase(it);
							break;
						}
					}

					ms.insert({new_dist, w.first});
					path[w.first] = node.second;
				}
			}
		}
		cout << "Counter :" << counter << " Depth Count :" << depthcnt << ln;
		//for (int i = 1; i <= m_V; i++) {
		//	cout << distance[i] << " ";
		//}
		//cout << ln;
		cout << "Minimum Distance :" << distance[end] << "\n";

		PrintShortestPath(path, end);

	}

	void BellmanFordShortestPath(int start, int end) { //Weighted shortest path with negative edges //avg:On2 worst:On3
		if (start <= 0 && start > m_V) {
			cout << "Please check the start vertex\n";
			return;
		}
		if (end <= 0 && end > m_V) {
			cout << "Please check the end vertex\n";
			return;
		}

		// Main Logic
		//INF 1E9 + 7 1000'000'007
		cout << "Running Bellman Ford Shortest Path Algorithm......\n";
		vector<int> distance(m_V + 1, INF); //starts with index 1
		vector<int> path(m_V + 1, INF);		//starts with index 1

		distance[start] = 0;

		//Relaxation code to get rid of negative edge values
		for (int cnt = 0; cnt < m_V - 1; cnt++) { // |V| - 1
			for (int node = 1; node <= m_V; node++) { // scan all the vertices
				for (const auto &v : Adj[node]) {
					if (distance[node] + v.second < distance[v.first]) {
						distance[v.first] = distance[node] + v.second;
						path[v.first] = node;
					}
				}
			}
		}

		//Check for the negative weight cycle
		for (int node = 1; node <= m_V; node++) { // scan all the vertices
			for (const auto &v : Adj[node]) {
				if (distance[node] + v.second < distance[v.first]) {
					distance[v.first] = -INF;
				}
			}
		}
		//Printing the final distance values
		cout << "Distance Values : ";
		for (auto i = 1; i <= m_V; i++) {
			cout << distance[i] << " ";
		}
		cout << ln;

		cout << "Minimum Distance :" << distance[end] << "\n";

		PrintShortestPath(path, end);

	}

	void PrimsMST(int start) {
		if (start <= 0 && start > m_V) {
			cout << "Please check the start vertex\n";
			return;
		}

		cout << "Running Prims Minimum Spanning Tree Algorithm......\n";
		vector<int> distance(m_V + 1, INF); //starts with index 1
		vector<int> path(m_V + 1, INF);		//starts with index 1

		distance[start] = 0;

		multiset<pii> ms;

		ms.insert({distance[start], start}); //Entry [distance, vertex] sort by distance

		while (ms.empty() != true) {

			auto node = *ms.begin();
			ms.erase(ms.begin());

			cout << node.second << " " << node.first << ln;

			for (const auto &w : Adj[node.second]) { // get all the neighbour vertices

				if (distance[w.first] == INF) {
					distance[w.first] = w.second;
					ms.insert({w.second, w.first});
					path[w.first] = node.second;
				}

				if (distance[w.first] > w.second) {
					distance[w.first] = w.second;
					for (auto &it : ms) {
						if (it.second == w.first) {
							ms.erase(it);
							break;
						}
					}
					ms.insert({w.second, w.first});
					path[w.first] = node.second;
				}
			}
		}

		// for (auto &i : path)
		// {
		// 	cout << i << " ";
		// }
		// cout << ln;

		cout << "New MST Tree with Adjacency List Representation: " << ln;
		//New Graph for MST
		GraphList newG(m_V);
		int totalCost = 0;
		//Create a Tree Graph with new values
		for (auto i = 1; i <= m_V; i++) {
			if (path[i] == INF)
				continue;
			else {
				if (path[i] > i) {
					newG.AddEdge(i, path[i], distance[i]);
					totalCost += distance[i];
				}
				else {
					newG.AddEdge(path[i], i, distance[i]);
					totalCost += distance[i];
				}
			}
		}

		newG.PrintUnDiGraph();
		cout << "TotalCost : " << totalCost << ln;
		
	}
};

int main()
{
	//cout << std::boolalpha;

	//edge list graph with no weight values
	vector<pii> V0 = {
		{1, 2},
		{1, 4},
		{2, 4},
		{2, 5},
		{3, 1},
		{3, 6},
		{4, 6},
		{4, 7},
		{5, 7},
		{6, 0},
		{7, 6}
	};

	//Using directed acyclic graph DAG no weight
	vector<pii> V1 = {
		{1, 2},
		{1, 4},
		{1, 3},
		{2, 5},
		{2, 4},
		{3, 6},
		{4, 3},
		{4, 6},
		{4, 7},
		{5, 4},
		{5, 7},
		{7, 6}
	};

	//GraphList connComponent(vertices) with no weight
	vector<pii> V2 = {
		{1, 2},
		{1, 3},
		{2, 3},
		{4, 0},
		{5, 6},
		{5, 9},
		{6, 7},
		{6, 8},
		{6, 9},
		{7, 8},
		{9, 8},
		{10, 11},
		{11, 12},
		{11, 13},
		{14, 15},
		{15, 16},
		{15, 17},
		{16, 17},
		{17, 18}
	};

	//directed weighted graph Lazy Dijkstra Algorithm
	vector<tiii> V3 = {
		{1, 2, 4},
		{1, 3, 1},
		{2, 4, 1},
		{3, 2, 2},
		{3, 4, 5},
		{4, 5, 3},
		{5, 0, 0}
	};

	//directed weightd graph
	vector<tiii> V4 = {
		{1, 2, 10},
		{1, 3, 15},
		{2, 4, 12},
		{2, 6, 15},
		{3, 5, 10},
		{4, 5, 2},
		{4, 6, 1}
	};

	//directed weighted graph with negative edges
	vector<tiii> V5 = {
		{1, 2, 6},
		{1, 3, 5},
		{1, 4, 5},
		{2, 5, -1},
		{3, 2, -2},
		{3, 5, 1},
		{4, 3, -2},
		{4, 6, -1},
		{5, 7, 3},
		{6, 7, 3},
		{7, 0, 0}
	};

	//undirected weighted graph for MST
	vector<tiii> V6 = {
		{1, 2, 28},
		{1, 6, 10},
		{2, 3, 16},
		{2, 7, 14},
		{3, 4, 12},
		{4, 5, 22},
		{4, 7, 18},
		{5, 6, 25},
		{5, 7, 24}
	};

	//Eager Dijkstra directed weighted graph
	vector<tiii> V7 = {// 6 vertices
		{1, 2, 5},
		{1, 3, 1},
		{2, 3, 2},
		{2, 4, 3},
		{2, 5, 20},
		{3, 2, 3},
		{3, 5, 12},
		{4, 3, 3},
		{4, 5, 2},
		{4, 6, 6},
		{5, 6, 1},
		{6, 0, 0}
	};

	//Undirected weighted graph William Fiset Example
	vector<tiii> V8 = {
		{1, 2, 10},
		{1, 3, 1},
		{1, 4, 4},
		{2, 3, 3},
		{2, 5, 0},
		{3, 4, 2},
		{3, 6, 8},
		{4, 6, 2},
		{4, 7, 7},
		{5, 6, 1},
		{5, 8, 8},
		{6, 7, 6},
		{6, 8, 9},
		{7, 8, 12}
	};

	//Undirected weighted graph AB Example
	vector<tiii> V10 = {
		{1, 2, 28},
		{1, 6, 10},
		{2, 3, 16},
		{2, 7, 14},
		{3, 4, 12},
		{4, 5, 22},
		{4, 7, 18},
		{5, 6, 25},
		{5, 7, 24}
	};

	//Directed weighted graph for FW algorithm
	vector<tiii> V9 = {
		{1, 2, 3},
		{1, 4, 7},
		{2, 1, 8},
		{2, 3, 2},
		{3, 1, 5},
		{3, 4, 1},
		{4, 1, 2}
	};

	//Working with Unweighted Shortest Path
	//GraphList G(7);
	//for (const auto& i : V0) {
	//	G.AddDiEdge(i.first, i.second);
	//}
	//G.PrintDiGraph();
	//G.UnweightedShortestPath(3, 7);

	GraphList G(5);
	for (const auto& i : V3) {
		auto &[from, to, weight] = i;
		G.AddDiEdge(from, to, weight);
	}
	G.PrintDiGraph();
	G.LazyDijkstra(1, 5);

	// FloydWarshall G(4);
	// for (const auto& i : V9) {
	// 	auto &[from, to, weight] = i;
	// 	G.AddDiEdge(from, to, weight);
	// }
	// G.PrintMatrix();
	// G.FloydWarshallSolver();

	// GraphList G(7);
	// for (const auto &i : V10) {
	// 	auto &[from, to, weight] = i;
	// 	G.AddEdge(from, to, weight);
	// }
	// G.PrintUnDiGraph();
	// G.PrimsMST(1);

	return 0;
}