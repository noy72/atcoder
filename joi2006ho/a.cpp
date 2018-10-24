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

	vector<pair<int, int>> v(m);
	rep(i,m) v[i] = make_pair(0,-i - 1);
	rep(i,n){
		rep(j,m){
			bool a;
			cin >> a;
			if(a){
				v[j].first++;
			}
		}
	}
	sort(all(v), greater<pair<int, int>>());
	rep(i,v.size()){
		if(i) cout << ' ' ;
		cout << -v[i].second;
	}
	cout << endl;
}
