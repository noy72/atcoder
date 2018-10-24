#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

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

int main(){
	int n, m;
	cin >> n >> m;

	vector<long long> a(n);
	rep(i,n){
		cin >> a[i];
	}

	init(n);
	rep(i,m){
		int a, b;
		cin >> a >> b;
		unite(a,b);
	}

	static vector<vector<long long>> q(100000);
	rep(i,n){
		q[find(i)].emplace_back(a[i]);
	}

	vector<long long> v;
	long long must = 0;
	int tree = 0;
	rep(i,100000){
		if(q[i].empty()) continue;
		tree++;

		sort(all(q[i]));
		must+=q[i].front();
		range(j,1,q[i].size()) v.emplace_back(q[i]);
	}

	if(tree == 1){
		cout << 0 << endl;
		return 0;
	}

	int need = (tree - 1) * 2;
	if(need > n){
		cout << "Impossible" << endl;
		return 0;
	}

	sort(all(v));
	cout << must + accumulate(v.begin(), next(v.begin(), need - tree), 0LL) << endl;
}
