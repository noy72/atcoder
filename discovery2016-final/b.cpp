#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

#define int long long
const int INF = (1LL << 60);

map<int,vector<int>> input(int n){
	vector<int> t(n), a(n);
	rep(i,n){
		cin >> t[i];
	}
	rep(i,n){
		cin >> a[i];
	}

	map<int,vector<int>> res;
	rep(i,n){
		res[t[i]].emplace_back(a[i]);
	}
	return res;
}

signed main(){
	int n, x;
	cin >> n >> x;

	map<int,vector<int>> m = input(n);

	int sum = 0;
	int ans = INF;
	priority_queue<int, vector<int>, greater<int>> q;
	for(auto& i : m){
		for(auto& j : i.second){
			sum += j;
			q.push(j);
		}
		while(i.first < q.size()){
			sum -= q.top();
			q.pop();
		}
		while(sum - q.top() >= x){
			sum -= q.top();
			q.pop();
		}
		if(x <= sum){
			ans = min<int>(ans, q.size());
		}
	}
	cout << (ans == INF ? -1 : ans) << endl;
}
