#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;


const int MAX_V = 1000;

vector<int> g[MAX_V]; //グラフ
vector<int> rg[MAX_V]; //辺が逆になったグラフ
vector<int> vs; //帰りがけ順の並び
vector<char> c;
bool used[MAX_V];
int cmp[MAX_V]; //属する強連結成分のトポロジカル順序

void addEdge(int from, int to){
	g[from].emplace_back(to);
	rg[to].emplace_back(from);
}

void dfs(int v){
	used[v] = true;
	rep(i,g[v].size()){
		if(not used[g[v][i]]) dfs(g[v][i]);
	}
	vs.emplace_back(v);
}

void rdfs(int v, int k){
	used[v] = true;
	cmp[v] = k;
	rep(i,rg[v].size()){
		if(not used[rg[v][i]]) rdfs(rg[v][i], k);
	}
}

int scc(int v){
	memset(used, 0, sizeof(used));
	vs.clear();
	rep(i,v){
		if(not used[i]) dfs(i);
	}
	memset(used, 0, sizeof(used));
	int k = 0;
	for(int i = vs.size() - 1; i >= 0; i--){
		if(not used[vs[i]]) rdfs(vs[i], k++);
	}
	return k;
}

void DAG(int n, bool dag[MAX_V][MAX_V]){
	rep(i,n){
		for(auto j : g[i]){
			if(cmp[i] != cmp[j]){
				dag[cmp[i]][cmp[j]] = 1;
			}
		}
	}
}

int main(){
	int n, m, k;
	cin >> n >> m >> k;

	c = vector<char>(n);
	rep(i,n){
		cin >> c[i];
	}

	rep(i,m){
		int a, b;
		cin >> a >> b;
		a--; b--;
		addEdge(a,b);
	}

	bool dag[MAX_V][MAX_V] = {{0}};
	int scc_v = scc(n);
	DAG(n, dag);

	vector<string> v(scc_v);
	rep(i,scc_v){
		rep(j,n){
			if(cmp[j] == i) v[i].push_back(c[j]);
		}
		sort(all(v[i]));
	}

	string dp[MAX_V][MAX_V]; //強連結成分、文字数
	rep(i,MAX_V) rep(j,MAX_V) dp[i][j] = "~";
	dp[0][0] = "";
	
	rep(i,scc_v){
		rep(to,scc_v + 1){
			if(to != scc_v && not dag[i][to]) continue;
			rep(j,k + 1){
				dp[to][j] = min(dp[to][j], dp[i][j]);
				string s;
				int len = 0;
				for(auto chr : v[i]){
					s += chr;
					len++;
					dp[to][j + len] = min(dp[to][j + len], dp[i][j] + s);
				}
			}
		}
	}

	cout << (dp[scc_v][k] == "~" ? "-1" : dp[scc_v][k]) << endl;
}
