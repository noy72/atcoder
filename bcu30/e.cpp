#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int m[3000][3000];
const int b = 1500;

const int dy[16] = { 0,-1, 0, 1, 1,-1, 1,-1, 0,-2, 0, 2};
const int dx[16] = { 1, 0,-1, 0, 1, 1,-1,-1, 2, 0,-2, 0};

void bfs(int n, int y, int x, int c){
	queue<pair<int, int>> q;
	q.push(make_pair(y,x));
	m[y][x] = c;

	while(not q.empty()){
		pair<int, int> u = q.front(); q.pop();
		rep(i,4){
			int ny = u.first + dy[i];
			int nx = u.second + dx[i];
			if(ny < b || ny >= n + b || nx < b || nx >= n + b) continue;
			if(m[ny][nx] == 0){
				m[ny][nx] = c;
				q.push(make_pair(ny,nx));
			}
		}
	}
}

int main(){
	int n, k, q;
	cin >> n >> k >> q;

	int l = b - (k - 1);
	int u = b + 1;
	//cout << l << ' ' << u << endl;
	rep(i,n){
		rep(j,n){
			char c;
			cin >> c;
			if(c == '#'){ //累積和の準備
				m[i + l][j + l]++;
				m[i + u][j + u]++;
				m[i + u][j + l]--;
				m[i + l][j + u]--;
			}
		}
	}
	//rep(i,n + 1){ rep(j,n + 1){ cout << m[i + b][j + b]; } cout << endl; }

	range(i,1,3000){
		rep(j,3000){
			m[j][i] += m[j][i - 1];
		}
	}

	range(j,1,3000){
		rep(i,3000){
			m[j][i] += m[j - 1][i];
		}
	}

	//rep(i,n + 1){ rep(j,n + 1){ cout << m[i + b][j + b]; } cout << endl; }

	int t =  -1;
	rep(i,n - k + 1){
		rep(j, n - k + 1){
			if(m[i + b][j + b] == 0){
				bfs(n - k + 1, i + b, j + b, t);
				t--;
			}
		}
	}
	//rep(i,n + 1){ rep(j,n + 1){ cout << m[i + b][j + b]; } cout << endl; }

	rep(i,q){
		int lx, ly, rx, ry;
		cin >> ly >> lx >> ry >> rx;
		//cout <<  m[ly - 1 + b][lx - 1 + b] << ' ' << m[ry - 1 + b][rx - 1 + b] << endl;

		bool f = m[ly - 1 + b][lx - 1 + b] == m[ry - 1 + b][rx - 1 + b];
		cout << (f ? "Yes" : "No") << endl;
	}
}
