#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const int M = 1000000007;
long long dp[10005][2][105];

int main(){
	int m;
	string s;
	cin >> m >> s;

	dp[0][0][0] = 1;
	rep(i,s.size()){
		rep(j,2) rep(k,m){
			int lim = j ? 9 : s[i] - '0';
			rep(d,lim + 1){
				(dp[i + 1][j || d < lim][(k + d) % m] += dp[i][j][k]) %= M;
			}
		}
	}
	cout << (dp[s.size()][0][0] + dp[s.size()][1][0] - 1) % M << endl;
}
