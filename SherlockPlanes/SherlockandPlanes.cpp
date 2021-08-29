#include <iostream>
#include <string>
#include <sstream> 
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <cassert>
using namespace std;

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define SZ(x) ((int)(x.size()))

#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))

#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)

#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define DBG cerr << "debug here" << "\n";
#define DBGV(vari) cerr << #vari<< " = "<< (vari) << "\n";

using LL = long long;
using ULL = unsigned long long;

struct Point {
    int x = 0;
    int y = 0;
    int z = 0;
};

auto computePlaner(vector<Point> &points) -> void {

    int a1 = points[1].x - points[0].x; 
    int b1 = points[1].y - points[0].y;
    int c1 = points[1].z - points[0].z;

    int a2 = points[2].x - points[0].x; 
    int b2 = points[2].y - points[0].y;
    int c2 = points[2].z - points[0].z;

    int a = b1*c2 - b2*c1;
    int b = c1*a2 - c2*a1;
    int c = a1*b2 - a2*b1;
    int d = (- a*points[0].x - b*points[0].y - c*points[0].z);

    //equation of the plane is ax + by + cz + d = 0
    //check if the fourth point is valid or not
    if( a*points[3].x + b*points[3].y + c*points[3].z + d == 0 )
        cout << "YES\n";
    else
        cout << "NO\n";
}


int main()
{   
    int T = 0;
    cin >> T;
    cin.ignore();

    while(T--) {
        vector<Point> points(4);
        int x , y, z;
        FOR(i, 4){
            cin >> x >> y >> z;
            points[i].x = x;
            points[i].y = y;
            points[i].z = z;
        }

        computePlaner(points);
    }

    return 0;
}