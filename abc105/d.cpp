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

void mod(vector<long long>& a, int m){
	for(auto& i : a) i %= m;
}

int main(){
	long long n, m;
	cin >> n >> m;

	vector<long long> a(n, 0);
	rep(i,n) cin >> a[i];

	rep(i,a.size() - 1) a[i + 1] += a[i];

	map<long long,long long> b;
	rep(i,a.size()) b[a[i] % m]++;

	long long ans = 0;
	for(auto i : b){
		ans += i.second * (i.second - 1) / 2;
	}
	cout << ans + b[0] << endl;
}
