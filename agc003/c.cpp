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

	vector<int> a(n), s;
	rep(i,n) cin >> a[i];
	s = a;
	sort(all(s));

	int cnt = 0;
	rep(i,n){
		if(distance(s.begin(), lower_bound(all(s), a[i])) % 2 != i % 2) cnt++;
	}
	cout << cnt / 2 << endl;
}
