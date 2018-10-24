#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

vector<vector<pair<int, int>>> g;

bool f;
void dfs(int cur, vector<int>& cost){
	for(auto e : g[cur]){
		int to, dis;
		tie(to,dis) = e;
		if(cost[to] == INF){
			cost[to] = cost[cur] + dis;
			dfs(to, cost);
		}else{
			if(cost[to] != cost[cur] + dis){
				f = false;
			}
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	g = vector<vector<pair<int, int>>>(n);
	rep(i,m){
		int l, r, c;
		cin >> l >> r >> c;
		l--; r--;
		g[l].emplace_back(r,c);
		g[r].emplace_back(l,-c);
	}

	f = true;
	vector<int> cost(n,INF);
	rep(i,n){
		if(cost[i] != INF) continue;
		cost[i] = 0;
		dfs(i, cost);
	}
	cout << (f ? "Yes" : "No") << endl;
}
