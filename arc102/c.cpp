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

long long iceil(long long a, long long b){
	return a / b + (a % b == 0 ? 0 : 1);
}

int main(){
	long long n, k;
	cin >> n >> k;

	if(k % 2){
		long long a = n / k;
		cout << a * a * a << endl;
	}else{
		long long a = n / k;
		long long b = (n - k / 2) / k + 1;
		if(n < k / 2) b = 0;
		cout << a * a * a + b * b * b << endl;
	}
}
