#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

double dp[2][205][100][100];

map<long long, long long> prime_factor(long long n){
	map<long long, long long> res;
	for(long long i = 2; i * i <= n; i++){
		while(n % i == 0){
			++res[i];
			n /= i;
		}
	}
	if(n != 1) res[n] = 1;
	return res;
}

//x^n mod M
typedef long long ull;
ull power(ull x, ull n, ull M = 1000000009){
	ull res = 1;
	if(n > 0){
		res = power(x, n / 2, M);
		if(n % 2 == 0) res = (res * res) % M;
		else res = (((res * res) % M) * x ) %M;
	}
	return res;
}

int main(){
	long long n, d;
	cin >> n >> d;

	if(d == 1){
		cout << fixed << setprecision(8)<<1.0 / power(6,min(n,10LL)) << endl;
		return 0;
	}

	map<long long,long long> m = prime_factor(d);
	for(auto i : m){
		if(i.first >= 6){
			cout << 0 << endl;
			return 0;
		}
	}

	dp[0][0][0][0] = 1;
	rep(i,n){
		rep(k,2 * i + 1) rep(l,i + 1) rep(o,i + 1){
			dp[(i + 1) % 2][k][l][o] += dp[i % 2][k][l][o] / 6.0;
			dp[(i + 1) % 2][k + 1][l][o] += dp[i % 2][k][l][o] / 6.0;
			dp[(i + 1) % 2][k][l + 1][o] += dp[i % 2][k][l][o] / 6.0;
			dp[(i + 1) % 2][k + 2][l][o] += dp[i % 2][k][l][o] / 6.0;
			dp[(i + 1) % 2][k][l][o + 1] += dp[i % 2][k][l][o] / 6.0;
			dp[(i + 1) % 2][k + 1][l + 1][o] += dp[i % 2][k][l][o] / 6.0;
		}
		rep(k,200) rep(l,100) rep(o,100) dp[i % 2][k][l][o] = 0;
	}

	double ans = 0;
	int p1 = m[2], p2 = m[3], p3 = m[5];
	range(i,p1,200) range(j,p2,100) range(k,p3,100){
		ans += dp[n % 2][i][j][k];
		//if(dp[n][i][j][k] != 0){ cout << i << ' ' << j << ' ' << k << endl; show( dp[n][i][j][k]) }
	}
	cout << fixed << setprecision(8)<<ans << endl;
}
