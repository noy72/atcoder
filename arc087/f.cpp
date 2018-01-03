#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

const int MAX_V = 5005;

class Edge{
	public:
		int to, dis;
		Edge(){}
		Edge(int to, int dis): to(to), dis(dis)  {}
};

vector<Edge> g[MAX_V];
int dis[MAX_V];

void bfs(int s, int n){
	queue<int> q;

	rep(i,n) dis[i] = INF;
	dis[s] = 0;
	q.push(s);

	int u;
	while(not q.empty()){
		u = q.front(); q.pop();
		rep(i,g[u].size()){
			Edge e = g[u][i];
			if(dis[e.to] == INF){
				dis[e.to] = dis[u] + e.dis;
				q.push(e.to);
			}
		}
	}
}

int solve(int n, int s){
	int maxi = 0;
	int tgt = 0; //ある点sから最も遠い点

	bfs(s, n);
	rep(i,n){
		if(dis[i] == INF) continue;
		if(maxi < dis[i]){
			maxi  = dis[i];
			tgt = i;
		}
	}

	bfs(tgt, n);
	int p = 0;
	rep(i,n){
		if(dis[i] == INF) continue;
		if(dis[p] < dis[i]){
			p = i;
		}
	}

	return p;
}

int main(){
	int n;
	cin >> n;

	vector<pair<int, int>> e(n);
	rep(i,n){
		cin >> e[i].first >> e[i].second;
	}

	vector<bool> used(n, 0);
	int dis = 0;
	rep(i,n){
		if(used[i]) continue;

	}

	/* 直径を求めて、それをパスにする二頂点を消す。
	 *これを繰り返して、最大値を求めることができそう。
	 *ただ、求めたところで、そこからどうやって計算すれば良いのかわからない。
	 *modを取るからDP？
	 */
}
