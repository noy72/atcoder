#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

const int N = 50;

struct Point{ int x, y; };
int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};
char M[N][N];

int bfs(int h, int w, Point p){
	int dis[N][N];
	queue<Point> q;
	rep(i,N) rep(j,N) dis[i][j] = INF;

	dis[p.y][p.x] = 0;
	q.push(p);

	Point u;
	while(not q.empty()){
		u = q.front(); q.pop();
		rep(i,4){
			Point next;
			next.x = u.x + dx[i];
			next.y = u.y + dy[i];
			if(next.x < 0 || next.x >= w || next.y < 0 || next.y >= h) continue;
			if(dis[next.y][next.x] == INF && M[next.y][next.x] == '.'){
				dis[next.y][next.x] = dis[u.y][u.x] + 1;
				q.push(next);
			}
		}
	}
	return dis[h - 1][w - 1] - 1;
}

int main(){
	int h, w;
	cin >> h >> w;

	int sum = 0;
	rep(i,h){
		rep(j,w){
			cin >> M[i][j];
			if(M[i][j] == '.') sum++;
		}
	}

	int res = bfs(h, w, Point{0,0});
	if(res == INF - 1){
		cout << -1 << endl;
	}else{
		cout << sum - bfs(h, w, Point{0,0}) - 2 << endl;
	}
}
