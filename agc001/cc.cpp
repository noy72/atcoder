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

vector<vector<int>> g;
void dfs(int pos, vector<bool>& use, int k){
	if(k < 0) return;
	use[pos] = false;
	for(auto to : g[pos]){
		if(not use[to]) continue;
		dfs(to, use, k - 1);
	}
}

int main(){
	int n, k;
	cin >> n >> k;

	g = vector<vector<int>>(n);
	vector<pair<int, int>> e(n - 1);
	rep(i,n - 1){
		int a, b;
		cin >> a >> b;
		a--; b--;
		e[i] = make_pair(a,b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	int ans = 1e9;
	if(k % 2){
		rep(i,n - 1){
			vector<bool> use(n, 1);
			use[e[i].first] = use[e[i].second] = 0;
			dfs(e[i].first, use, k / 2);
			dfs(e[i].second, use, k / 2);
			ans = min(ans, accumulate(all(use), 0));
		}
	}else{
		rep(i,n){
			vector<bool> use(n, 1);
			dfs(i, use, k / 2);
			ans = min(ans, accumulate(all(use), 0));
		}
	}
	cout << ans << endl;
}
