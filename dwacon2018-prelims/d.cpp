#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e9;
using namespace std;

vector<vector<int>> g;
vector<int> v; //x[i] + x[iと隣接する子]

void dfs(int cur, vector<int> &x){
	int cost = x[cur];
	for(auto to : g[cur]){
		cost += x[to];
		dfs(to, x);
	}
	v[cur] = cost;
}

int dfs_acc(int &n, int cur, vector<int> &x){
	if(g[cur].empty()) return x[cur]; //葉なので、タスク処理のコストは一定

	vector<pair<int, int>> m; //first: x[i], second:iのタスクを処理するまでに必要な最小の容量
	int child_x = 0;
	for(auto to : g[cur]){
		int result = dfs_acc(n, to, x);
		child_x += x[to];
		m.emplace_back(make_pair(x[to], result));
	}

	vector<int> dp(1 << m.size(), INF);
	dp[0] = 0;
	vector<int> have(1 << m.size(), 0);
	rep(s,1 << m.size()){
		rep(i,m.size()){
			if((s >> i bitand 1) == 0){
			have[s bitor 1 << i] = have[s] + m[i].first;
				dp[s bitor 1 << i] = min(dp[s bitor 1 << i], have[s] + m[i].second);
			}
		}
	}

	return max(*max_element(all(dp)), child_x + x[cur]);
}

int main(){
	int n;
	cin >> n;

	vector<int> x(n);
	rep(i,n){
		cin >> x[i];
	}

	g = vector<vector<int>>(n);
	range(i,1,n){
		int a;
		cin >> a;
		a--;
		g[a].emplace_back(i);
	}

	v = vector<int>(n);
	dfs(0, x);
	cout << dfs_acc(n, 0, x) << endl;
}
