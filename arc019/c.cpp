#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

struct Node{
	int dis,k;
	bool visited[50][50];
};

const int N = 55;
Node node[50][50];
char m[N][N];

struct Point { int x, y, z; };
int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};

void bfs(int h, int w, int k, Point s){
	queue<Point> q;

	node[s.y][s.x].k = 0;
	dis[s.y][s.x][0] = 0;
	q.push(Point{s.x, s.y, 0});

	Point u;
	while(not q.empty()){
		u = q.front(); q.pop();
		if(dis[u.y][u.x][u.z] == INF) continue;
		rep(i,4){
			Point next;
			next.x = u.x + dx[i];
			next.y = u.y + dy[i];
			if(next.x < 0 || next.x >= w || next.y < 0 || next.y >= h) continue;
			if(m[next.y][next.x] == 'T') continue;
			if(m[next.y][next.x] == 'E'){
				if(dis[next.y][next.x][u.z + 1] == INF && u.z + 1 <= k){
					dis[next.y][next.x][u.z + 1] = dis[u.y][u.x][u.z] + 1;
					q.push(Point{next.x, next.y, u.z + 1});
				}
			}else{
				if(dis[next.y][next.x][u.z] == INF){
					dis[next.y][next.x][u.z] = dis[u.y][u.x][u.z] + 1;
					q.push(Point{next.x, next.y, u.z});
				}
			}
		}
	}
	//rep(i,h){ rep(j,w){ cout << dis[i][j][3] << ' '; } cout << endl; } cout << endl;
}

int main(){
	int h, w, k;
	cin >> h >> w >> k;

	Point s, c, g;
	rep(i,h){
		rep(j,w){
			cin >> m[i][j];
			if(m[i][j] == 'S'){
				s = Point{j,i};
			}else if(m[i][j] == 'C'){
				c = Point{j,i};
			}else if(m[i][j] == 'G'){
				g = Point{j,i};
			}
		}
	}

	rep(i,h){
		rep(j,w){
			node[i][j].dis = INF;
			node[i][j].k = 0;
			memset(node[i][j].visited, 0, sizeof(node[i][j].visited));
		}
	}
	bfs(h,w,k,s);
	bfs(h,w,k,c);

	vector<Point> p;

}
