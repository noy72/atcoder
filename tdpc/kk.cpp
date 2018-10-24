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

int LIS(int n, vector<int>& a){
	vector<int> dp(n,1e9);
	rep(i,n){
		*lower_bound(all(dp), a[i]) = a[i];
	}
	return lower_bound(all(dp), 1e9) - dp.begin();
}

int main(){
	int n;
	cin >> n;

	vector<pair<int, int>> p(n);
	rep(i,n){
		int x, r;
		cin >> x >> r;
		p[i] = make_pair(x - r, x + r);
	}
	sort(all(p), greater<pair<int, int>>());

	vector<int> a(n);
	rep(i,n){
		a[i] = p[i].second;
	}
	//for(auto i : a){ cout << i << endl; }

	cout << LIS(n, a) << endl;
}
