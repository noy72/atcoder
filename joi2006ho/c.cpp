#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

void dfs(int n, vector<int> v, int pre){
	if(n == 0){
		rep(i,v.size()){
			if(i) cout << ' ';
			cout << v[i];
		}
		cout << endl;
		return;
	}

	for(int i = min(n,pre); i > 0; i--){
		v.emplace_back(i);
		dfs(n - i, v, i);
		v.pop_back();
	}
}

int main(){
	int n;
	cin >> n;

	dfs(n, vector<int>(), n);
}
