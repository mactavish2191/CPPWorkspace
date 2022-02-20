#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <string>

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define SZ(x) ((int)x.size())

std::string ln = "\n";
using vvChar = std::vector<std::vector<char>>;

struct vertex {
	int x, y, distance;
};

auto PrintMatrix(const vvChar &MAZE) -> void {
	for (const auto &x : MAZE) {
		for (const auto& y : x) {
			std::cout << y << " ";
		}
		std::cout << ln;
	}
}

auto PrintShortestPathMaze(const vvChar& MAZE, const std::string& moves, const int& row, const int& col) -> void {
	int x = row, y = col;
	std::string path = moves.substr(0, moves.length() - 1);
	std::set<std::pair<int, int>> pos;
	for (char move : path) {
		if (move == 'N')
			x -= 1;
		else if (move == 'S')
			x += 1;
		else if (move == 'E')
			y += 1;
		else if (move == 'W')
			y -= 1;
		pos.insert({ x, y });
	}

	for (size_t i=0; i < MAZE.size(); i++) {
		for (size_t j=0; j < MAZE[0].size(); j++) {
			bool skip = false;
			for (auto it = pos.begin(); it != pos.end(); it++) {
				if (it->first == i && it->second == j) {
					std::cout << "+ ";
					skip = true;
				}
			}
			if(!skip)
				std::cout << MAZE[i][j] << " ";
		}
		std::cout << ln;
	}
}

auto findPath(vvChar &MAZE) -> void {
	if(MAZE.empty() || MAZE[0].empty()) {
		std::cout << "Empty MAZE hence exiting.\n";
		return;
	}

	int H = SZ(MAZE);
	int W = SZ(MAZE[0]);
	int start_row, start_col;
	//Find the start indexes of the MAZE
	bool flag = false;
	for (auto i = 0; i < H; i++) {
		for (auto j = 0; j < W; j++) { 
			if(MAZE[i][j] == 'S') {
				start_row = i; 
				start_col = j;
				flag = true;
				break;
			}
		}
		if (flag == true){
			break;
		}
	}

	auto inside = [&] (int row, int col) {
		return  0 <= row && row < H && 0 <= col && col < W ; 
	};

	std::vector<std::vector<bool>> visited(H, std::vector<bool>(W, false));

	std::vector<std::pair<int, int>> directions = { {1,0}, {0,1}, {-1,0}, {0,-1} };

	for (auto i = 0; i < H; i++) {
		for (auto j = 0; j < W; j++) {
			if(!visited[i][j] && ( MAZE[i][j] == ' ' || MAZE[i][j] == 'E')) {
				std::queue<vertex> q;
				q.push({ start_row, start_col, 0 });
				visited[start_row][start_col] = true;

				//run the BFS algorithm
				while (!q.empty()) {
					auto v = q.front(); q.pop();
					int dist = v.distance;

					for (auto &dr : directions) {
						int new_row = v.x + dr.first;
						int new_col = v.y + dr.second;

						if (inside(new_row, new_col) && !visited[new_col][new_col] && ( MAZE[new_row][new_col] == ' ' || MAZE[new_row][new_col] == 'E')) {
							q.push({ new_row, new_col, dist + 1 });
							visited[new_row][new_col] = true;
						}
					}
				}
			} // end if
		}
	}

}


auto main() -> int {
/* 	//read file input
	std::ifstream icin("input.txt", std::ios::in);
	if (icin.good() == false) {
		std::cout << "Cannot open file.\n";
		exit(EXIT_FAILURE);
	}

	//R # of rows and C # of columns of the grid
	int R, C;
	icin >> R >> C;
	icin.ignore(); */

	//store the input matrix
	vvChar MAZE = {
		{'S', ' ', ' ', '#', ' ', ' ', ' '},
		{' ', '#', ' ', ' ', ' ', '#', ' '},
		{' ', '#', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', '#', '#', ' ', ' ', ' '},
		{'#', ' ', '#', 'E', ' ', '#', ' '}
	};

	PrintMatrix(MAZE);

	findPath(MAZE);	

	return 0;
}