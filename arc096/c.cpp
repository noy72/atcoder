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
	long long a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	
	c*=2;

	long long ans = max(x, y) * c;

	long long t = min(x, y);
	ans = min(ans, c * t + (x - t) * a + (y - t) * b);

	ans = min(ans, x * a + b * y);
	cout << ans << endl;
}
