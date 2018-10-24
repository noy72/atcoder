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

bool check(vector<long long>& a, long long n){
	show( all_of(all(a), [n](const long long i){show(i);return i < n;}))
		return all_of(all(a), [n](const long long i){show(i);return i < n;});
}

int main(){
	int n;
	cin >> n;

	vector<long long> a(n);
	cin >> a;

	sort(all(a), greater<long long>());

	long long ans = 0;
	while(true){
		long long div;
		rep(i,n){
			div = a[i] / n;
			a[i]%=n;
			ans += div;
			rep(j,n){
				if(i == j) continue;
				a[j] += div;
			}
		}
		if(div < n and check(a, n)) break;
	}
	cout << ans << endl;
}
