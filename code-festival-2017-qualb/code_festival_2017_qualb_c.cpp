#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

#define int long long

const int MAX_V = 100005;
vector<int> G[MAX_V];

int color[MAX_V];

bool dfs(int cur, int c){
	color[cur] = c;
	for(auto to : G[cur]){
		if(color[to] == c) return false;
		if(color[to] == 0 && not dfs(to, -c)) return false;
	}
	return true;
}

bool solve(int n){
	rep(i,n){
		if(color[i] == 0){
			if(not dfs(i, 1)){
				return false;
			}
		}
	}
	return true;
}

signed main(){
	int n, m;
	cin >> n >> m;

	rep(i,m){
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}

	if(solve(n)){
		int w = 0, b = 0;
		rep(i,n){
			if(color[i] == 1) w++;
			else b++;
		}
		cout << w * b - m << endl;
	}else{
		cout << n * (n - 1) / 2 - m << endl;
	}
}
