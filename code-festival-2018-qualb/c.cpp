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

int dx[] = {0,1,2,3};
int dy[] = {2,0,3,1};

int main(){
	int n;
	cin >> n;

	char m[1200][1200];
	rep(i,1200) rep(j,1200) m[i][j] = 'o';

	for(int i = 0; i < n; i+=5){
		for(int j = 1; j < n; j+=5){
			m[i][j] = 'X';
		}
	}
	for(int i = 1; i < n; i+=5){
		for(int j = 3; j < n; j+=5){
			m[i][j] = 'X';
		}
	}
	for(int i = 2; i < n; i+=5){
		for(int j = 0; j < n; j+=5){
			m[i][j] = 'X';
		}
	}
	for(int i = 3; i < n; i+=5){
		for(int j = 2; j < n; j+=5){
			m[i][j] = 'X';
		}
	}
	for(int i = 4; i < n; i+=5){
		for(int j = 4; j < n; j+=5){
			m[i][j] = 'X';
		}
	}

	//rep(i,n){
	//	if(m[i][n] == 'X') m[i][n - 1] = 'X';
	//	if(m[n][i] == 'X') m[n - 1][i] = 'X';
	//}

	//for(int i = 4; i < n; i+=5){
	//	m[i][n - 1] = 'X';
	//	m[n - 1][i] = 'X';
	//	m[i][0] = 'X';
	//	m[0][i] = 'X';
	//}

	int cnt = 0;

	const int dy[16] = { 0,-1, 0, 1, 1,-1, 1,-1, 0,-2, 0, 2};
	const int dx[16] = { 1, 0,-1, 0, 1, 1,-1,-1, 2, 0,-2, 0};
	rep(i,n){
		rep(j,n){
			if(m[i][j] == 'X'){
				cnt++;
				rep(d,4){
					int ny = i + dy[d];
					int nx = j + dx[d];
					if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
					m[ny][nx] = '.';
				}
			}
		}
	}
	rep(i,n){
		rep(j,n){
			if(m[i][j] == 'o'){
				cnt++;
				m[i][j] = 'X';
			}
		}
	}
	//cout << cnt << endl;
	//return 0;
	rep(i,n){
		rep(j,n){
			cout << m[i][j];
		}
		cout << endl;
	}
}
