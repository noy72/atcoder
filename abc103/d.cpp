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

int main(){
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> a(m);
	rep(i,m){
		cin >> a[i].second >> a[i].first;
		a[i].first--;
	}

	sort(all(a));

	int cur = 0, ans = 0;
	rep(i,m){
		if(cur >= a[i].second and cur <= a[i].first) continue; 
		ans++;
		cur = a[i].first;
	}
	cout << ans << endl;
}
