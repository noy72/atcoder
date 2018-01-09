#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

class UnionFind{
	static const int gmax_n = 100005;

	int par[gmax_n]; //親
	int depth[gmax_n];//木の深さ

	public:
	void init(int n){
		rep(i,n){
			par[i] = i;
			depth[i] = 0;
		}
	}

	int find(int x){
		if(par[x] == x){
			return x;
		}else {
			return par[x] = find(par[x]);
		}
	}

	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;

		if(depth[x] < depth[y]){
			par[x] = y;
		}else{
			par[y] = x;
			if(depth[x] == depth[y]) depth[x]++;
		}
	}

	bool same(int x, int y){
		return find(x) == find(y);
	}
};

const int MAX_V = 100005;
const int MAX_LOG_V = 20;

vector<int> g[MAX_V];

pair<int, int> P(int a, int b){
	return a < b ? make_pair(a,b) : make_pair(b,a);
}

map<pair<int, int>,int> edgeMap;

int parent[MAX_LOG_V][MAX_V];
int connect[MAX_LOG_V][MAX_V];
int depth[MAX_V];

void dfs(int v, int p, int d){
	parent[0][v] = p;
	connect[0][v] = p;
	depth[v] = d;
	rep(i,g[v].size()){
		if(g[v][i]!= p) dfs(g[v][i], v, d + 1);
	}
}


void init(int V){
	memset(parent, -1, sizeof(parent));
	memset(parent, -1, sizeof(connect));
	rep(i,V){
		if(parent[0][i] == -1) dfs(i, -1, 0);
	}
	rep(i,V){
		int u = i;
		int v = parent[0][i];
		if(v == -1) continue;
		//cout << u << ' ' << v << ' ' << edgeMap[P(u,v)] << endl;
		connect[0][u] = edgeMap[P(u,v)];
	}

	//show("parent")
	//rep(i,V){ cout << parent[0][i] << ' '; } cout << endl;
	//show("connect")
	//rep(i,V){ cout << connect[0][i] << ' '; } cout << endl;
	rep(k,MAX_LOG_V - 1){
		rep(v,V){
			if(parent[k][v] < 0) parent[k + 1][v] = -1;
			else {
				parent[k + 1][v] = parent[k][ parent[k][v] ];
				connect[k + 1][v] = max(connect[k][v], connect[k][ parent[k][v] ]);
				//cout << v << ' ' << parent[k][ parent[k][v]] << endl;
				//cout << connect[k][v] << ' ' <<  connect[k][ parent[k][v] ] << endl;
				//show(connect[k + 1][v])
			}
		}
	}
}

int lca(int u, int v){
	if(depth[u] > depth[v]) swap(u, v);
	//cout << depth[v] << ' ' << depth[u] << endl;

	int res = -1;
	rep(k,MAX_LOG_V){
		if( (depth[v] - depth[u]) >> k & 1){
			//show(connect[k][v])
			res = max(res, connect[k][v]);
			v = parent[k][v];
		}
	}
	//res = max(res, connect[0][u]);
	if(u == v) return res;
	for(int k = MAX_LOG_V - 1; k >= 0; k--){
		if(parent[k][u] != parent[k][v]){
			//show(connect[k][u])
			res = max(res, connect[k][u]);
			res = max(res, connect[k][v]);
			u = parent[k][u];
			v = parent[k][v];
		}
	}
	res = max({res, connect[0][u], connect[0][v]});
	return res;
}

int main(){
	int n, m;
	cin >> n >> m;

	UnionFind uni;
	uni.init(n);
	rep(i,m){
		int a, b;
		cin >> a >> b;
		a--; b--;
		if(not uni.same(a,b)){
			uni.unite(a,b);
			edgeMap[P(a,b)] = i;
			g[a].emplace_back(b);
			g[b].emplace_back(a);
		}
	}

	init(n);
	int q;
	cin >> q;
	rep(i,q){
		int x, y;
		cin >> x >> y;
		x--; y--;
		if(not uni.same(x,y)){
			cout << -1 << endl;
		}else{
			cout << lca(x,y) + 1 << endl;
		}
	}
}
