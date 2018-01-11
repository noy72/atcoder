#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

const int N = 1000;

struct Point{
	int x, y;
	bool operator < ( const Point &right ) const {
		return x < right.x;
	}
};
typedef pair<int,Point> pip;

int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};
char c[N][N];
bool m[N][N];


vector<Point> bfs(int h, int w, Point p, int k){
	int dis[N][N];
	queue<Point> q;
	rep(i,N) rep(j,N) dis[i][j] = INF;

	dis[p.y][p.x] = 0;
	q.push(p);

	Point u;
	vector<Point> res;
	while(not q.empty()){
		u = q.front(); q.pop();
		res.emplace_back(u);
		rep(i,4){
			Point next;
			next.x = u.x + dx[i];
			next.y = u.y + dy[i];
			if(next.x < 0 || next.x >= w || next.y < 0 || next.y >= h) continue;
			if(dis[next.y][next.x] == INF && c[next.y][next.x] == '.' && dis[u.y][u.x] + 1 <= k){
				dis[next.y][next.x] = dis[u.y][u.x] + 1;
				q.push(next);
			}
		}
	}
	return res;
}

int bfs(int h, int w, Point p, vector<Point> s, int k){
	int dis[N][N];
	priority_queue<pip, vector<pip>, greater<pip>> q;
	rep(i,N) rep(j,N) dis[i][j] = INF;

	for(auto i : s){
		dis[i.y][i.x] = 0;
		q.push(make_pair(0,i));
	}

	while(not q.empty()){
		pip cur = q.top(); q.pop();
		Point u = cur.second;
		rep(i,4){
			Point next;
			next.x = u.x + dx[i];
			next.y = u.y + dy[i];
			if(next.x < 0 || next.x >= w || next.y < 0 || next.y >= h) continue;
			if(dis[next.y][next.x] > dis[u.y][u.x] + 1){
				dis[next.y][next.x] = dis[u.y][u.x] + 1;
				q.push(make_pair(dis[next.y][next.x], next));
			}
		}
	}

	int ans = INF;
	rep(i,h) ans = min(ans, min(dis[i][0], dis[i][w - 1]));
	rep(i,w) ans = min(ans, min(dis[0][i], dis[h - 1][i]));
	//show(ans)

	//rep(i,h){ rep(j,w){ cout << dis[i][j] << ' '; } cout << endl; }

	return (ans + k - 1) / k;
}


int main(){
	int h, w, k;
	cin >> h >> w >> k;

	Point s;
	rep(i,h){
		rep(j,w){
			cin >> c[i][j];
			if(c[i][j] == 'S') s = Point{j,i};
		}
	}
	vector<Point> tmp = bfs(h, w, s, k);
	cout << bfs(h, w, s, tmp, k) + 1 << endl;
}
