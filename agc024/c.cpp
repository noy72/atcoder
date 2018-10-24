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
	int n;
	cin >> n;

	vector<long long> a(n);
	rep(i,n){
		cin >> a[i];
	}

	if(a[0] > 0){
		cout << -1 << endl;
		return 0;
	}

	rep(i,n - 1){
		if(a[i + 1] - a[i] > 1){
			cout << -1 << endl;
			return 0;
		}
	}

	long long ans = 0;
	vector<long long> s(n, 0);

	int i = n - 1;
	while(i >= 0){
		int t = a[i];
		ans += a[i];

		if(i == 0) break;

		while(a[i] == t){
			t--;
			i--;
		}
	}
	cout << ans << endl;
}
