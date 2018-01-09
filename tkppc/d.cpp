#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;


struct Point{
	int x, y, z; 
	bool operator < ( const Point &right ) const {
		return x < right.x;
	}
};
int dy[4] = {0,1}, dx[4] = {1,0};

const int N = 100;
int n, r, c;
char m[N][N][N];

int bfs(Point p){
	int dis[N][N][N];
	typedef pair<int,Point> P;
	priority_queue<P, vector<P>, greater<P>> q;
	rep(i,N) rep(j,N) rep(k,N) dis[i][j][k] = INF;

	dis[p.z][p.y][p.x] = 0;
	q.push(make_pair(0,p));

	while(not q.empty()){
		P p = q.top(); q.pop();
		Point u = p.second;
		rep(i,2){
			Point nt;
			nt.x = u.x + dx[i];
			nt.y = u.y + dy[i];
			nt.z = u.z;
			if(nt.x < 0 || nt.x >= c || nt.y < 0 || nt.y >= r) continue;
			if(dis[nt.z][nt.y][nt.x] == INF and m[nt.z][nt.y][nt.x] != 'H'){
				dis[nt.z][nt.y][nt.x] = p.first + m[nt.z][nt.y][nt.x] - '0';
				q.push(make_pair(dis[nt.z][nt.y][nt.x], nt));
			}else if(m[nt.z][nt.y][nt.x] == 'H' and dis[nt.z + 1][nt.y][nt.x] == INF){
				nt.z += 1;
				dis[nt.z][nt.y][nt.x] = p.first + m[nt.z][nt.y][nt.x] - '0';
				q.push(make_pair(dis[nt.z][nt.y][nt.x], nt));
			}
		}
	}
	return dis[n - 1][r - 1][c - 1];
}

int main(){
	cin >> n >> r >> c;

	rep(i,n){ rep(j,r){ rep(k,c){ cin >> m[i][j][k]; } } }
	Point s = Point{0,0,0};
	cout << bfs(s) << endl;
}
