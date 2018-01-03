#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;


int main(){
	int n, x, y;
	cin >> n >> x >> y;

	vector<int> a(n), b(n);
	rep(i,n){
		cin >> a[i] >> b[i];
	}

	static int dp[55][20005];
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	rep(i,n){
		int _dp[55][20005];
		memset(_dp, -1, sizeof(_dp));
		for(int j = n - 1; j >= 0; j--){
			rep(k,20001){
				if(dp[j][k] == -1) continue;
				_dp[j][k] = max(_dp[j][k], dp[j][k]);
				_dp[j + 1][min(k + a[i], 20000)] = max(_dp[j + 1][min(k + a[i], 20000)], dp[j][k] + b[i]);
			}
		}
		//rep(i,n){ rep(j,11){ cout << _dp[i][j] << ' '; } cout << endl; }
		rep(j,n + 1) rep(k,20001) dp[j][k] = _dp[j][k];
	}

	//rep(i,n){ rep(j,11){ cout << dp[i][j] << ' '; } cout << endl; }

	rep(i,n + 1){
		rep(j,20001){
			if(dp[i][j] >= y and dp[i][j] - y + j >= x){
				cout << i << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
}
