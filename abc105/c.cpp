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

void dfs(vector<long long>& a, int pos, long long num){
	if(pos > 32){
		a.emplace_back(num);
		return;
	}

	dfs(a, pos + 2, num + (1LL << pos));
	dfs(a, pos + 2, num);
}

int main(){
	long long n;
	cin >> n;

	if(n == 0){
		cout << 0 << endl;
		return 0;
	}

	vector<long long> a, b;
	dfs(a, 0, 0);
	dfs(b, 1, 0);
	sort(all(b));


	rep(i,a.size()){
		long long t = n - a[i];

		auto it = lower_bound(all(b), -t);
		if(it == b.end() or *it != -t) continue;

		long long ans = a[i] bitor *it;

		string s;
		while(ans != 0){
			s += '0' + ans % 2;
			ans /= 2;
		}
		reverse(all(s));
		cout << s << endl;
		return 0;
	}
	assert(false);
}
