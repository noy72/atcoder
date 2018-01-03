#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int h, w, k;

bool f(vector<vector<char>>& v){
	for(int i = 0; i < h; i+=2){
		for(int j = 0; j < w; j+=2){
			if(k == 0) return true;
			v[i][j] = '#';
			k--;
		}
	}
	if(k != 0) return false;
	return true;
}

int main(){
	cin >> h >> w >> k;

	vector<vector<char>> m(h, vector<char>(w,'.'));
	if(not f(m)){
		cout << "IMPOSSIBLE" << endl;
	}else{
		for(auto i : m){
			for(auto j : i){
				cout << j;
			}
			cout << endl;
		}
	}
}
