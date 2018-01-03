#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const int dy[16] = { 0,-1, 0, 1, 1,-1, 1,-1, 0,-2, 0, 2};
const int dx[16] = { 1, 0,-1, 0, 1, 1,-1,-1, 2, 0,-2, 0};

int H = 19;
int W = 19;

bool dfs(int y, int x, int& dir, char& t, vector<vector<char>>& m, int cnt){
	if(m[y][x] != t) return false;
	cnt++;
	if(cnt == 5) return true;

	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if(ny < 0 || ny >= H || nx < 0 || nx >= W) return false;
	return dfs(ny, nx, dir, t, m, cnt);
}

bool finished(vector<vector<char>>& m){
	bool finish = false;
	rep(i,H){
		rep(j,W){
			rep(k,8){
				char o = 'o';
				char x = 'x';
				finish = finish or dfs(i,j,k,o,m,0);
				finish = finish or dfs(i,j,k,x,m,0);
			}
		}
	}
	return finish;
}

int main(){
	vector<vector<char>> m(H, vector<char>(W));

	int b = 0, w = 0;
	rep(i,H){
		rep(j,W){
			cin >> m[i][j];
			if(m[i][j] == 'o') b++;
			else if(m[i][j] == 'x') w++;
		}
	}

	if(b != w and b - 1 != w){
		cout << "NO" << endl;
		return 0;
	}

	if(b == 0 and w == 0){
		cout << "YES" << endl;
		return 0;
	}

	bool ans = true;
	char take = b == w ? 'x' : 'o';
	rep(i,H){
		rep(j,W){
			if(m[i][j] == take){
				m[i][j] = '.';
				if(not finished(m)) ans = false;
				m[i][j] = take;
			}
		}
	}

	cout << (not ans ? "YES" : "NO") << endl;
}
