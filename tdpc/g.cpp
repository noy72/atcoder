#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

long long dp[1000001][30];

int main(){
	string s;
	long long k;
	cin >> s >> k;

	long long sum = 0;
	for(int i = s.size() - 1; i >= 0; i--){
		dp[i][s[i] - 'a'] = sum + 1;
		sum += dp[i][s[i] - 'a'];
		show(dp[i][s[i] - 'a'])
	}
}
