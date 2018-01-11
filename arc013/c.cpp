#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int n;
	cin >> n;

	int ans = 0;
	rep(i,n){
		int x, y, z;
		cin >> x >> y >> z;

		int xmin, xmax, ymin, ymax, zmin, zmax;
		xmin = ymin = zmin = 1e9 + 5;
		xmax = ymax = zmax = 0;

		int m;
		cin >> m;
		rep(j,m){
			int a, b, c;
			cin >> a >> b >> c;
			xmin = min(xmin, a);
			xmax = max(xmax, a);
			ymin = min(ymin, b);
			ymax = max(ymax, b);
			zmin = min(zmin, c);
			zmax = max(zmax, c);
		}
		if(x - xmax - 1 > 0) ans ^= x - xmax - 1;
		ans ^= xmin - 0;
		if(y - ymax - 1 > 0) ans ^= y - ymax - 1;
		ans ^= ymin - 0;
		if(z - zmax - 1 > 0) ans ^= z - zmax - 1;
		ans ^= zmin - 0;
	}
	cout << (ans != 0 ? "WIN" : "LOSE") << endl;
}
