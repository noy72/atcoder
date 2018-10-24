#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

#define int long long

signed main(){
	int n;
	cin >> n;

	vector<int> a(n);
	cin >> a;

	sort(all(a), greater<int>());

	vector<vector<int>> v(n);
	rep(i,n){
		rep(j,n){
			if(v[j].empty() or v[j].back() % a[i] == 0){
				v[j].emplace_back(a[i]);
				break;
			}
		}
	}

	int ans = 0;
	rep(i,n){
		if(v[i].empty()) break;
		int k = v[i].front() - 1;
		rep(j,v[i].size()){
			ans += k % v[i][j];
		}
	}
	cout << ans << endl;
}
