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

char m[20][20];
bool used[20][20];
string ans;

void dfs(int y, int x, string s){
	if(used[y][x] or m[y][x] == 'x') return;
	if(y == 1){
		ans = s;
		return;
	}
	used[y][x] = true;
	dfs(y - 1, x + 1, s + 'R');
	dfs(y - 1, x    , s + 'S');
	dfs(y - 1, x - 1, s + 'L');
}

int main(){
	int h, w;
	cin >> h >> w;

	rep(i,20) rep(j,20) m[i][j] = 'x';
	rep(i,h) rep(j,w) cin >> m[i + 1][j + 1];

	int s;
	rep(i,w + 2) if(m[h][i] == 's') s = i;

	memset(used, false, sizeof(used));
	ans = "impossible";

	dfs(h, s, string());
	cout << ans << endl;
}
