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


int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};

void bfs(int h, int w, int x, vector<pair<int, int>>& b, vector<vector<char>>& m){
	vector<vector<int>> dis(m.size(), vector<int>(m[0].size(), 0));
	typedef tuple<int,int,int> T;
	priority_queue<T> q;

	for(auto p : b){
		dis[p.first][p.second] = x;
		q.emplace(make_tuple(x, p.first, p.second));
	}

	while(not q.empty()){
		int c, y, x;
		tie(c, y, x) = q.top(); q.pop();
		if(c == 0) continue;
		if(m[y][x] == '#') continue;
		m[y][x] = '#';
		dis[y][x] = c;

		rep(i,4){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
			if(m[ny][nx] == '#' or dis[ny][nx] > c - 1) continue;
			q.emplace(make_tuple(c, ny, nx));
		}
	}
}

const int INF = 1e8;

int bfs(int h, int w, pair<int, int> s, pair<int, int> g, vector<vector<char>>& m){
	vector<vector<int>> dis(m.size(), vector<int>(m[0].size(), INF));
	typedef tuple<int ,int, int> T;
	queue<T> q;
	q.emplace(make_tuple(0, s.first, s.second));

	while(not q.empty()){
		int c, y, x;
		tie(c, y, x) = q.front(); q.pop();
		if(make_pair(y,x) == g) return c;
		if(dis[y][x] != INF) continue;
		dis[y][x] = c;

		rep(i,4){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
			if(m[ny][nx] == '#' or dis[ny][nx] < c + 1) continue;
			q.emplace(c + 1, ny, nx);
		}
	}
	return -1;
}

int main(){
	int h, w, x;
	cin >> h >> w >> x;

	vector<vector<char>> m(h, vector<char>(w));
	vector<pair<int, int>> b;
	pair<int, int> s, g;
	rep(i,h){
		rep(j,w){
			cin >> m[i][j];
			if(m[i][j] == '@') b.emplace_back(i,j);
			if(m[i][j] == 'S') s = make_pair(i,j);
			if(m[i][j] == 'G') g = make_pair(i,j);
		}
	}

	bfs(h, w, x, b, m);
	cout << bfs(h, w, s, g, m) << endl;
}
