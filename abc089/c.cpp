#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

string s = "MARCH";
map<char, long long> m;
long long ans = 0;

void dfs(vector<int> p){
	if(p.size() == 3){
		ans += m[s[p[0]]] * m[s[p[1]]] * m[s[p[2]]];
		return;
	}

	rep(i,5){
		if(not p.empty() and i <= p.back()) continue;
		p.emplace_back(i);
		dfs(p);
		p.pop_back();
	}
}

int main(){
	int n;
	cin >> n;
	rep(i,n){
		string t;
		cin >> t;
		m[t[0]]++;
	}

	dfs(vector<int>());
	cout << ans << endl;
}
