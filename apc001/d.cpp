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

	vector< priority_queue<int, vector<int>, greater<int>>  > v(n);
	map<int,int> t;
	rep(i,n){
		t[find(i)] = 1;
		v[ find(i) ].emplace(a[i]);
	}

	int cnt = (t.size() - 1) * 2;
	long long sum = 0;
	rep(i,n){
		if(cnt == 0) break;
		if(v[i].empty()) continue;
		sum += v[i].top();
		v[i].pop();
		cnt--;
	}

	priority_queue<int, vector<int>, greater<int>> al;
	rep(i,n){
		while(not v[i].empty()){
			al.emplace(v[i].top());
			v[i].pop();
		}
	}

	rep(i,cnt){
		if(al.empty()){
			cout << "Impossible" << endl;
			return 0;
		}
		sum += al.top();
		al.pop();
	}
	cout << sum << endl;

	/*
	set<int> s;
	rep(i,n){
		s.emplace(find(i));
	}

	vector<priority_queue<long long>> q(s.size());
	rep(i,n){
		int t = distance(s.begin(), s.lower_bound(find(i)));
		q[t].push(a[i]);
	}

	if(s.size() == 1){
		cout << 0 << endl;
		return 0;
	}

	int need = (s.size() - 1) * 2;
	if(need > n){
		cout << "Impossible" << endl;
		return 0;
	}

	vector<long long> v;
	for(auto& i : q){
		while(i.size() > 1){
			v.emplace_back(i.top());
			i.pop();
		}
	}
	sort(all(v), greater<long long>());
	cout << accumulate(all(a),0LL) - accumulate(v.begin(), next(v.begin(), n - need), 0LL) << endl;
	*/
}
