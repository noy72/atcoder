#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

vector<int> g[2000];

void dfs(int cur, int k, vector<bool> &used){
	used[cur] = true;
	for(auto to : g[cur]){
		if(used[to] || k == 0) continue;
		dfs(to, k - 1, used);
	}
}

int main(){
	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> v(n - 1);
	rep(i,n - 1){
		int a, b;
		cin >> a >> b;
		a--; b--;
		v[i] = make_pair(a,b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	int ans = 1e8;
	if(k % 2){
		rep(i,n - 1){
			vector<bool> used1(n,0), used2(n,0);
			dfs(v[i].first, k / 2, used1);
			dfs(v[i].second, k / 2, used2);
			int cnt = 0;
			rep(i,n){
				if(not used1[i] && not used2[i]) cnt++;
			}
			ans = min(ans, cnt);
		}
	}else{
		rep(i,n){
			vector<bool> used(n,0);
			dfs(i,k / 2,used);
			int cnt = 0;
			rep(i,n){
				if(not used[i]) cnt++;
			}
			ans = min(ans, cnt);
		}
	}
	cout << ans << endl;
}
