#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

#define int long long

const int gmax_n = 100005;

int par[gmax_n]; //親
int depth[gmax_n];//木の深さ

void init(int n){
	rep(i,n){
		par[i] = i;
		depth[i] = 0;
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
	}else{
		par[y] = x;
		if(depth[x] == depth[y]) depth[x]++;
	}
}

bool same(int x, int y){
	return find(x) == find(y);
}

signed main(){
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> p;

	init(n);
	rep(i,m){
		int a, b;
		cin >> a >> b;
		a--; b--;
		unite(a,b);
		p.emplace_back(a,b);
	}

	int a = 0, b = 0;
	vector<int> alone;
	rep(i,n){
		if(same(0,i)){
			a++;
		}else if(same(1,i)){
			b++;
		}else{
			alone.emplace_back(i);
		}
	}

	if(a >= b){
		a += alone.size();
		for(auto i : alone){
			unite(0,i);
		}
	}else{
		b += alone.size();
		for(auto i : alone){
			unite(1,i);
		}
	}

	cout << a * (a - 1) / 2 + b * (b - 1) / 2 - m << endl;
}
