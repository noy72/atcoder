#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const int dy[16] = {-2,-2,-1,-1,1,1,2,2};
const int dx[16] = {-1,1,-2,2,-2,2,-1,1};

int main(){
	char m[10][10];
	rep(i,9) cin >> m[i];

	bool ans = true;
	rep(i,9){
		rep(j,9){
			rep(k,8){
				int ny = i + dy[k];
				int nx = j + dx[k];
				if(ny < 0 || ny >= 9 || nx < 0 || nx >= 9) continue;
				if(m[i][j] == m[i + dy[k]][j + dx[k]]) ans = false;
			}
		}
	}

	rep(i,9){
		set<char> s;
		rep(j,9){
			s.emplace(m[i][j]);
		}
		if(s.size() != 9) ans = false;
	}

	rep(i,9){
		set<char> s;
		rep(j,9){
			s.emplace(m[j][i]);
		}
		if(s.size() != 9) ans = false;
	}

	cout << (ans ? "Yes" : "No") << endl;
}
