#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

#define int long long
const int MAX_W = 10005;
const int MAX_C = 55;

vector<int> w, v;
int dp[MAX_C][MAX_W];

void solve(vector<int>& p, int W, int C, vector<int>& resw, vector<int>& resv){
	int dp[MAX_W] = {0};
	rep(i,p.size()){
		for(int j = W; j >= 0; j--){
			if(j + w[p[i]] > W) continue;
			dp[j + w[p[i]]] = max(dp[j + w[p[i]]], dp[j] + v[p[i]]);
		}
	}

	range(i,1,W + 1){
		if(resw.empty()){
			resw.emplace_back(i);
			resv.emplace_back(dp[i]);
		}else if(resv.back() < dp[i]){
			resw.emplace_back(i);
			resv.emplace_back(dp[i]);
		}
	}
}

signed main(){
	int n, W, C;
	cin >> n >> W >> C;

	map<int,vector<int>> m; //いろごとの添字
	w = vector<int>(n);
	v = vector<int>(n);
	rep(i,n){
		int c;
		cin >> w[i] >> v[i] >> c;
		m[c].emplace_back(i);
	}

	vector<vector<int>> dpw(MAX_C), dpv(MAX_C);
	int p = 0;
	for(auto i : m){
		solve(i.second, W, C, dpw[p], dpv[p]);
		//rep(j,dpw[p].size()){ cout << dpw[p][j] << ' ' << dpv[p][j] << endl; } cout << endl;
		p++;
	}

	rep(i,p){
		int _dp[MAX_C][MAX_W] = {{0}};
		rep(j,dpw[i].size()){
			for(int k = C; k >= 0; k--){
				rep(l,W + 1){
					_dp[k][l] = max(_dp[k][l], dp[k][l]);
					if(l + dpw[i][j] > W or k + 1 > C) continue;
					_dp[k + 1][l + dpw[i][j]] = max(_dp[k + 1][l + dpw[i][j]], dp[k][l] + dpv[i][j]);
				}
			}
		}
		rep(k,C + 1) rep(l, W + 1) dp[k][l] = _dp[k][l];
		//rep(i,C + 1){ rep(j, W + 1){ cout << dp[i][j] << ' '; } cout << endl; }
	}

	int ans = 0;
	rep(i,C + 1){
		rep(j, W + 1){
			//cout << dp[i][j] << ' ';
			ans = max(ans, dp[i][j]);
		}
		//cout << endl;
	}
	cout << ans << endl;
}
