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

int memo[1000][1001];
vector<int> a;
int dfs(int l, int r, int k){
	if(l >= r) return 0;

	int sum = 0;
	range(i,l,r){
		sum += a[i];
	}
	int f = 1;
	range(i,1,k + 1) f *= i;

	int res = f * sum;
	res += dfs(l + 1, r, k - 1);
	res += dfs(l, r - 1, k - 1);
	range(i,l + 1,r - 1){
		res += (dfs(l, i,k - 1) + dfs(i + 1, r,k - 1)) * 2;
	}
	return memo[l][r] = res;
}

int main(){
	int n;
	cin >> n;

	assert(n < 100);

	a = vector<int>(n);
	cin >> a;

	dfs(0, n, n);
	cout << memo[0][n] << endl;
	range(len,1,5){
		rep(i,n - len + 1){
			show(memo[i][i + len])
		}
	}
	show(memo[0][1])
	show(memo[0][2])
	show(memo[0][3])
	show(memo[0][4])
}
