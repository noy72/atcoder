#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template <typename X, typename T>
auto vectors(X x, T a) {
	return vector<T>(x, a);
}

template <typename X, typename Y, typename Z, typename... Zs>
auto vectors(X x, Y y, Z z, Zs... zs) {
	auto cont = vectors(y, z, zs...);
	return vector<decltype(cont)>(x, cont);
}

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

const long long INF = (1LL << 60);

int main(){
	int n, k;
	cin >> n >> k;

	vector<long long> a(n);
	rep(i,n){
		cin >> a[i];
	}

	vector<long long> dp(n + 1, -INF);
	long long m = -INF;
	dp[0] = 0;
	rep(i,n){
		if(i >= k - 1){
			m = max(m, dp[i - (k - 1)]);
		}
		dp[i + 1] = max({dp[i + 1], dp[i] + a[i], m});
	}
	cout << dp.back() << endl;
}
