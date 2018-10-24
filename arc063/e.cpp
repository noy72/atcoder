#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template <typename X, typename T>
auto vectors(X x, T a) {
	return vector<T>(x, a);
}

template <typename X, typename Y, typename Z, typename... Zs>
auto vectors(X x, Y y, Z z, Zs... zs) {
	auto cont = vectors(y, z, zs...);
	return vector<decltype(cont)>(x, cont);
}

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

const int INF = 1e8;

vector<int> g[100000];
int low[100000], high[100000];

bool impossible;
void __dfs(int cur, int pre, int num){
	if(high[cur] != INF and high[cur] % 2 != num % 2){
		impossible = true;
		return;
	}

	for(auto to : g[cur]){
		if(to == pre) continue;
		__dfs(to, cur, num + 1);
	}
}

void dfs(int cur, int pre){
	for(auto to : g[cur]){
		if(to == pre) continue;

		dfs(to, cur);
		high[cur] = min(high[cur], high[to] + 1);
		low[cur] = max(low[cur], low[to] - 1);
	}
}

void _dfs(int cur, int pre){
	for(auto to : g[cur]){
		if(to == pre) continue;
		high[to] = min(high[to], high[cur] + 1);
		low[to] = max(low[to], low[cur] - 1);
		_dfs(to, cur);
	}
}

int main(){
	fill(low, low + 100000, -INF);
	fill(high, high + 100000, INF);

	int n;
	cin >> n;

	rep(i,n - 1){
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	int k;
	cin >> k;

	int s;
	rep(i,k){
		int V, p;
		cin >> V >> p;
		V--;
		low[V] = high[V] = p;
		s = V;
	}

	dfs(s, -1);
	_dfs(s, -1);
	__dfs(s, -1, high[s]);

	if(impossible){
		cout << "No" << endl;
		return 0;
	}

	rep(i,n){
		if(high[i] < low[i]){
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
	rep(i,n){
		cout << high[i] << endl;
	}
}
