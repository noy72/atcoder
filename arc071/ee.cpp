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

template<typename T>
class CumulativeSum {
	vector<T> a;
	public:
	CumulativeSum(vector<T>& x) : a(x.size() + 1,0) {
		rep(i,x.size()){
			a[i + 1] = a[i] + x[i];
		}
	}
	T get(int l, int r){ // [l, r]の区間の合計を求める
		return a[r + 1] - a[l];
	}
	T operator [] (const int i) const {
		return a[i];
	}
};

int main(){
	string s, t;
	int q;
	cin >> s >> t >> q;

	vector<int> a(s.size()), b(t.size());
	rep(i,s.size()) a[i] = s[i] == 'A' ? 1 : -1;
	rep(i,t.size()) b[i] = t[i] == 'A' ? 1 : -1;

	CumulativeSum<int> asum(a), bsum(b);

	rep(i,q){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		if( (asum.get(a,b) - bsum.get(c,d)) % 3 == 0 ) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
