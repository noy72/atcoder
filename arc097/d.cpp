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

class UnionFind{
	private:
		vector<int> par, depth;
	public:
		vector<int> cnt; // その集合の頂点数
		UnionFind() {}
		UnionFind(int n){
			init(n);
		}
		void init(int n){
			par = vector<int>(n);
			depth = vector<int>(n, 0);
			cnt = vector<int>(n, 1);
			rep(i,n){
				par[i] = i;
			}
		}
		int find(int x){
			if(par[x] == x){
				return x;
			}else {
				return par[x] = find(par[x]);
			}
		}
		void unite(int x, int y){
			x = find(x);
			y = find(y);
			if(x == y) return;

			if(depth[x] < depth[y]){
				par[x] = y;
				cnt[y] += cnt[x];
			}else{
				par[y] = x;
				cnt[x] += cnt[y];
				if(depth[x] == depth[y]) depth[x]++;
			}
		}
		bool same(int x, int y){
			return find(x) == find(y);
		}
};

int main(){
	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	cin >> a;
	for(auto &i: a) i--;

	UnionFind uni(n);
	rep(i,m){
		int x, y;
		cin >> x >> y;
		x--; y--;
		uni.unite(x,y);
	}

	map<int,vector<int>> mpp;
	rep(i,n){
		mpp[uni.find(i)].emplace_back(i);
	}

	int ans = 0;
	for(auto i : mpp){
		set<int> s;
		for(auto j : i.second){
			s.emplace(a[j]);
		}
		for(auto j : i.second){
			if(s.count(j)) ans++;
		}
	}
	cout << ans << endl;
}
