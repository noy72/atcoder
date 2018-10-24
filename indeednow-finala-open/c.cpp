#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	int t[101][101][101] = {{{0}}};
	rep(i,n){
		int a, b, c, w;
		cin >> a >> b >> c >> w;
		auto& p = t[a][b][c];
		p = max(p, w);
	}

	rep(i,101){
		rep(j,101){
			rep(k,101){
				int maxi = 0;
				if(i - 1 >= 0) maxi = max(maxi, t[i - 1][j][k]);
				if(j - 1 >= 0) maxi = max(maxi, t[i][j - 1][k]);
				if(k - 1 >= 0) maxi = max(maxi, t[i][j][k - 1]);
				t[i][j][k] = max(t[i][j][k], maxi);
			}
		}
	}

	rep(i,m){
		int x, y, z;
		cin >> x >> y >> z;

		cout << t[x][y][z] << endl;
	}
}
