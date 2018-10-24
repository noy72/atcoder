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

int solve(int a, int b, int c, vector<vector<int>>& d, vector<vector<int>> &m){
	int res = 0;
	rep(i,m.size()){
		rep(j,m.size()){
			if((i + j) % 3 == 0){
				res += d[m[i][j] - 1][a];
			}else if((i + j) % 3 == 1){
				res += d[m[i][j] - 1][b];
			}else{
				res += d[m[i][j] - 1][c];
			}
		}
	}
	return res;
}

int main(){
	int n, c;
	cin >> n >> c;

	vector<vector<int>> d(c, vector<int>(c));
	rep(i,c) rep(j,c) cin >> d[i][j];

	vector<vector<int>> m(n, vector<int>(n));
	rep(i,n) rep(j,n) cin >> m[i][j];

	int ans = INT_MAX;
	rep(i,c){
		rep(j,c){
			if(i == j) continue;
			rep(k,c){
				if(i == k or j == k) continue;
				//cout << i << ' ' << j << ' ' << k << endl;
				//show(solve(i,j,k,d,m))
				ans = min(ans, solve(i,j,k,d,m));
			}
		}
	}
	cout << ans << endl;
}
