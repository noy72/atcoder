#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

const long long M = 1000000007;

long long power(long long x, long long n){
	long long res = 1;
	if(n > 0){
		res = power(x, n / 2);
		if(n % 2 == 0) res = (res * res) % M;
		else res = (((res * res) % M) * x ) % M;
	}
	return res;
}

int main(){
	int n, x, y, z;
	cin >> n >> x >> y >> z;

	long long MAX = x + y + z;
	long long s = (1 << (x + y + z - 1)) + (1 << (x + y - 1)) + (1 << (x - 1));
	long long mask = (1 << MAX) - 1;

	vector<vector<long long>> dp(n + 1, vector<long long>(1 << MAX));
	dp[0][0] = 1;
	rep(i,n){
		rep(j,1 << MAX){
			range(k,1,11){
				long long nbit = mask bitand ((j << k) + (1 << (k - 1)));
				if((nbit bitand s) == s) continue; // x, y, zを含んでしまう

				(dp[i + 1][nbit] += dp[i][j]) %= M;
			}
		}
	}

	long long sum = 0;
	rep(i,1 << MAX) (sum += dp[n][i]) %= M;

	cout << (power(10, n) - sum + M) % M << endl;
}
