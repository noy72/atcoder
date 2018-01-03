#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

#define int long long

signed main(){
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> p(m);
	vector<vector<int>> v(n + 1);
	rep(i,m){
		int a, b;
		cin >> a >> b;
		p[i] = make_pair(a,b);
		v[a].emplace_back(b);
	}

	vector<vector<int>> pn(vector<vector<int>>(n + 1, vector<int>(n + 1,0)));
	rep(i,m){
		for(auto j : v[p[i].second]){
			pn[p[i].first][j]++;
		}
	}

	int ans = 0;
	rep(i,n + 1){
		rep(j,n + 1){  
			//cout << i.first.first << ' ' << i.first.second << ' '<< i.second << endl;
			ans += pn[i][j] * pn[i][j];
		}
	}
	cout << ans << endl;
}
