#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

vector<int> p = {25,39,51,76,163,111,136,128,133,138};
vector<int> v;

void dfs(int i, int sum){
	if(i == 10){
		v.emplace_back(sum);
		return;
	}

	if(i == 9){
		dfs(i + 1, sum + 58);
	}
	dfs(i + 1, sum);
	dfs(i + 1, sum + p[i]);
}

void compress(vector<int> &v) {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
}

int lb(vector<int>& v, int num){
	return lower_bound(all(v), num) - v.begin();
}

int main(){
	dfs(0,0);
	compress(v);
	for(auto i : v){
		cout << i << endl;
	}
}
