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

const long long M = 1000000007;

class Combination{
public:
	vector<long long> fact, rev;
	Combination(int n = 200005) : fact(n), rev(n) { // n = h + w
		fact[0] = fact[1] = 1;
		range(i,2,n){
			(fact[i] = fact[i - 1] * i) %= M;
		}
		rev[n - 1] = power(fact[n - 1], M - 2) % M;
		for (int i = n - 1; i > 0; i--) {
			rev[i - 1] = rev[i] * i % M;
		}
	}
	long long power(long long x, long long n){ //べき乗 x^n mod M
		long long res = 1;
		if(n > 0){
			res = power(x, n / 2);
			if(n % 2 == 0) res = (res * res) % M;
			else res = (((res * res) % M) * x ) % M;
		}
		return res;
	}
	long long factorial(long long l, long long r){ return fact[r] * rev[l - 1] % M; }
	long long factorial(long long n){ return fact[n]; }
	long long combination(long long n, long long r){ //nCr (1,1)から(w,h)だと、引数は(w - 1, h - 1, M)
		return factorial(n - r + 1, n) * rev[r] % M;
	}
};

map<int, int> primeFactor(int n){
	map<int, int> res;
	for(int i = 2; i * i <= n; i++){
		while(n % i == 0){
			++res[i];
			n /= i;
		}
	}
	if(n != 1) res[n] = 1;
	return res;
}

int main(){
	long long n, m;
	cin >> n >> m;

	long long ans = 1;
	Combination com;
	for(auto p : primeFactor(m)){
		(ans *= com.combination(n + p.second - 1, n - 1)) %= M;
	}
	cout << ans << endl;
}
