#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int dis(pair<int, int> x, pair<int, int> y){
	int a, b, c, d;
	tie(a,b) = x;
	tie(c,d) = y;
	return abs(a - c) + abs(b - d);
}

int main(){
	int h, w, d;
	cin >> h >> w >> d;

	vector<pair<int, int>> p(h * w);
	rep(i,h){
		rep(j,w){
			int a;
			cin >> a;
			p[a - 1] = make_pair(i,j);
		}
	}

	vector<vector<int>> a(h * w);
	rep(i,d){
		a[i].emplace_back(0);
		for (int j = i; j < h * w - d; j+=d) {
			a[i].emplace_back(dis(p[j], p[j + d]));
		}
	}

	rep(i,d){
		rep(j,a[i].size() - 1){
			a[i][j + 1] += a[i][j];
		}
	}

	int q;
	cin >> q;
	rep(i,q){
		int l, r;
		cin >> l >> r;
		l--; r--;
		//show(a[l % d][r / d]);
		cout << a[l % d][r / d] - a[l % d][l / d] << endl;
	}
}
