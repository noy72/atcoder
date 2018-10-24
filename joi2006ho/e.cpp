#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

int g[100][100];

int path;

void solve(int cur, vector<bool> used, int cnt){
	used[cur] = true;

	bool f = false;
	rep(i,100){
		if(g[cur][i] == 0) continue;
		if(used[i]) continue;
		solve(i, used, cnt + 1);
		f = true;
	}
	if(not f){
		path = max(path, cnt);
	}
}

int main(){
	int n;
	cin >> n;

	vector<pair<int, int>> v;
	rep(i,n){
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a][b] = g[b][a] = 1;
		v.emplace_back(make_pair(a,b));
	}

	int ans = 0;
	for(auto p : v){
		int i, j;
		tie(i,j) = p;
		g[i][j] = g[j][i] = 0;
		rep(k,n){
			solve(k, vector<bool>(n,0), 0);
		}
		ans = max(ans, path);
		g[i][j] = g[j][i] = 1;
	}
	cout << ans + 1 << endl;
}
