#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template <typename X, typename T>
auto vectors(X x, T a) {
	return vector<T>(x, a);
}

template <typename X, typename Y, typename Z, typename... Zs>
auto vectors(X x, Y y, Z z, Zs... zs) {
	auto cont = vectors(y, z, zs...);
	return vector<decltype(cont)>(x, cont);
}

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
	int h, w, q;
	cin >> h >> w >> q;

	vector<long long> a[2], b[2];
	rep(i,h){
		int x;
		cin >> x;
		a[i % 2].emplace_back(x);
		a[(i + 1) % 2].emplace_back(0);
	}
	rep(i,w){
		int x;
		cin >> x;
		b[i % 2].emplace_back(x);
		b[(i + 1) % 2].emplace_back(0);
	}

	cout << a[0] << endl;
	cout << a[1] << endl;
	cout << b[0] << endl;
	cout << b[1] << endl;

	CumulativeSum<long long> ca(a[0]), cb(a[1]), cc(b[0]), cd(b[1]);
	rep(i,q){
		int px, py, qx, qy;
		cin >> px >> py >> qx >> qy;
		px--; py--; qx--; qy--;
		show(ca.get(px, qx))
		show(cc.get(px, qx))
		cout << (ca.get(px, qx) - cc.get(px, qx)) * (cb.get(px, qx) - cd.get(px, qx)) << endl;
	}
}
