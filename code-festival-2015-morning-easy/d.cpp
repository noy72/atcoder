#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const int MAX_N = 100;

int solve(string s, string t){
	int dp[MAX_N + 1][MAX_N + 1] = {{0}};

	rep(i,s.size()){
		rep(j,t.size()){
			if(s[i] == t[j]){
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}else{ //連続した部分文字列の場合はここを消し、dpのmaxを返す
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}
	return dp[s.size()][t.size()];
}

int main(){
	int n;
	string s;
	cin >> n >> s;

	int maxi = 0;
	rep(i,n){
		string x = s.substr(0,i);
		string y = s.substr(i,n - i);
		maxi = max(maxi, solve(x,y));
	}
	cout << n - maxi * 2 << endl;
}
