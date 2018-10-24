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
	int n, k, q;
	cin >> n >> k >> q;

	vector<long long> a(n);
	cin >> a;

	vector<pair<long long,long long>> p(n);
	rep(i,n){
		p[i] = make_pair(a[i], i);
	}
	sort(all(p));

	long long ans = 1e9;
	range(len,k,n + 1){
		long long maxi = 0, mini = 1e9;
		rep(j,len){
			maxi = max(maxi, p[j].second);
			mini = min(mini, p[j].second);
		}

		if(maxi - mini + 1 == len) ans = abs(p[0].second - p[0 + len].second);

		range(j,1,n - len){
			if(maxi == p[j - 1].second) maxi = 0;
			if(mini == p[j - 1].second) mini = 1e9;
			maxi = max(maxi, p[j + len].second);
			mini = min(mini, p[j + len].second);
		if(maxi - mini + 1 == len) ans = abs(p[j].second - p[j + len].second);
		}
	}
	cout << ans << endl;
}
