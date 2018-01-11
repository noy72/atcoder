#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const int M = 1000000007;

long long dp[305][800];
const int base = 400;

int main(){
	long long n, K;
	string s;
	cin >> n >> K >> s;

	dp[0][base] = 1;
	rep(i,s.size()){
		range(j,K - base, K + base + 1){
				if(s[i] == '1' || s[i] == '?'){
					int dif = 
					if(abs(j + 1 - k) > K) continue;
					(dp[i + 1][j + 1][k] += dp[i][j][k]) %= M;
				}
				if(s[i] == '0' || s[i] == '?'){
					if(abs(j - (k + 1)) > K) continue;
					(dp[i + 1][j][k + 1] += dp[i][j][k]) %= M;
				}
		}
	}
	rep(i,s.size()){
		cout << i << endl;
		rep(j,s.size()){
		cout << j << endl;
			show(dp[s.size()][i][j]);
		}
		cout << endl;
	}

	long long dp_[800] = {0};
	rep(j,s.size()){
		rep(k,s.size()){
			(dp_[base + j - k] += dp[s.size()][j][k]) %= M;
		}
	}

	range(i,base - K, base + K + 1){
		show(dp_[i])
	}

	long long sum = 0;
	range(i,base - K, base + K + 1){
		(sum += dp_[i]) %= M;
	}
	cout << sum << endl;
}
