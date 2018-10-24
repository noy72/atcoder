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
	cin >> a;

	vector<long long> minus;
	rep(i,n){
		a[i] -= i + 1;
	}

	sort(all(a), greater<long long>());
	long long ans = 0;
	long long k = a[n / 2];
	rep(i,n){
		a[i] -= k;
		ans += abs(a[i]);
	}


	cout << ans << endl;
}
