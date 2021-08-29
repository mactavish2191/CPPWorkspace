#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <map>

using namespace std;
//using String = char *;

std::string Path;
std::string PathGood;
vector<int> PathInt;
vector<int> PathBueno;
std::map < int, vector<int>> lista; 

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
    out << "[";
    size_t last = v.size() - 1;
    for(size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i != last) 
            out << ", ";
    }
    out << "]";
    return out;
}

/*std::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( std::pair<char,int>('a',100) );
  mymap.insert ( std::pair<char,int>('z',200) );

  ret = mymap.insert ( std::pair<char,int>('z',500) );
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }
 */
void display(char maze[][10]) {
    for(int i = 0; i < 10; i++) {
        copy(maze[i], maze[i] + 10, ostream_iterator<char>(cout, ""));
        cout << endl;
    }
}


int pathExists(char maze[][10], int sr, int sc, int er, int ec, int distance, int direction) {

    /*if(maze[sr][sc] != '.') . es visitable, x pared
        return 0;
 */
 int lmin=99, l;
    if(maze[sr][sc] != '.') //You cannot visit it, or is wall or is @ visited
        return 0;

    if(sr == er  &&  sc == ec) {
        display(maze); 
        cout << "Distance to end point is:  " << distance << endl;
        cout << "Ultima direccion ess:  " << direction << endl; 
        //if ( lmin==l) PathBueno = PathInt;
        PathInt.push_back(direction);
        lista.insert ( std::pair<int,vector<int>>(distance,PathInt));
        PathInt.pop_back();
        return distance;
    }
    /*
    if(distance == 15) {
        cout << "Cant make it in 15 steps" << endl;
        return 0;
    }
    */
   // path.push_back(vertex);
    //Path.append(direction);
    PathInt.push_back(direction);
    maze[sr][sc] = '@';  // anything non-'.' will do



    //Row --  Norte
    l = pathExists(maze, sr - 1, sc, er, ec, distance + 1,1);
    if(l > 0 && l<lmin) {
        lmin = l; 
       // Path.append("N");
    }
    //Row ++  Sur
    l = pathExists(maze, sr + 1, sc, er, ec, distance + 1,2);
    if(l > 0 && l<lmin) {
        lmin = l; 
        //Path.append("S");
    }

    //Column --  Oeste
    l = pathExists(maze, sr, sc - 1, er, ec, distance + 1,3);
    if(l > 0 && l<lmin) 
        {
        lmin = l; 
        //Path.append("W");
    }

    //Column ++  Este
    l = pathExists(maze, sr, sc + 1, er, ec, distance + 1,4);
    if(l > 0 && l<lmin) 
    {
        lmin = l; 
        //Path.append("E");
    }

    maze[sr][sc] = '.'; //restore
    PathInt.pop_back();
    //if ( Path.size() > 2) Path.erase(Path.size() - 1);

    return lmin;
}



int main() {
    char maze[10][10] = {
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
        {'X', '.', '.', '.', '.', '.', '.', '.', '.', 'X'},
        {'X', '.', 'X', 'X', 'X', 'X', '.', 'X', 'X', 'X'},
        {'X', '.', '.', 'X', '.', 'X', '.', '.', '.', 'X'},
        {'X', '.', '.', 'X', '.', '.', '.', 'X', '.', 'X'},
        {'X', '.', 'X', 'X', '.', 'X', 'X', 'X', '.', 'X'},
        {'X', '.', 'X', '.', '.', '.', '.', 'X', 'X', 'X'},
        {'X', '.', '.', 'X', 'X', '.', 'X', 'X', '.', 'X'},
        {'X', '.', '.', '.', '.', '.', '.', '.', '.', 'X'},
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}
    };

    Path.clear();

    int  slen = pathExists(maze,5,4, 3, 1,0,0); 




    if(slen) {
        cout << "Solvable in "<<slen<<" steps !" << endl;
    //  cout << "Complete path is : " << Path;
    //    std::cout << "Complete path is : " << PathGood;
    }
    else
        cout << "Out of luck!" << endl;
    cin.get();

    // showing contents:
  std::map<int,std::vector<int>>::iterator it = lista.begin();
  std::cout << "Mi lista contains:\n";
  for (it=lista.begin(); it!=lista.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  int direccionb = lista.find(slen)->second[1];

  cout << "La direccion buena de la buena es :" << direccionb << endl;

}