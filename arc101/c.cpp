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
	int n, k;
	cin >> n >> k;

	vector<long long> l, r = {0};
	rep(i,n){
		long long a;
		cin >> a;
		if(a > 0) r.emplace_back(a);
		else l.emplace_back(-a);
	}
	l.emplace_back(0);
	reverse(all(l));

	long long ans = LLONG_MAX;
	rep(i,k + 1){
		int j = k - i;
		if(l.size() <= i or r.size() <= j) continue;

		long long llen = l[i];
		long long rlen = r[j];
		//cout << i << ' ' << j << endl;
		//cout << llen << ' ' << rlen << endl;
		ans = min({ans, llen * 2 + rlen, llen + rlen * 2});
	}
	cout << ans << endl;
}
