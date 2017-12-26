#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

vector<vector<int>> g;
vector<int> ans;

void bfs(int n, vector<int>& dis, int v, int d, int c){
	queue<int> q;
	q.push(v);

	int u;
	while(!q.empty()){
		u = q.front(); q.pop();
		if(ans[u] == 0) ans[u] = c;

		for(auto to : g[u]){
			if(dis[to] < dis[u] - 1){
				dis[to] = dis[u] - 1;
				q.emplace(to);
			}
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	g = vector<vector<int>>(n);
	rep(i,m){
		int a, b;
		cin >> a >> b;
		a--; b--;

		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	//rep(i,n){ for(auto j : g[i]){ cout << j.first << ' ' ; } cout << endl; }

	int q;
	cin >> q;

	vector<int> v(q), d(q), c(q);
	rep(i,q){
		cin >> v[i] >> d[i] >> c[i];
		v[i]--;
	}

	ans = vector<int>(n,0);
	vector<int> dis(n,-1); // dis[i] :- 頂点iから距離dis[i]にある頂点は色が塗ってある
	for(int i = q - 1; i >= 0; i--){
		if(dis[v[i]] < d[i]){
			dis[v[i]] = d[i];
			bfs(n, dis, v[i], d[i], c[i]);
		}
	}
	for(auto i : ans){
		cout << i << endl;
	}
}
