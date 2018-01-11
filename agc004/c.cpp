#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

	char g[500][500];
char a[500][500], b[500][500];

struct Point{ int x, y; };
int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};

void bfs(int h, int w){
	bool dis[500][500] = {{0}};
	queue<Point> q;

	dis[0][0] = true;
	b[0][0] = '#';
	q.push({0,0});

	Point u;
	while(not q.empty()){
		u = q.front(); q.pop();
		rep(i,4){
			Point next;
			next.x = u.x + dx[i];
			next.y = u.y + dy[i];
			if(next.x < 0 || next.x >= w || next.y < 0 || next.y >= h) continue;
			if(not dis[next.y][next.x] && (a[next.y][next.x] == '.' or g[next.y][next.x] == '#')){
				dis[next.y][next.x] = true;
				b[next.y][next.x] = '#';
				q.push(next);
			}
		}
	}
}

int main(){
	int h, w;
	cin >> h >> w;

	rep(i,h){
		cin >> g[i];
	}

	rep(i,h) rep(j,w) a[i][j] = b[i][j] = '.';
	rep(i,h){
		rep(j,w){
			if(g[i][j] == '#'){
				a[i][j] = b[i][j] = '#';
			}
		}
	}
	//rep(i,h){ rep(j,w){ cout << a[i][j]; } cout << endl; }

	for(int i = 1; i < h; i+=2){
		for(int j = 1; j < w - 1; j++){
			a[i][j] = '#';
		}
	}
	//rep(i,h){ rep(j,w){ cout << a[i][j]; } cout << endl; }

	for(int i = 1; i < h - 1; i++){
		if((i - 1) % 4 == 1) a[i][w - 2] = '#';
		if((i - 1) % 4 == 3) a[i][1] = '#';
	}


	bfs(h,w);
	//rep(i,h){ rep(j,w){ if(a[i][j] == '.') b[i][j] = '#'; } }

	//rep(i,h){ rep(j,w){ if(a[i][j] == '#' && b[i][j] == '#') cout << a[i][j]; else cout << '.'; } cout << endl; }

	rep(i,h){ rep(j,w){ cout << a[i][j]; } cout << endl; }
	cout << endl;
	rep(i,h){ rep(j,w){ cout << b[i][j]; } cout << endl; }
}
