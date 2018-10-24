#include<bits/stdc++.h>
#define range(i,a,b) for(long long i = (a); i < (b); i++)
#define rep(i,b) for(long long i = 0; i < (b); i++)
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

long long gcd(long long x, long long y) {
	long long r;
	if(x < y) swap(x, y);

	while(y > 0){
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

long long lcm( long long m, long long n ) {
	// 引数に０がある場合は０を返す
	if ( ( 0 == m ) || ( 0 == n ) ) return 0;
	return ((m / gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}

int main(){
	long long n, m;
	string s,t ;
	cin >> n >> m >> s >> t;

	if(s.front() != t.front()){
		cout << -1 << endl;
		return 0;
	}

	long long l = lcm(n, m);
	long long g = gcd(n, m);


	if([&]() -> bool{
		for(int i = 0, j = 0; i < n or j < m; i += n / g, j += m / g){
			if(s[i] != t[j]) return false;
		}
		return true;
		}()) cout << l << endl;
	else cout << -1 << endl;
}
