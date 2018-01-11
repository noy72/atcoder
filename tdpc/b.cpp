#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

int A, B;
vector<int> a, b;

int dp[1001][1001];

int dfs(int i, int j){
	if(dp[i][j] != -1) return dp[i][j];

	int res;
	if((i + j) % 2){
		res = INF;
		if(i < A) res = min(res, dfs(i + 1, j));
		if(j < B) res = min(res, dfs(i, j + 1));
	}else{ //先手
		res = 0;
		if(i < A) res = max(res, dfs(i + 1, j) + a[i]);
		if(j < B) res = max(res, dfs(i, j + 1) + b[j]);
	}
	return dp[i][j] = res;
}

int main(){
	cin >> A >> B;

	a = vector<int>(A);
	b = vector<int>(B);
	rep(i,A) cin >> a[i];
	rep(i,B) cin >> b[i];

	memset(dp, -1, sizeof(dp));
	dp[A][B] = 0;

	cout << dfs(0,0) << endl;
}
