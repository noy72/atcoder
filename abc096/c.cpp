#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

const int dy[16] = { 0,-1, 0, 1, 1,-1, 1,-1, 0,-2, 0, 2};
const int dx[16] = { 1, 0,-1, 0, 1, 1,-1,-1, 2, 0,-2, 0};

bool check(char m[55][55], int y, int x){
	rep(d,4){
		int ny = y + dy[d];
		int nx = x + dx[d];
		if(m[ny][nx] == '#') return true;
	}
	return false;
}

int main(){
	int h, w;
	cin >> h >> w;

	char m[55][55];
	rep(i,h) rep(j,w) m[i][j] = '.';
	rep(i,h){
		rep(j,w){
			cin >> m[i + 1][j + 1];
		}
	}

	rep(i,h){
		rep(j,w){
			if(m[i][j] == '#'){
				if(not check(m, i, j)){
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}
	cout << "Yes" << endl;
}
