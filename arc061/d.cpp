#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

map<pair<int, int>, int> m;

int main(){
	long long h, w, n;
	cin >> h >> w >> n;

	rep(i,n){
		int x, y;
		cin >> y >> x;
		x--; y--;
		rep(i,3){
			rep(j,3){
				m[make_pair(x - i, y - j)]++;
			}
		}
	}

	vector<long long> ans(10,0);
	for(auto i : m){
		pair<int, int> c;
		int b;
		tie(c,b) = i;

		if(c.first < 0 or c.second < 0 or c.first >= w - 2 or c.second >= h - 2) continue;
		ans[b]++;
	}

	ans[0] = (w - 2) * (h - 2) - accumulate(all(ans),0LL);
	for(auto i : ans){
		cout << i << endl;
	}
}
