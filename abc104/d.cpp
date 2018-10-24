#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

#define int long long
const int M = (1LL << 60);

int solve(string& s, string t){
	vector<vector<int>> dp(s.size() + 1, vector<int>(t.size(), 0));

	map<char,int> m;
	rep(i,t.size()){
		m[t[i]] = i;
	}

	rep(i,s.size()){
		if(not m.count(s[i])){
			rep(j,t.size()){
				dp[i + 1][j] += dp[i][j];
			}
			continue;
		}

		int p = m[s[i]];

		if(p == 0) dp[i + 1][p] += dp[i][0] + 1;
		else (dp[i + 1][p] += dp[i][p - 1]) %= M;

		rep(j,t.size()){
			dp[i + 1][j] += dp[i][j];
		}

		//rep(j,t.size()){ rep(k,s.size() + 1){ cout << dp[k][j] << ' '; } cout << endl; } cout << endl; cout << endl;
	}
	show(t)
	rep(j,t.size()){ rep(k,s.size() + 1){ cout << dp[k][j] << ' '; } cout << endl; } cout << endl; cout << endl;
	
	return dp.back().back();
}

int power(int x, int n){
	if(n < 0) return 0;

	int res = 1;
	if(n > 0){
		res = power(x, n / 2);
		if(n % 2 == 0) res = (res * res) % M;
		else res = (((res * res) % M) * x ) % M;
	}
	return res;
}

signed main(){
	string s;
	cin >> s;

	int sum = 0;
	for(auto& c : s) sum += c == '?' ? 1 : 0;

	int ans = 0;
	ans += solve(s, "ABC") * power(3, sum);

	for(auto t : {"AB", "AC", "BC"}){
		ans += solve(s, t) * power(3, sum - 1) * sum;
	}
	for(auto t : {"A", "B", "C"}){
		ans += solve(s, t) * power(3, sum - 2) * sum * (sum - 1) / 2;
	}

	ans += power(3, sum - 3);

	cout << ans << endl;
}
