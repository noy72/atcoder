#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const int M = 1000000007;
long long dp[1000005];

int main(){
	int n, k;
	cin >> n >> k;
	n-=1;

	long long t = 1;
	rep(i,n){
		if(i < k){
			dp[i] = t;
		}else{
			dp[i] = dp[i - 1] + dp[i - k];
		}
		(t*=2) %= M;
		show(dp[i])
	}
	cout << dp[n - 1] << endl;
}
