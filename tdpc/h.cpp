#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int n, W, C;
int dp[10005][55];
int dp_[10005][55];

void solve(vector<pair<int, int>> &v){
	rep(i,W + 1) rep(j,C + 1) dp_[i][j] = dp[i][j];
	rep(i,n){
		rep(j,C + 1){
			for(int k = W; k >= v[i].first; k--){
				dp_[k][j] = max(dp_[k][j], dp_[k - v[i].first][j] + v[i].second);
			}
		}
	}
	rep(i,C) rep(j,W + 1) dp[j][i + 1] = max(dp[j][i + 1], dp_[j][i]);
}

int main(){
	cin >> n >> W >> C;

	map<int,vector<pair<int, int>>> m;
	rep(i,n){
		int w, v, c;
		cin >> w >> v >> c;
		c--;
		m[c].emplace_back(make_pair(w,v));
	}

	for(auto i : m){
		solve(i.second);
	}

	int ans = 0;
	rep(i,W + 1) rep(j,C + 1) ans = max(ans, dp[i][j]);
	cout << ans << endl;
}
