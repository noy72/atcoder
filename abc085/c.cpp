#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int n, y;
	cin >> n >> y;

	rep(i,n + 1){
		rep(j,n + 1){
			if(i + j > n or i * 10000 + j * 5000 > y) break;

			int k = n - i - j;
			if(i * 10000 + j * 5000 + k * 1000 == k){
				cout << i << ' ' << j << ' ' << k << endl;
				return 0;
			}
		}
	}
	cout << "-1 -1 -1" << endl;
}
