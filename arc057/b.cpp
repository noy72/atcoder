#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

const long long INF = (1LL << 50);

int main(){
	int n;
	long long k;
	cin >> n >> k;

	vector<double> a(n + 1,0); // 1-index
	rep(i,n){
		cin >> a[i + 1];
		a[i + 1] += a[i];
	}

	if(a[n] == k){ //全勝するケース
		cout << 1 << endl;
		return 0;
	}

	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, INF)); //dp[i][j] := i日までに機嫌がよかった日数がjのとき、ゲームに勝った回数の最小値

	dp[0][0] = 0;
	rep(i,n){
		rep(j,n + 1){
			if(dp[i][j] == INF) continue;
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);

			long long win;
			if(dp[i][j] == 0 or i == 0){
				win = 1;
			}else{
				win = ceil(dp[i][j] * (a[i + 1] / a[i] - 1.0));
				if(dp[i][j] * a[i + 1] == (dp[i][j] + win) * a[i]) win++; //勝率が同値になる時はもう一勝必要
			}
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + win);
			//cout << i << ' ' << j << endl;
			//cout << dp[i][j]  << ' ' << dp[i + 1][j + 1]  << endl;
			//cout << dp[i][j] / a[i] << ' ' << dp[i + 1][j + 1] / a[i + 1] << endl;
		}
	}

	//rep(i,n + 1){ rep(j,n + 1){ cout << dp[i][j] << ' '; } cout << endl; cout << endl; }

	for(int i = n; i >= 0; i--){
		if(dp[n][i] <= k){
			cout << i << endl;
			return 0;
		}
	}
}
