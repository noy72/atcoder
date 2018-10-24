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

int main(){
	int n;
	cin >> n;

	vector<int> a = {1,6};
	while(a.back() <= n) a.emplace_back(a.back() * 6);
	a.emplace_back(9);
	while(a.back() <= n) a.emplace_back(a.back() * 9);

	vector<int> dp(n + 1, INT_MAX);
	dp[0] = 0;
	rep(i,a.size()){
		rep(j,n + 1){
			if(dp[j] == INT_MAX) continue;
			if(j + a[i] > n) break;
			dp[j + a[i]] = min(dp[j + a[i]], dp[j] + 1);
		}
	}
	cout << dp[n] << endl;
}
