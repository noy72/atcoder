#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;
#define int long long
const int INF = (1LL << 60);

int	func(vector<int>& v){ //一行埋めるためのコスト
	vector<int> d(v.size() - 1);
	rep(i,v.size() - 1){
		d[i] = v[i + 1] - v[i];
		if(d[i] > 0) d[i]--;
	}

	//方向があるから誤解法
	int maxi = *max_element(next(d.begin(), 1), prev(d.end(), 1));
	return min(max(maxi, d.front()) + d.back(), max(maxi, d.back()) + d.front());
}

signed main(){
	int h, w, n;
	cin >> h >> w >> n;

	map<int,vector<int>> m;
	rep(i,n){
		int x, y;
		cin >> y >> x;
		x--; y--;
		m[y].emplace_back(x);
	}
	for(auto& i : m){
		i.second.emplace_back(-1);
		i.second.emplace_back(w);
		sort(all(i.second));
	}

	vector<pair<int,int>> v; //一行埋めるためのコスト、埋まるy座標
	for(auto& i : m){
		v.emplace_back(func(i.second), i.first);
	}
	sort(all(v));

	int ans = INF;
	vector<int> ver = {-1, h}; //埋まっているy座標
	rep(i,v.size()){
		ver.emplace_back(v[i].second);
		sort(all(ver));
		ans = min(ans, v[i].first + func(ver));
	}
	cout << ans << endl;
}
