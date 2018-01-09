#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

#define int long long
const int INF = (1LL << 60);

const int MAX_V = 100005;

class Edge{
	public:
		int to, dis;
		Edge(){}
		Edge(int to, int dis): to(to), dis(dis)  {}
};

vector<Edge> g[MAX_V];
int dis[MAX_V];

vector<int> bfs(int s, int n, bool f){
	queue<int> q;

	rep(i,n) dis[i] = INF;
	dis[s] = 0;
	q.push(s);

	vector<int> pre(n,-1);
	while(not q.empty()){
		int d = q.front(); q.pop();

		rep(i,g[d].size()){
			Edge e = g[d][i];
			if(dis[e.to] == INF){
				pre[e.to] = d;
				dis[e.to] = dis[d] + e.dis;
				q.push(e.to);
			}
		}
	}

	int maxi = -1;
	rep(i,n){
		if(dis[i] == INF) continue;
		if(maxi == -1) maxi = i;
		if(dis[maxi] < dis[i]){
			maxi = i;
		}
	}
	if(f) return vector<int>() = {maxi};

	vector<int> path = {maxi};
	while(pre[maxi] != -1){
		maxi = pre[maxi];
		path.emplace_back(maxi);
	}
	reverse(all(path));
	return path;
}

const int gmax_n = 100005;

int par[gmax_n]; //親
int depth[gmax_n];//木の深さ

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

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<pair<int, int>> e(n - 1);
	rep(i,n - 1){
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		e[i] = make_pair(a,b);
		g[a].emplace_back(b,c);
		g[b].emplace_back(a,c);
	}

	vector<int> path = bfs(bfs(0, n, 1).front(), n, 0);
	//for(auto i : path){ cout << i << endl; }

	//assert(true);
	vector<bool> used(n,0);
	vector<int> ans(n);
	for(auto i : path){
		used[i] = true;
		if(dis[i] > dis[path.back()] - dis[i]){
			ans[i] = path.front();
		}else if(dis[i] < dis[path.back()] - dis[i]){
			ans[i] = path.back();
		}else{
			ans[i] = min(path.front(), path.back());
		}
	}

	init(n);
	rep(i,n - 1){
		if(used[e[i].first] and used[e[i].second]) continue;
		unite(e[i].first, e[i].second);
	}

	vector<int> par(n);
	for(auto i : path){
		par[find(i)] = ans[i];
	}
	rep(i,n){
		if(used[i]) continue;
		ans[i] = par[find(i)];
	}

	for(auto& i : ans){
		cout << i + 1 << endl;
	}
}
