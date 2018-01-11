#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e9 + 7;
using namespace std;

int main(){
	int n;
	cin >> n;

	vector<long long> a(n), ans(n,0);
	map<long long,vector<long long>> m;
	rep(i,n){
		cin >> a[i];
		m[a[i]].emplace_back(i);
	}
	m[0].emplace_back(-1);

	long long cur = INF; //加算される対象
	long long num = 0; //今処理している値と同じ数値を持つ要素の個数
	for(auto it = m.rbegin(); it->first != 0; it++){
		num += it->second.size();
		cur = min(cur, it->second.front());

		long long dif = it->first - (*next(it,1)).first;
		ans[cur] += num * dif;
	}

	for(auto i : ans){
		cout << i << endl;
	}
}
