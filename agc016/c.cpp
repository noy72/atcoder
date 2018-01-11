#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

/*
 * 1  1  1  1
 * 1  1 -6  1
 * 1  1  1  1
 *
 */

int main(){
	int H, W, h, w;
	cin >> H >> W >> h >> w;

	int i = 0, j = 0;
	int a[700][700];
	while(i < 600){
		while(j < 600){
			//cout << i << ' ' << j << endl;
			rep(k,h){
				if(i + k >= 600) break;
				rep(l,w){
					if(j + l >= 600) break;
					if(k == h - 1 && l == w - 1) a[i + k][j + l] = -((h * w - 1) * 4000 + 1);
					else a[i + k][j + l] = 4000;
				}
			}
			j+=w;
		}
		j = 0;
		i+=h;
	}

	long long sum = 0;
	rep(i,H){
		rep(j,W){
			sum += a[i][j];
		}
	}

	if(sum < 0){
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	rep(i,H){
		rep(j,W){
			if(j) cout << ' ';
			cout << a[i][j];
		}
		cout << endl;
	}
}
