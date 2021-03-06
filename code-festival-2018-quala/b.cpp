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
	int n, m, a, b;
	cin >> n >> m >> a >> b;

	vector<int> v(n, b);
	rep(i,m){
		int l, r;
		cin >> l >> r;
		range(j,l - 1,r){
			v[j] = a;
		}
	}
	cout << accumulate(all(v), 0) << endl;
}
