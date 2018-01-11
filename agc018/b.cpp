#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int n, m;
int a[305][305];

bool usedAll(vector<bool> u){
	rep(i,u.size()){
		if(not u[i]) return false;
	}
	return true;
}

bool C(int mid){
	vector<int> p(n,0);
	vector<bool> u(m,0);
	rep(i,m){
		vector<int> cnt(m,0);
		//rep(i,m){ cout << u[i] << ' '; } cout << endl;
		if(usedAll(u)){
			return false;
		}

		rep(j,n){
			while(u[ a[j][ p[j] ] ]){
				p[j]++;
				if(p[j] >= m) return false;
			}
			cnt[ a[j][ p[j] ] ]++;
		}

		bool f = true;
		vector<int> tmp;
		rep(j,n){
			if(cnt[a[j][ p[j] ]] > mid){
				f = false;
				u[ a[j][p[j]] ] = true;
			}
		}
		if(f) return true;
	}
	return false;
}

int main(){
	cin >> n >> m;

	rep(i,n){
		rep(j,m){
			cin >> a[i][j];
			a[i][j]--;
		}
	}

	int right = n, left = 1;
	rep(i,100){
		int mid = (right + left ) / 2;
		if(C(mid)) right = mid;
		else left = mid;
	}
	cout << right << endl;
}
