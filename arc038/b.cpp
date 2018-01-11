#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
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

const int dy[16] = { 1, 1, 0, 1, 1,-1, 1,-1, 0,-2, 0, 2};
const int dx[16] = { 1, 0, 1, 0, 1, 1,-1,-1, 2, 0,-2, 0};
int h, w;
vector<string> m;

vector<vector<int>> memo;
int dfs(int x, int y){
	if(memo[y][x] != -1) return memo[y][x];
	set<int> s;
	rep(i,3){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		if(m[ny][nx] == '#') continue;
		s.emplace(dfs(nx, ny));
	}
	
	int res = 0;
	while(s.count(res)) res++;
	return memo[y][x] = res;
}

int main(){
	cin >> h >> w;
	m = vector<string>(h);
	memo = vectors(h,w,-1);

	rep(i,h) cin >> m[i];
	if(dfs(0,0)) cout << "First" << endl;
	else cout << "Second" << endl;
}
