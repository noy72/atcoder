#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

#define int long long
const int M = 1000000007;

vector<vector<int>> t,dp;

void dp1(){
	int n = 1000, m = 100;
	t = vector<vector<int>>(m + 1, vector<int>(n + 1));
	t[0][0] = 1;

	range(i,1,m + 1){
		rep(j,n + 1){
			if(j - i >= 0){
				t[i][j] = (t[i - 1][j] + t[i][j - i]) % M;
			}else{
				t[i][j] = t[i - 1][j];
			}
		}
	}
	//rep(i,10){ rep(j,10){ cout << t[i][j] << ' '; } cout << endl; }
}

int solve(vector<int> v, int n){
	map<int,int> ma;
	for(auto i : v){
		ma[i]++;
	}

	vector<int> div;
	for(auto i : ma){
		div.emplace_back(i.second);
	}
	int m = div.size();

	dp = vector<vector<int>>(m + 1, vector<int>(n + 1));
	dp[0][0] = 1;
	range(i,1,m + 1){
		rep(j,n + 1){
			rep(k,j + 1){
				//if(t[div[i - 1]][k]== 0) t[div[i - 1]][k] = 1;
				(dp[i][j] += dp[i - 1][j - k] * t[div[i - 1]][k] % M) %= M;
			}
		}
	}
	return dp[m][n];
}

signed main(){
	int n, m;
	cin >> n >> m;

	vector<int> a(n), b(m);
	rep(i,n){
		cin >> a[i];
	}

	rep(i,m){
		cin >> b[i];
	}

	dp1();

	int A = solve(a, accumulate(all(b),0));
	int B = solve(b, accumulate(all(a),0));
	cout << A * B % M << endl;
}
