#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

vector<vector<int>> g;

int dfs(int cur, vector<bool>& used){
	//cout << cur << endl;
	used[cur] = true;

	int res = 1;
	for(auto to : g[cur]){
		if(used[to]) continue;
		res += dfs(to, used);
	}
	return res;
}

int main(){
	int n;
	cin >> n;

	g = vector<vector<int>>(n);
	rep(i,n - 1){
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	vector<bool> used(n,0);
	used[0] = true;

	if(g[0].size() == 1){
		cout << 'A' << endl;
		return 0;
	}

	int num = 0;
	for(auto to : g[0]){
		num += dfs(to, used) % 2;
		//show(num)
	}

	cout << (num % 2 ? 'A' : 'B') << endl;
}
