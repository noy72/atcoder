#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

long long dp[2][305][605];

int main(){
	long long x, y, n;
	cin >> x >> y >> n;

	vector<long long> t(n), h(n);
	rep(i,n){
		cin >> t[i] >> h[i];
	}

	range(i,1,n + 1){
		range(j,1,x + 1){
			for(int k = x + y; k >= 1; k--){
				dp[i % 2][j][k] = max(dp[i % 2][j][k], dp[(i - 1) % 2][j][k]);
				if(k - t[i - 1] < 0) continue;

				dp[i % 2][j][k] = max(dp[i % 2][j][k], dp[(i - 1) % 2][j - 1][k - t[i - 1]] + h[i - 1]);
			}
		}
		rep(j,x + 1) rep(k, x + y + 1) dp[(i - 1) % 2][j][k] = 0;
	}

	long long ans = 0;
	rep(i,x + y + 1){
		ans = max(ans, dp[n % 2][x][i]);
	}
	cout << ans << endl;
}
