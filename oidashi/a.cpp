#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;


struct Point{ int x, y; };
int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};

const int N = 300;
char m[N][N];
int dis[N][N];

void bfs(int h, int w, Point p, int cost){
	queue<Point> q;

	dis[p.y][p.x] = cost;
	q.push(p);

	Point u;
	while(not q.empty()){
		u = q.front(); q.pop();
		rep(i,4){
			Point next;
			next.x = u.x + dx[i];
			next.y = u.y + dy[i];
			if(next.x < 0 || next.x >= w || next.y < 0 || next.y >= h) continue;
			if(dis[next.y][next.x] == INF && m[next.y][next.x] == '.'){
				dis[next.y][next.x] = dis[u.y][u.x] + cost;
				q.push(next);
			}
		}
	}
}

int main(){
	int h, w;
	cin >> h >> w;

	Point s, g;
	rep(i,h){
		rep(j,w){
			cin >> m[i][j];
			if(m[i][j] == 'S'){
				s = {j,i};
			}else if(m[i][j] == 'G'){
				g = {j,i};
			}
		}
	}

	rep(i,N) rep(j,N) dis[i][j] = INF;
	bfs(h, w, s, 1);
	bfs(h, w, g, -1);

	//rep(i,h){ rep(j,w){ 
	//	auto p = dis[i][j];
	//	if(p == INF) cout << "__ ";
	//	else if(p < 0) printf("%2d ", p);
	//	else printf("%2d ", p);
	//} cout << endl; }

	int maxi = 0;
	rep(i,h){
		rep(j,w){
			if(m[i][j] == '#'){
				set<int> a, b;
				rep(k,4){
					Point next;
					next.x = j + dx[k];
					next.y = i + dy[k];
					if(next.x < 0 || next.x >= w || next.y < 0 || next.y >= h) continue;

					auto& p = dis[next.y][next.x];
					if(p == INF) continue;
					if(p < 0) b.emplace(-p);
					else a.emplace(p);
				}
				//cout << a.size() << ' ' << b.size() << endl;
				if(a.empty() or b.empty()) continue;

				maxi = max(maxi, *a.begin() + *b.begin() + 0);
			}
		}
	}
	cout << maxi << endl;
}
