#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}


class Node{
	public:
		bool used;
		int ord; //DFSの訪問の順番
		int par; //DFS Treeにおける親
		int low; //min(自分のord, 逆辺がある場合の親のord, すべての子のlow)
		Node() : ord(-1) { }
};

class ArticulationPoints {
	private:
		int v, cnt;
		vector<Node> node;
		void dfs(int cur, int prev){
			//cout << cur << ' ' << prev << endl;
			node[cur].ord = node[cur].low = cnt;
			cnt++;

			node[cur].used = true;

			for(auto to : g[cur]){
				if(to == prev) continue;
				if(node[to].ord >= 0){
					node[cur].low = min(node[cur].low, node[to].ord);

				}else{
					node[to].par = cur;
					dfs(to, cur);
					node[cur].low = min(node[cur].low, node[to].low);

				}
					if(node[cur].ord < node[to].low){
						bridge.emplace_back(min(cur, to), max(cur, to));
					}
			}
		}
	public:
		vector<vector<int>> g;
		vector<pair<int, int>> bridge;
		set<int> ap; // 関節店
		ArticulationPoints(int n) : v(n), cnt(1), node(n), g(n) { }
		void addEdge(int a, int b){
			g[a].emplace_back(b);
			g[b].emplace_back(a);
		}
		bool isBridge(int u, int v){
			if(node[u].ord > node[v].ord) swap(u,v);
			return node[u].ord < node[v].low;
		}
		void run(){
			dfs(0, -1); // 0 = root

			int np = 0;
			range(i,1,v){
				int p = node[i].par;
				if(p == 0) np++;
				else if(node[p].ord <= node[i].low) ap.emplace(p);
			}
			if(np > 1) ap.emplace(0);
			//for(auto it:ap){ cout << it << endl; } //関節点の全列挙
			sort(all(bridge));
			//for(auto it:bridge){ cout << it.first << ' ' << it.second << endl; } //橋の全列挙
		}
};

class TwoEdgeConnectedComponext : public ArticulationPoints {
	private:
		void dfs(int c, int pos){
			ver[c].emplace_back(pos);
			comp[pos] = c;
			for (int to : g[pos]) {
				if (comp[to] >= 0) continue;
				if (isBridge(pos, to)) continue;
				dfs(c, to);
			}
		}
		void addComp(int pos){
			if(comp[pos] >= 0) return;
			ver.emplace_back();
			dfs(ver.size() - 1, pos);
		}
	public:
		vector<int> comp; // 成分分解前の頂点から分解後の頂点への写像？
		vector<vector<int>> ver; // 分解後の頂点と、その頂点に含まれる分解前の頂点
		TwoEdgeConnectedComponext(int n) : ArticulationPoints(n), comp(n,-1) {}
		void solve(){
			run();
			for(auto p : bridge){
				addComp(p.first);
				addComp(p.second);
			}
			addComp(0);
		}
		vector<vector<int>> getTree(){
			vector<vector<int>> res(ver.size());
			for(auto p : bridge){
				int u = comp[p.first], v = comp[p.second];
				res[u].emplace_back(v);
				res[v].emplace_back(u);
			}
			return res;
		}
};

class LCA{
	private:
		vector<vector<int>> g, parent;
		int n, root, log_n;
		bool inited;
		vector<int> depth;
		void dfs(int v, int p, int d){
			parent[0][v] = p;
			depth[v] = d;
			rep(i,g[v].size()){
				if(g[v][i] != p) dfs(g[v][i], v, d + 1);
			}
		}
		void init(){
			inited = true;
			dfs(root, -1, 0);
			rep(k,log_n - 1){
				rep(i,n){
					if(parent[k][i] < 0) parent[k + 1][i] = -1;
					else parent[k + 1][i] = parent[k][ parent[k][i] ];
				}
			}
		}
		void dfs(int pos){
			for(auto to : g[pos]){
				if(dis[to] != -1) continue;
				dis[to] = dis[pos] + 1;
				dfs(to);
			}
		}
	public:
		vector<int> dis;
		LCA(int n, int root = 0) : g(n), parent(log2(n) + 1, vector<int>(n)), n(n), root(root), log_n(log2(n) + 1), inited(false), depth(n), dis(n, -1) { }
		void addEdge(int u, int v){
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		void set(vector<vector<int>>& a){
			g = a;
		}
		void dfs(){
			dis[0] = 0;
			dfs(0);
		}
		int dist(int u, int v){
			return dis[u] + dis[v] - 2 * dis[get(u,v)];
		}
		int get(int u, int v){
			if(not inited) init();
			if(depth[u] > depth[v]) swap(u, v);
			rep(k,log_n){
				if( (depth[v] - depth[u]) >> k & 1){
					v = parent[k][v];
				}
			}
			if(u == v) return u;
			for(int k = log_n - 1; k >= 0; k--){
				if(parent[k][u] != parent[k][v]){
					u = parent[k][u];
					v = parent[k][v];
				}
			}
			return parent[0][u];
		}
};

int main(){
	int n, m;
	cin >> n >> m;

	TwoEdgeConnectedComponext tecc(n);
	rep(i,m){
		int s, t;
		cin >> s >> t;
		s--; t--;
		tecc.addEdge(s,t);
	}
	tecc.solve();
show(tecc.bridge.size())

	show("JI")
	vector<vector<int>> g = tecc.getTree();
	LCA lca(g.size());
	lca.set(g);
	lca.dfs();

	//for(auto i : g){ for(auto j : i) cout << j << ' '; cout << endl; }

	//for(auto i : tecc.comp){ cout << i << ' '; } cout << endl;

	int q;
	cin >> q;
	rep(i,q){
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--; c--;
		a = tecc.comp.at(a);
		b = tecc.comp.at(b);
		c = tecc.comp.at(c);
		if(lca.dist(a,b) + lca.dist(b,c) == lca.dist(a,c)) cout << "OK" << endl;
		else cout << "NG" << endl;
	}
}
