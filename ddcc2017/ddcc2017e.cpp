#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

#define int long long

vector<int> g[200005];

void dfs(int cur, vector<bool>& used, vector<int>& depth){
	used[cur] = true;
	for(auto to : g[cur]){
		if(not used[to]){
			depth[to] = depth[cur] + 1;
			dfs(to, used, depth);
		}
	}
}

int requireCenterOfTree(int n, vector<int> leef){ //中心ではない
	vector<int> dis(n, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	for(auto i : leef){
		dis[i] = 0;
		q.push(make_pair(0,i));
	}

	while(not q.empty()){
		pair<int, int> u = q.top(); q.pop();
		for(auto to : g[u.second]){
			if(dis[to] == INF){
				dis[to] = dis[u.second] + 1;
				q.push(make_pair(u.first + 1, to));
			}
		}
	}

	int p = 0;
	rep(i,n){
		if(dis[p] < dis[i]){
			p = i;
		}
	}
	return p;
}


const int MAX_V = 200005;

class diameterOfTree{
	public:
		vector<int> g[MAX_V];
		int dis[MAX_V];

		void set(int n, vector<int> G[MAX_V]){
			rep(i,n){
				for(auto j : G[i]){
					g[i].emplace_back(j);
				}
			}
		}

		void bfs(int s, int n){
			queue<int> q;

			rep(i,n) dis[i] = INF;
			dis[s] = 0;
			q.push(s);

			int u;
			while(not q.empty()){
				u = q.front(); q.pop();
				for(auto to : g[u]){
					if(dis[to] == INF){
						dis[to] = dis[u] + 1;
						q.push(to);
					}
				}
			}
		}

		int solve(int n){
			int maxi = 0;
			int tgt = 0; //ある点sから最も遠い点

			bfs(0, n);
			rep(i,n){
				if(dis[i] == INF) continue;
				if(maxi < dis[i]){
					maxi  = dis[i];
					tgt = i;
				}
			}

			bfs(tgt, n);
			maxi = 0; //tgtから最も遠い接点の距離maxi
			rep(i,n){
				if(dis[i] == INF) continue;
				maxi = max(maxi, dis[i]);
			}

			return maxi;
		}
};

signed main(){
	int n;
	cin >> n;

	rep(i,n - 1){
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	vector<int> leef;
	rep(i,n){
		if(g[i].size() == 1) leef.emplace_back(i);
	}

	int center = requireCenterOfTree(n, leef);

	vector<int> depth(n,0);
	vector<bool> used(n,0);
	dfs(center,used, depth);

	int max_depth = *max_element(all(depth));
	diameterOfTree dia;
	dia.set(n,g);
	int diameter = dia.solve(n);

	int sum = 0;
	for(auto i : leef){
		sum += max_depth - depth[i];
	}
	show(sum)

	int q;
	cin >> q;

	rep(i,q){
		int x;
		cin >> x;
		if(x <= sum){
			cout << diameter << endl;
		}else{
			int ans = (x / leef.size() + max_depth) * 2;
			cout << x / leef.size() << ' ' << x % leef.size() << endl;
			if(x % leef.size() == 1) ans++;
			else if(x % leef.size() >= 2) ans+=2;
			cout << ans << endl;
		}
	}
}
