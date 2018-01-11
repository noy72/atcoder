#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

vector<int> g[100005];
vector<int> k[100005];
vector<int> chi(100005);
vector<int> chi_max(100005);

int dfs(int cur){
	int res = 1;
	for(auto to : g[cur]){
		int tmp = dfs(to);
		k[cur].emplace_back(tmp);
		res += tmp;
		chi_max[cur] = max(chi_max[cur], tmp);
	}
	if(k[cur].empty()){
		k[cur].emplace_back(-1);
	}
	return chi[cur] = res;
}

int main(){
	int n;
	cin >> n;
	rep(i,n - 1){
		int x;
		cin >> x;
		g[x].emplace_back(i + 1);
	}
	dfs(0);

	//rep(i,n){ for(auto j : k[i]){ cout << j << ' '; } cout << endl; }

	rep(i,n){
		cout << max(n - chi[i], chi_max[i]) << endl;
	}
}
