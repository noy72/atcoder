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
	vector<int> a(3);
	cin >> a;

	sort(all(a));
	int x = a[2] - a[0];
	int y = a[2] - a[1];

	int ans = x / 2 + y / 2;
	int odd = x % 2 + y % 2;
	if(odd == 1) ans += 2;
	if(odd == 2) ans += 1;
	cout << ans << endl;
}
