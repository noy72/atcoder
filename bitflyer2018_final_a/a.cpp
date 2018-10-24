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

int f(int a){
	int cnt = 0;
	while(true){
		if(a % 10 != 0) break;
		a/=10;
		cnt++;
	}
	return cnt;
}

int main(){
	int n;
	cin >> n;

	vector<int> a(n);
	rep(i,n) cin >> a[i];

	int ans = INT_MAX;
	rep(i,n){
		ans = min(ans, f(a[i]));
	}
	cout << ans << endl;
}
