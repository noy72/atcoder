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

const int M = 1000000007;
long long dp[100005][2][100];

int main(){
	string s;
	int d;
	cin >> d >> s;

	dp[0][0][0] = 1;
	rep(i,s.size()) rep(j,2) rep(k,d) {
		int lim = j ? 9 : s[i] - '0';
		rep(l, lim + 1){
			(dp[i + 1][j or l < lim][(k + l) % d] += dp[i][j][k]) %= M;
		}
	}
	cout << dp[s.size()][1][0] + dp[s.size()][0][0] - 1 << endl;
}
