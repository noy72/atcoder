#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const int dy[16] = { 0,-1, 0, 1, 1,-1, 1,-1, 0,-2, 0, 2};
const int dx[16] = { 1, 0,-1, 0, 1, 1,-1,-1, 2, 0,-2, 0};

void dfs(int y, int x, char t, vector<vector<char>>& m, vector<vector<bool>>& u){
	u[y][x] = true;
	rep(d,4){
		int ny = y + dy[d];
		int nx = x + dx[d];
		if(ny < 0 || ny >= 100 || nx < 0 || nx >= 100) continue;
		if(u[ny][nx] or m[ny][nx] != t) continue;
		dfs(ny, nx, t, m, u);
	}
}

void deleteWhite(vector<vector<char>>& m, int k){
	for(int i = 1; i < 100 - 4; i+=4){
		for(int j = 1; j < 100 - 4; j+=4){
			k--;
			m[i + 1][j + 1] = '#';
			if(k == 0) return;
		}
	}
}

void deleteBlack(vector<vector<char>>& m, int k){
	int y = 4;
	while(y < 100 - 4){
		k--;
		m[y][2] = '#';
		if(k == 0) return;
		y += 4;
	}

	for(int i = 2; i < 100 - 4; i += 4){
		for(int j = 4; j < 100 - 4; j += 4){
			k--;
			m[i][j] = '#';
			if(k == 0) return;
		}
	}
}

int main(){
	int a, b;
	cin >> a >> b;

	vector<vector<char>> m = vector<vector<char>>(100, vector<char>(100, '.'));
	int cnt = 0;
	for(int i = 1; i < 100 - 4; i+=4){
		for(int j = 1; j < 100 - 4; j+=4){
			cnt++;
			rep(k,3){
				rep(l,3){
					if(not (k == 1 and l == 1)){
						m[i + k][j + l] = '#';
					}
				}
			}
		}
	}

	deleteWhite(m, 577 - a);
	deleteBlack(m, 576 - b);

	vector<vector<bool>> u(100, vector<bool>(100,0));
	int B = 0, W = 0;
	rep(i,100){
		rep(j,100){
			if(u[i][j] == 0){
				if(m[i][j] == '.') W++;
				else B++;
				dfs(i, j, m[i][j], m, u);
			}
		}
	}
	//show(W) show(B)

	cout << 100 << ' ' << 100 << endl;
	range(i,0,100){ range(j,0,100){ cout << m[i][j]; } cout << endl; }
}
