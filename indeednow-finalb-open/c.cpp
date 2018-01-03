#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

#define int long long
const int INF = (1LL << 60);

signed main(){
	int n;
	string s;
	cin >> n >> s;

	vector<int> c(n + 1);
	rep(i,n){
		cin >> c[i + 1];
	}

	//奇数の回文を探す
	vector<vector<int>> p(n); //p[i][j] := i番目から始まる回文の長さがp[i][j]文字
	rep(i,n){
		int left = i, right = i;
		rep(j,n + 1){
			if(left < 0 or right >= s.size()) continue;
			if(s[left] == s[right]){
				p[left].emplace_back(right - left + 1);
			}else{
				break;
			}
			left--;
			right++;
		}
	}

	//偶数長の回文を探す
	rep(i,n - 1){
		int left = i, right = i + 1;
		rep(j,n + 1){
			if(left < 0 or right >= s.size()) continue;
			if(s[left] == s[right]){
				p[left].emplace_back(right - left + 1);
			}else{
				break;
			}
			left--;
			right++;
		}
	}

	//for(auto i : p){ for(auto j : i){ cout << j << ' '; } cout << endl; }

	vector<int> dp(s.size() + 1, INF);
	dp[0] = 0;
	rep(i,n){
		rep(j,p[i].size()){
			assert(i + p[i][j] < s.size() + 1);
			dp[i + p[i][j]] = min(dp[i + p[i][j]], dp[i] + c[p[i][j]]);
		}
	}
	cout << dp[s.size()] << endl;
}
