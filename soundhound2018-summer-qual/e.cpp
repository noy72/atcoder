#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

vector<vector<pair<int, int>>> g;
vector<vector<int>> num;
// plus 1 +, 0 -

bool impossible;
void dfs(int pos, int sum, bool plus, vector<bool>& used){
	if(impossible) return;

	auto& p = num[pos][plus];
	if(p != -1){
		if(p != sum){
			impossible = true;
		}
		return;
	}
	p = sum;

	used[pos] = true;
	for(auto e : g[pos]){
		if(impossible) return;
		if(used[e.first]) continue;
		dfs(e.first, e.second - sum, plus ^ 1, used);
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	g = vector<vector<pair<int, int>>>(n);
	rep(i,m){
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		g[a].emplace_back(b,c);
		g[b].emplace_back(a,c);
	}

	num = vector<vector<int>>(n, vector<int>(2, -1));
	vector<bool> used(n, false);
	impossible = false;
	dfs(0, 0, 1, used);

	if(impossible){
		cout << 0 << endl;
		return 0;
	}

	vector<pair<int, int>> mm(n);
	rep(i,n){
		mm[i] = make_pair(1,1e9);
		auto& maxi = mm[i].second;
		for(auto e : g[i]){
			maxi = min(maxi, e.second - 1);
		}
	}

	//rep(i,n){
	//		cout << num[i][0] << ' ' << num[i][1] << endl;
	//}

	int &rmin = mm[0].first, &rmax = mm[0].second;
	rep(i,n){
		if(i == 0) continue;

		auto& mini = mm[i].first;
		auto& maxi = mm[i].second;
		if(num[i][0] != -1){
			rmin = max(rmin, max(0, num[i][0] - maxi));
			rmax = min(rmax, max(0, num[i][0] - mini));
		}
		if(num[i][1] != -1){
			rmin = max(rmin, max(0, num[i][1] + maxi));
			rmax = min(rmax, max(0, num[i][1] + mini));
		}
	}

	cout << max(0, rmax - rmin + 1) << endl;
}
