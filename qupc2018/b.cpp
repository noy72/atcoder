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

bool solve(){
	long long a, b, c;
	cin >> a >> b >> c;
	a *= 100;
	b *= 10;

	long long d = a % 200;
	if(d <= b){
		b -= d;
		d = b % 20;
	}else{
		d -= b;
	}

	if(d > c or (c - d) % 2) return false;
	return true;
}

int main(){
	int q;
	cin >> q;
	while(q--){
		cout << (solve() ? "Yes" : "No") << endl;
	}
}
